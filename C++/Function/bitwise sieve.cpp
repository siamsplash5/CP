#define mxl 100000003

bool check(lld N, lld pos) {return (bool)(N & (1 << pos));}
lld setbit(lld N, lld pos) { return N = N | (1 << pos);}
lld pre[mxl]len = 1;
lld mark[(mxl / 32) + 2];

void bitwise_sieve() {
    lld sqrtN = sqrt(mxl - 3);
    prime[0] = pre[0] = 2;
    for (lld i = 3; i <= sqrtN; i += 2 ) {
        if ( check(mark[i >> 5], i & 31) == 0) {
            for (lld j = i * i; j <= mxl - 3; j += (i << 1) ) {
                mark[j >> 5] = setbit(mark[j >> 5], j & 31);
            }
        }
    }
    for (lld i = 3; i <= mxl - 3; i += 2) {
        if (check(mark[i >> 5], i & 31) == 0) {
            prime[len++] = i;
        }
    }
}