void sub_array(std::vector<lld> v) {
    lld n = v.size();
    lld f = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i <= n - k; i++) {
            for (int j = i; j < i + k; j++) {
                cout << v[j] << " ";
            }
            cout << endl;
        }
    }
}