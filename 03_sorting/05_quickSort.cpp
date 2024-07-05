#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partitionIndexFunc(int *arr, int low, int high)                 // This part take O(N)
{
    int pivot = low;
    int i = low;
    int j = high;

    while( i < j)
    {
        while(arr[i] <= arr[pivot] && i <= high-1)
        {
            i++;
        }

        while(arr[j] > arr[pivot] && j >= low+1)
        {
            j--;
        }
        if(i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[pivot], &arr[j]);
    return j;
}

void quickSort(int *arr, int low, int high)                       // TIME COMPLEXITY -> O(N*logN)
{
    if(low < high)
    {
        int partition = partitionIndexFunc(arr, low, high);
        
        quickSort(arr, low, partition-1);                         // This takes O(logN) time complexity as it breaks down.
        quickSort(arr, partition+1, high);
    }
}


int main()
{
    int n;
    cout << "Enter Array Size : ";
    cin >> n;

    int *arr = (int *)malloc(n*sizeof(int));

    cout << "Enter Array Elements : ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);

    cout << "Array Sorted by Selection Sort : ";

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}