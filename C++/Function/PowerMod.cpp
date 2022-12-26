lld power_mod(lld num, lld base, lld m) {
    lld res = 1;
    num = num % m;
    if (num == 0)
        return 0;
    while (base > 0) {
        if (base & 1)res = (res * num) % m;
        base = base >> 1;
        num = (num * num) % m;
    }
    return res;
}