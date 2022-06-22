string MULTIPLY(string s1, string s2)
{
    int n = s2.size();
    int m = s1.size();

    string s;
    reverse(s1.begin(), s1.end());

    int carry = 0;

    int d = stoi(s2);
    for (int j = 0; j < m; j++)
    {
        int c = s1[j] - '0';
        int mul = c * d + carry;
        s += (mul % 10) + '0';
        carry = mul / 10;
    }

    while (carry)
    {
        s += (carry % 10) + '0';
        carry /= 10;
    }

    reverse(s.begin(), s.end());
    return s;
}

string power(string base, int p)
{
    string pwr = to_string(p);
    string answer = "1";

    for (int i = 0; i < p; ++i)
    {
        answer = MULTIPLY(answer, base);
    }
    return answer;
}