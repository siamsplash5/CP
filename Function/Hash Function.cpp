long long int m;
long long int base;

void forward_hash(string s) {
    lld hash_value = 0;
    fhash.push_back(0);
    for (auto it : s) {
        hash_value = ((hash_value * base) % m + (it - 64) % m) % m;
        fhash.push_back(hash_value);
    }
}

void backward_hash(string s) {
    lld hash_value = 0;
    bhash.push_back(0);
    for (int i = s.size() - 1; i >= 0; i--) {
        hash_value = ((hash_value * base) % m + (s[i] - 64) % m) % m;
        bhash.push_back(hash_value);
    }
}