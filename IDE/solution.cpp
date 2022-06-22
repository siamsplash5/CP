#include <bits/stdc++.h>
using namespace std;
#define MXS 10000005

long long int phi[MXS];
void phi_1_to_n(int n) {
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}

long long int sparse_table[22][MXS];

void sparse_table_generator(int n) {
    long long int len = log2(n);
    for (int i = 0; i < n; i++) {
        sparse_table[0][i] = phi[i + 1];
    }
    for (int k = 1; k <= len; k++) {
        for (int j = 0; j <= n - (1 << k); j++) {
            sparse_table[k][j] = max(sparse_table[k - 1][j], sparse_table[k - 1][j + (1 << k - 1)]);
        }
    }
}

int main() {
    phi_1_to_n(1000000);
    sparse_table_generator(1000000);
    long long int n, q;
    scanf("%lld %lld", &n, &q);
    while (q--) {
        long long int l, r;
        scanf("%lld %lld", &l, &r);
        l--; r--;
        long long int x = log2(r - l + 1);
        long long int ans = max(sparse_table[x][l], sparse_table[x][r - (1 << x) + 1]);
        printf("%lld\n", ans);
    }
    return 0;
}