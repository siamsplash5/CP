#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
#define dbug cout <<"dukse" <<endl;
#define test int tt; scanf("%d", &tt); while(tt--)

int main() {
    lld tst = 1;
    test {
        lld n; cin >> n;
        lld sum = 0, a[n + 2], x;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> x;
            sum += (a[i] - x);
        }
        sum -= n;
        printf("Case %d: ", tst++);
        cout << ((sum & 1) ? "white wins" : "black wins") << endl;
    }
    return 0;
}