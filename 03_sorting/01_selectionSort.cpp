#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int *arr, int arrSize)
{
    for(int i=0; i<arrSize; i++)
    {
        int min = i;
        for(int j=i; j<arrSize; j++)
        {
            if(arr[j] < arr[min])   
                min = j;
        }
        swap(&arr[i], &arr[min]);
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

    selectionSort(arr, n);

    cout << "Array Sorted by Selection Sort : ";

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}