#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
#define test lld t; cin >>t; while(t--)
#define dbug cout <<"dukse" <<endl;

lld n, k;
lld w[100005], v[100005];
lld dp[105][100005];

lld f(lld weight, lld idx) {
    if (idx == n or weight == 0)return 0;
    if (dp[idx][weight]) return dp[idx][weight];
    if (w[idx] > weight)return dp[idx][weight] =  f(weight, idx + 1);
    return dp[idx][weight] =  max(v[idx] + f(weight - w[idx], idx + 1), f(weight, idx + 1));
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }
    cout << f(k, 0) << endl;
    return 0;
}