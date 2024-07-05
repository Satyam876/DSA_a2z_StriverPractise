#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int *arr, int arrSize)
{
    int hasSwapped = 0;

    for(int i=1; i<arrSize; i++)
    {
        for(int j=i; j>0; j--)
        {
            if(arr[j-1] > arr[j])                          // IF SWAPPED -> WORST/AVG CASE -> O(N^2)
            {
                swap(&arr[j-1], &arr[j]);
                hasSwapped = 1;
            }
        }
        if(hasSwapped == 0)                               // NO SWAP -> ALREADY SORTED -> BEST CASE -> O(N)
            break;                                        
    }
}

int main(){
    int n;
    cout << "Enter Array Size : ";
    cin >> n;

    int *arr = (int *)malloc(n*sizeof(int));

    cout << "Enter Array Elements : ";
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    insertionSort(arr, n);

    cout << "Array Sorted by Bubble Sort : ";

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}