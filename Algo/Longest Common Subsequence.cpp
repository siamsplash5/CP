#include <bits/stdc++.h>
using namespace std;

string lcs(string s1, string s2) {
    int n, m;
    n = s2.size();
    m = s1.size();
    int table[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)table[i][j] = 0;
            else if (s1[i - 1] == s2[j - 1])table[i][j] = table[i - 1][j - 1] + 1;
            else table[i][j] = max(table[i - 1][j], table[i][j - 1]);
        }
    }
    string lcs_string;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs_string += s1[i - 1];
            i--, j--;
        }
        else if (table[i - 1][j] > table[i][j - 1])i--;
        else j--;
    }
    reverse(lcs_string.begin(), lcs_string.end());
    return lcs_string;
}

void solve()
{
    string s1, s2;
    cin >> s1 >> s2;
    string s = lcs(s1, s2);
    cout << s.size() << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    clock_t tStart = clock();
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();

#ifndef ONLINE_JUDGE
    fprintf(stderr, "\n>> Runtime: %.10fs\n", (double) (clock() - tStart) / CLOCKS_PER_SEC);
#endif
    return 0;
}