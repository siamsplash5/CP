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