string lcs(string s1, string s2) {
    int n, m;
    n = s2.size();
    m = s1.size();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)dp[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    //return dp[m][n] if need only size
    string lcs_string;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs_string += s1[i - 1];
            i--, j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])i--;
        else j--;
    }
    reverse(lcs_string.begin(), lcs_string.end());
    return lcs_string;
}
std::set<string> v;
void all_lcs(int i, int j, string s) {
    if (i <= 0 or j <= 0) {
        if (s.size() == x)v.insert(s);
        return;
    }
    if (s1[i - 1] == s2[j - 1]) {
        all_lcs(i - 1, j - 1, s + s1[i - 1]);
    }
    else {
        all_lcs(i - 1, j, s);
        all_lcs(i, j - 1, s);
    }
}

//recursive lcs

string s1, s2, ans;
int dp[3003][3003];

int lcs(int n, int m) {
    if (n < 0 or m < 0)return 0;
    if (dp[n][m])return dp[n][m];
    if (s1[n - 1] == s2[m - 1]) return dp[n][m] = lcs(n - 1, m - 1) + 1;
    else return dp[n][m] = max(lcs(n, m - 1), lcs(n - 1, m));
}

int main() {
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    lcs(n, m);
    string ans = "";
    while (n > 0 and m > 0) {
        if (s1[n - 1] == s2[m - 1]) {
            ans += s1[n - 1];
            n--;
            m--;
        }
        else if (dp[n - 1][m] > dp[n][m - 1])n--;
        else m--;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}