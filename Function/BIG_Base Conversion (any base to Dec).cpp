string BIG_ADD(string s1, string s2)
{
    string s;
    int n = s1.size();
    int m = s2.size();

    if (n > m)
    {
        reverse(s2.begin(), s2.end());
        for (int i = 0; i < abs(n - m); i++)
            s2 += '0';
        reverse(s2.begin(), s2.end());
    }
    else if (n < m)
    {
        reverse(s1.begin(), s1.end());
        for (int i = 0; i < abs(n - m); i++)
            s1 += '0';
        reverse(s1.begin(), s1.end());
    }

    int sum, carry = 0;

    for (int i = s2.size() - 1; i >= 0; i--)
    {
        sum = s1[i] - '0' + s2[i] - '0' + carry;
        s += (sum % 10) + '0';
        carry = sum / 10;
    }

    while (carry)
    {
        s += carry + '0';
        carry /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

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

string convertedStrToDec(string num, string base)
{
    int len = num.size();
    int p = 0;
    string ans = "0";
    for (int i = len - 1; i >= 0; --i)
    {
        string pwr = power(base, p);
        string s;
        s += num[i];
        string mul = MULTIPLY(pwr, s);
        ans = BIG_ADD(ans, mul);
        p++;
    }
    return ans;
}
