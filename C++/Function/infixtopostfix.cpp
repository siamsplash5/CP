int pre(char ch) {
    if (ch == '+' or ch == '-')return 1;
    if (ch == '*' or ch == '/')return 2;
    return -1;
}

string infix_to_postfix(string str) {
    string res;
    stack <char> s;
    for (auto it : str) {
        if (it >= '0' and it <= '9')res += it;
        else if (it == '*' or it == '/' or it == '+' or it == '-') {
            while (!s.empty() and pre(it) <= pre(s.top())) {
                res += s.top();
                s.pop();
            }
            s.push(it);
        }
        else if (it == ')') {
            while (s.top() != '(') {
                res += s.top();
                s.pop();
            }
            s.pop();
        }
        else s.push(it);
    }
    while (!s.empty()) {
        res += s.top();
        s.pop();
    }
    return res;
}