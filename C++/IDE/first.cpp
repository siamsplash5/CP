#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
#define dbug cout <<"dukse" <<endl;
#define test int tt; scanf("%d", &tt); while(tt--)

int dp[17][17];
bool f(lld x, lld y) {
    if (x <= 1 and y <= 1)return 0;
    if (15 > x or y > 15) return 0;

    if (dp[x][y] != -1) return dp[x][y];
    return dp[x][y] = !(f(x - 2, y + 1) and f(x - 2, y - 1) and f(x + 1, y - 2) and f(x - 1, y - 2));
}

int main() {
    test{
        lld x, y; cin >> x >> y;
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                dp[i][j] = -1;
            }
        }
        if (f(x, y))cout << "First" << endl;
        else cout << "Second" << endl;
    }
    return 0;
}