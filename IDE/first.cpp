#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
#define test lld t; cin >>t; while(t--)
#define dbug cout <<"dukse" <<endl;
#define eps 1e-18

void display(lld a[], lld n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    test{
        lld n; cin >> n;
        lld a[n + 2];
        lld mx_minus = INT_MIN;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] < 0)mx_minus = max(mx_minus, abs(a[i]));
        }
        lld op = 0;
        if (mx_minus != INT_MIN) {
            op += mx_minus;
            for (int i = 0; i < n; i++) {
                a[i] = a[i] + mx_minus;
            }
        }
        lld mini_plus = INT_MAX;
        display(a, n);
        for (int i = 0; i < n; i++) {
            if (a[i])mini_plus = min(a[i], mini_plus);
            else {
                mini_plus = INT_MAX;
                break;
            }
        }
        if (mini_plus != INT_MAX) {
            op += mini_plus;
            for (int i = 0; i < n; i++) {
                if (a[i])a[i] -= mini_plus;
            }
        }
        display(a, n);
        lld mx = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0)break;
            if (a[i] >= a[i + 1]) {
                mx = a[i];
            }
        }
    }
    return 0;
}