
void insertionSort(int ara[], int array_size)
{
    int x, j;
    for(int i=0; i<array_size; i++)
    {
        x = ara[i];
        j = i - 1;
        while(j>=0 && ara[j]>x)
        {
            ara[j+1] = ara[j];
            j--;
        }
        ara[j+1] = x;
    }
}


