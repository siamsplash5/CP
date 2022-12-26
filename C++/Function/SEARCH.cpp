class SEARCH
{
public:
    lld BS(std::vector<lld> v, int low, int high, int key) {
        while (low <= high) {
            lld mid = (high + low) / 2;
            if (v[mid] == key)return mid;
            else if (v[mid] < key)low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
    lld UB(lld ara[], lld low, lld high, lld key) {
        lld mid;
        while (low < high) {
            mid = (low + high) / 2;
            if (ara[mid] <= key)low = mid + 1;
            else high = mid;
        }
        return high;
    }
    lld LB(lld ara[], lld low, lld high, lld key) {
        lld mid;
        while (low < high) {
            mid = (low + high) / 2;
            if (ara[mid] >= key)high = mid;
            else low = mid + 1;
        }
        return low;
    }
};