vector <lld> prime;
bool mark[10005];
void simple_sieve(lld n) {
    for (int i = 2; i < n; i++) {
        if (mark[i])continue;
        for (int j = i + i; j <= n; j += i) {
            mark[j] = true;
        }
        prime.push_back(i);
    }
}