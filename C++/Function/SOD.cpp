lld mark[1000005];
void simple_sieve(lld n) {
    for (int i = 1; i < n; i++) {
        for (int j = i + i; j <= n; j += i) {
            mark[j] += i;
        }
    }
}