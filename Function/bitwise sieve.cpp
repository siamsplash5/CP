bool Check(lld N, lld pos) {return (bool)(N & (1 << pos));}
lld Set(lld N, lld pos) { return N = N | (1 << pos);}
std::vector<lld> prime;

lld status[(mxs / 32) + 2];
lld N = 10000003;
void sieve() {
    lld sqrtN = lld(sqrt(N));
    for (lld i = 3; i <= sqrtN; i += 2 ) {
        if ( Check(status[i >> 5], i & 31) == 0) {
            for (lld j = i * i; j <= N; j += (i << 1) ) {
                status[j >> 5] = Set(status[j >> 5], j & 31)   ;
            }
        }
    }
    prime.push_back(2);
    for (lld i = 3; i <= N; i += 2) {
        if ( Check(status[i >> 5], i & 31) == 0)
            prime.push_back(i);
    }
}