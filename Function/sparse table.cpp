//range minimum query in O(1)

int main() {
    lld n, q;
    scanf("%lld %lld", &n, &q);
    lld len = log2(n);
    lld sparse_table[len + 2][n + 5];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &sparse_table[0][i]);
    }
    for (int k = 1; k <= len; k++) {
        for (int j = 0; j <= n - (1 << k); j++) {
            sparse_table[k][j] = min(sparse_table[k - 1][j], sparse_table[k - 1][j + (1 << k - 1)]);
        }
    }
    lld l, r;
    printf("Case %lld:\n", t);
    while (q--) {
        scanf("%lld %lld", &l, &r);
        l--; r--;
        lld x = log2(r - l + 1);
        lld ans = min(sparse_table[x][l], sparse_table[x][r - (1 << x) + 1]);
        printf("%lld\n", ans);
    }
    return 0;
}