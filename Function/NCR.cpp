lld ncr(lld n, lld m) {
    lld answer = 1;
    lld d = 1;
    for (lld i = n; i > max(n - m, m); i--) {
        answer *= i;
        if (answer % d == 0 and d <= min(n - m, m)) {
            answer /= d;
            d++;
        }
    }
    return answer;
}