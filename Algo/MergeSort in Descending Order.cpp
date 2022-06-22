#include <bits/stdc++.h>
using namespace std;

lld i, j; //loop variable

void merge(int ara[], int low, int high, int mid)
{
    int k, temp[high-low+1];
    i = low;
    k = 0;
    j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (ara[i] > ara[j])
        {
            temp[k] = ara[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = ara[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k] = ara[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        temp[k] = ara[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++)
    {
        ara[i] = temp[i-low];
    }
}

void mergeSort(int ara[], int low, int high)
{
    int mid;
    if (low>=high)
    {
        return;
    }
    mid=(low+high)/2;

    mergeSort(ara, low, mid);
    mergeSort(ara, mid+1, high);

    merge(ara, low, high, mid);
}
