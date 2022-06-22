#include <bits/stdc++.h>
using namespace std;
typedef long long int             lld;
#define test                      lld t; cin >>t; while(t--)
#define dbug                      cout <<"dukse" <<endl;

std::vector<string> keyword; //if, while, break etc.
std::vector<string> identifier; //variable name
std::vector<string> operators; // +, -, %, &. etc.
std::vector<string> literal; //string
std::vector<string> delimiter; // brackets, semicolon
std::vector<string> constant; // numbers

bool is_keyword(string token) {
    if (token == "if" or token == "else" or token == "break"
            or token == "continue" or token == "while" or token == "do"
            or token == "int" or token == "double" or token == "float"
            or token == "string" or token == "char" or token == "long"
            or token == "short" or token == "unsigned" or token == "switch"
            or token == "void" or token == "static" or token == "public"
            or token == "private" or token == "class" or token == "goto"
            or token == "struct" or token == "sizeof" or token == "case"
            or token == "static" or token == "true" or token == "false") {
        return true;
    }
    return false;
}

bool is_operator(string token) {
    if (token == "+" or token == "-" or token == "*" or token == "/"
            or token == "^" or token == "|" or token == "&" or token == "~"
            or token == "%" or token == "=" or token == ">" or token == "<") {
        return true;
    }
    return false;
}

bool is_delimiter(string token) {
    if (token == "," or token == ";" or token == "[" or token == "]"
            or token == "(" or token == ")" or token == "{" or token == "}") {
        return true;
    }
    return false;
}

void tokenize(std::vector<string> program) {

    //------------------keyword-------------------------

    for (int i = 0; i < program.size(); i++) {
        string tmp;
        for (int j = 0; j < program[i].size(); j++) {
            tmp += program[i][j];
            if (is_keyword(tmp)) {
                keyword.push_back(tmp);
                //delete founded keyword from the input

                lld idx = 0;
                for (int k = 0; k < program[i].size(); k++) {
                    if (tmp[idx++] == program[i][k]) {
                        program[i].erase(program[i].begin() + k);
                        k--;
                    }
                    if (idx == tmp.size())break;
                }
                j -= tmp.size();
                tmp.clear();

            }
        }
    }

    //------------------delimiter----------------------

    for (int i = 0; i < program.size(); i++) {
        string tmp;
        for (int j = 0; j < program[i].size(); j++) {
            tmp += program[i][j];
            if (is_delimiter(tmp)) {
                // delete founded delimiter from input
                program[i].erase(program[i].begin() + j);
                j--;
                delimiter.push_back(tmp);
            }
            tmp.clear();
        }
    }

    //----------------constant-------------------------

    for (int i = 0; i < program.size(); i++) {
        string tmp;
        for (int j = 0; j < program[i].size(); j++) {
            if (program[i][j] >= '0' and program[i][j] <= '9') {
                tmp += program[i][j];
                program[i].erase(program[i].begin() + j);
                j--;
            }
            else {
                if (tmp != " ")constant.push_back(tmp);
                tmp.clear();
            }
        }
        if (tmp.size() and tmp != " ")constant.push_back(tmp);
    }

    //----------------------operator------------------------

    for (int i = 0; i < program.size(); i++) {
        string tmp;
        for (int j = 0; j < program[i].size(); j++) {
            tmp += program[i][j];
            if (is_operator(tmp)) {
                program[i].erase(program[i].begin() + j);
                j--;
                operators.push_back(tmp);
            }
            tmp.clear();
        }
    }

    //----------------------literal------------------------

    for (int i = 0; i < program.size(); i++) {
        string tmp;
        char ch = '"';
        bool lock = false;
        for (int j = 0; j < program[i].size(); j++) {
            if (program[i][j] == ch) {
                if (lock) {
                    program[i].erase(program[i].begin() + j);
                    j--;
                    if (tmp.size()) {
                        literal.push_back(tmp);
                        tmp.clear();
                    }
                    lock = false;
                }
                else if (!lock) {
                    program[i].erase(program[i].begin() + j);
                    j--;
                    lock = true;
                }
            }
            else {
                if (lock) {
                    tmp += program[i][j];
                    program[i].erase(program[i].begin() + j);
                    j--;
                }
            }
        }
    }

    //---------------------identifier---------------------

    for (int i = 0; i < program.size(); i++) {
        identifier.push_back(program[i]);
    }

    //-----------------------------------------------
}

void display() {

    cout << "Keywords: ";
    for (int i = 0; i < keyword.size() - 1; i++) {
        cout << keyword[i] << " ";
    }
    cout << keyword.back() << endl;

    cout << "Operators: ";
    for (int i = 0; i < operators.size() - 1; i++) {
        cout << operators[i] << " ";
    }
    cout << operators.back() << endl;

    cout << "Delimiter: ";
    for (int i = 0; i < delimiter.size() - 1; i++) {
        cout << delimiter[i] << " ";
    }
    cout << delimiter.back() << endl;

    cout << "Identifier: ";
    for (int i = 0; i < identifier.size() - 1; i++) {
        cout << identifier[i] << " ";
    }
    cout << identifier.back() << endl;

    cout << "Literal: ";
    for (int i = 0; i < literal.size() - 1; i++) {
        cout << literal[i] << " ";
    }
    cout << literal.back() << endl;

    cout << "Constant: ";
    for (int i = 0; i < constant.size() - 1; i++) {
        cout << constant[i] << " ";
    }
    cout << constant.back() << endl;
}

int main() {
    std::vector<string> program;
    string str;
    while (getline(cin, str)) {
        program.push_back(str);
    }
    tokenize(program);
    display();
}