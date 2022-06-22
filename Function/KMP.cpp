lld dp[mxs];
void prefixFun(char s[]) {
    lld len = strlen(s);
    for (int i = 1; i < len; i++) {
        lld j = dp[i - 1];
        while (j > 0 and s[i] != s[j]) {
            j = dp[j - 1];
        }
        if (s[i] == s[j])j++;
        dp[i] = j;
    }
}

void kmp(char pattern[], char text[]) {
    lld n = strlen(text);
    lld m = strlen(pattern);
    int i = 0, j = 0;
    bool found = false;
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
        }
        else {
            if (j != 0)j = dp[j - 1];
            else i++;
        }
        if (j == m) {
            found = true;
            printf("%lld\n", i - m);
            i = i - m + 1;
            j = 0;
        }
    }
    if (!found)printf("\n");
}