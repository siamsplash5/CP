lld anyBaseToDecimal(string s, int base) {
	if (base == 10)return stoi(s);
	int n = s.size();
	lld res = 0;
	int digit;
	reverse(s.begin(), s.end());
	for (int i = 0; i < n; i++) {
		if (s[i] >= 'A' && s[i] <= 'F')digit = s[i] - 55;
		else digit = s[i] - '0';
		res += digit * pow(base, i);
	}
	return res;
}