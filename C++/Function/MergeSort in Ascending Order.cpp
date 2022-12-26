#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
lld ara[2000005];
void merge(lld low, lld high, lld mid) {
    lld temp[high - low + 1];
    lld i = low;
    lld k = 0;
    lld j = mid + 1;
    while (i <= mid && j <= high) {
        if (ara[i] < ara[j]) {
            temp[k] = ara[i];
            k++; i++;
        }
        else {
            temp[k] = ara[j];
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
    lld mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(low , mid);
        mergeSort(mid + 1 , high);
        merge(low, high, mid);
    }
}
