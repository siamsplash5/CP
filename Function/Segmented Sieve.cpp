vector <lld> primeNumbers;

void simpleSieve(lld limit, vector<lld>& prime)
{
    bool mark[limit + 1];
    memset(mark, false, sizeof(mark));

    for (lld i = 2; i <= limit; ++i)
    {
        if (mark[i] == false)
        {
            prime.push_back(i);
            for (lld j = i; j <= limit; j += i)
                mark[j] = true;
        }
    }
}

void primesInRange(lld low, lld high)
{
    lld limit = floor(sqrt(high)) + 1;
    vector<lld> prime;
    simpleSieve(limit, prime);

    if(low==1)
    {
        low++;
    }

    lld n = high - low + 1;

    bool mark[n + 1];
    memset(mark, false, sizeof(mark));

    for (lld i = 0; i < prime.size(); i++)
    {
        lld loLim = floor(low / prime[i]) * prime[i];
        if (loLim < low)
            loLim += prime[i];
        if(loLim==prime[i])
            loLim += prime[i];

        for (lld j = loLim; j <= high; j += prime[i])
            if(j != prime[i])
                mark[j - low] = true;
    }

    for (lld i = low; i <= high; i++)
        if (!mark[i - low])
            primeNumbers.push_back(i);
}

void callSieve(ull n)
{
    int range = n/1000000;
    lld high = 1000000, low = 2;
    for(i=0; i<range; i++)
    {
        primesInRange(low, high);
        low = high+1;
        high +=1000000;
    }
}

