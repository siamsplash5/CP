double euler_totient_function(lld n) {
    prime_factor(n); //generate prime factorization of n
    double ans = 1.00;
    for (int i = 0; i < primefactor.size(); i++) {
        ans *= double(1.00 - (1 / (primefactor[i] * 1.00)));
    }
    return ans * n;
}
