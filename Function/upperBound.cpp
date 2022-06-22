lld upperBound(lld ara[], lld low, lld high, lld key) {
	lld mid;
	while (low < high) {
		mid = (low + high) / 2;
		if (ara[mid] <= key)
			low = mid + 1;
		else
			high = mid;
	}
	return high;
}