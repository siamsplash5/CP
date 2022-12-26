//lps in a string

int lps(string X, int i, int j) {
    if (i > j) return 0;
    if (i == j) return 1;
    if (X[i] == X[j]) return lps(X, i + 1, j - 1) + 2;
    return max(lps(X, i, j - 1), lps(X, i + 1, j));
}