void inverse_function() {
    inv[1] = 1;
    for (int i = 2; i < mxs; i++) {
        inv[i] = m - (m / i) * inv[m % i] % m;
    }
}