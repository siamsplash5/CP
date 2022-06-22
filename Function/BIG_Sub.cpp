string sub(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();
    string s;
    if (n < m)swap(s1, s2);
    else if (n == m && s1 < s2)swap(s1, s2);
    if (s1 == s2)return "0";
    if (n > m) for (int i = 0; i < abs(n - m); i++)s2 = '0' + s2;
    for (int i = n - 1; i >= 0; i--) {
        if (s1[i] >= s2[i])s += s1[i] - s2[i] + '0';
        else {
            s += (s1[i] - '0' + 10 - (s2[i] - '0') + '0');
            s2[i - 1] = (s2[i - 1] - '0' + 1) + '0';
        }
    }
    while (s.back() == '0') {
        s.pop_back();
    }
    reverse(s.begin(), s.end());
    return s;
}