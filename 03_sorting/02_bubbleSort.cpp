#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int arrSize)                // WORST / AVG CASE -> O(N^2)
{                                                     // BEST CASE -> O(N)
    int hasSwapped = 0;

    for(int i=0; i<arrSize-1; i++)
    {
        for(int j=0; j<arrSize-i-1; j++)
        {
            if(arr[j+1] < arr[j])
            {
                swap(&arr[j], &arr[j+1]);
                hasSwapped = 1;
            }
        }
        if(hasSwapped == 0)                           // Best Case -> Sorted Array -> If only one swapped has been happened then hasSwapped = 1
            break;                                   //  If no swapped means in 1 inner loop no swap has been performed i.e already sorted
    
    cout << "pass" << endl;
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

    bubbleSort(arr, n);

    cout << "Array Sorted by Bubble Sort : ";

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

