lld lowerBound(lld ara[], lld low, lld high, lld key) {
    lld mid;
    while (low < high) {
        mid = (low + high) / 2;
        if (ara[mid] >= key)
            high = mid;
        else
            low = mid + 1;
    }
    return low;
}