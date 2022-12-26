void inverse_factorial() {
    inv[1] = 1;
    inv_facto[0] = 1;
    inv_facto[1] = 1;
    for (int i = 2; i < mxs; i++) {
        inv[i] = m - (m / i) * inv[m % i] % m;
        //inv_facto[i] = (inv_facto[i - 1] % m * inv[i] % m) % m;
    }
}