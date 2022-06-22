lld binarySearch(std::vector<lld> v, int low, int high, int key) {
    while (low <= high) {
        lld mid = (high + low) / 2;
        if (v[mid] == key)return mid;
        else if (v[mid] < key)low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}