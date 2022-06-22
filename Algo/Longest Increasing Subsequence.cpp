#include <bits/stdc++.h>
using namespace std;

int lis( vector <int> arr, int n) {
    int T[n];
    T[0] = 1;
    for (int i = 1; i < n; i++ ) {
        T[i] = 1;
        for (int j = 0; j < i; j++ ) {
            if ( arr[i] > arr[j] && T[i] < T[j] + 1) {
                T[i] = T[j] + 1;
            }
        }
    }
    return *max_element(T, T + n);
}

int main() {
    vector <int> arr{1, 2, 3, 4, 5, 4, 3, 2, 1, 10};
    int n = arr.size();
    printf("Length of lis is %d\n", lis( arr, n ) );
    return 0;
}
