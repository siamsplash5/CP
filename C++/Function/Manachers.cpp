//returns the length longest palindrome substring length in O(N)

void manachar(string s) {
    string str;
    str += '#';
    for (int i = 0; i < s.size(); i++) {
        str += s[i];
        str += '#';
    }
    str += '#';
    lld dp[str.size()] = {0};
    lld center = 0, R = 0, mirror, mx = 0;
    for (int i = 1; i < str.size() - 1; i++) {
        mirror = 2 * center - i;
        if (i < R)dp[i] = min(dp[mirror], R - i);
        while (str[i + dp[i] + 1] == str[i - dp[i] - 1]) {
            dp[i]++;
        }
        if (i + dp[i] > R) {
            center = i;
            R = i + dp[i];
        }
        mx = max(mx, dp[i]);
    }
    cout << mx << endl;
}