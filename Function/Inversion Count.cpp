#include <bits/stdc++.h>
using namespace std;
typedef long long int             lld;
#define test                      lld t; cin >>t; while(t--)
#define dbug                      cout <<"dukse" <<endl;


/*

Inversion Count for an array indicates – how far (or close) the
array is from being sorted. If the array is already sorted, then
the inversion count is 0, but if the array is sorted in the reverse
order, the inversion count is the maximum.
Formally speaking, two elements a[i] and a[j] form an inversion
if a[i] > a[j] and i < j

*/

lld c = 0;
lld ara[200015];
void merge(lld low, lld high, lld mid) {
    lld temp[high - low + 1];
    lld i = low, k = 0, j = mid + 1;
    while (i <= mid && j <= high) {
        if (ara[i] < ara[j]) {
            temp[k] = ara[i];
            k++; i++;
        }
        else {
            temp[k] = ara[j];
            c += (mid - i + 1);
            k++; j++;
        }
    }
    while (i <= mid) {
        temp[k] = ara[i];
        k++; i++;
    }
    while (j <= high) {
        temp[k] = ara[j];
        k++; j++;
    }
    for (i = low; i <= high; i++) {
        ara[i] = temp[i - low];
    }
}

void mergeSort(lld low, lld high) {
    if (low < high) {
        lld mid = (low + high) / 2;
        mergeSort(low , mid);
        mergeSort(mid + 1 , high);
        merge(low, high, mid);
    }
}

int main() {
    test{
        lld n; cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> ara[i];
        }
        mergeSort(0, n);
        cout << c << endl;
        c = 0;
    }
}