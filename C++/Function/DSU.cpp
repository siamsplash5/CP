#define ms 1000007
lld par[ms], size[ms];
void make_set(lld n) {
    for (int i = 0; i < n; i++) {
        par[i] = i;
        size[i] = 1;
    }
}
lld find_set(lld n) {
    if (par[n] == n) return n;
    return par[n] = find_set(par[n]);
}
void union_set(lld u, lld v) {
    lld r1 = find_set(u);
    lld r2 = find_set(v);
    if (r1 != r2) {
        if (size[r1] < size[r2])swap(r1, r2);
        par[r2] = r1;
        size[r1] += size[r2];
        size[r2] = 1;
    }
}