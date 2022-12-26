// pattern count

lld prefix_function(string pattern, lld presize) {
    //pattern = actual pattern + # + text
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
        counter += (presize == pre[i]);
    }
    return counter;
}
/*

for printing the position: pos = i-actualpatternsize+1;

*/