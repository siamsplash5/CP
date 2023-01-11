/*

KMP function will return the number of pattern found in
the text string.

for function call, use: KMP(modified_string, pattern_length);
where modified string = pattern+"#"+text;
& pattern_length = pattern.size();

for printing the position: pos = i-pattern_lenght+1;

*/

lld KMP(string pattern, lld plen) {
    lld n = pattern.size();
    lld pre[n + 2] = {0};
    lld i = 0, j = 1;
    while (j < n) {
        if (pattern[i] == pattern[j]) {
            pre[j] = i + 1;
            i++; j++;
        }
        else {
            if (i == 0)pre[j++] = 0;
            else i = pre[i - 1];
        }
    }
    lld counter = 0;
    for (int i = 0; i < n; i++) {
        counter += (plen == pre[i]);
    }
    return counter;
}