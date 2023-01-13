/*
Returns the maximum rectangle area on histogram.
Note: array have to 1-index based.
*/

lld histogram(lld a[], lld n) {
    a[0] = a[n + 1] = '-1';
    stack<lld> s; s.push(0);
    for (int i = 1; i <= n; i++) {
        dp[i] = dp2[i] = 1;
        while (a[s.top()] >= a[i]) {
            dp[i] += dp[s.top()];
            s.pop();
        }
        s.push(i);
    }
    stack <lld> s2;
    s2.push(n + 1);
    for (int i = n; i >= 1; i--) {
        while (a[s2.top()] >= a[i]) {
            dp2[i] += dp2[s2.top()];
            s2.pop();
        }
        s2.push(i);
    }
    lld mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, (dp[i] + dp2[i] - 1) * a[i]);
    }
    return mx;
}