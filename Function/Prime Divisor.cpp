void factorize(lld n) {
    for (int i = 0; i < prime.size() && prime[i] <= n; i++) {
        lld freq = 0;
        while (n % prime[i] == 0) {
            n /= prime[i];
            freq++;
        }
        if (freq)
            bprime.push_back(make_pair(prime[i], freq));
    }
}