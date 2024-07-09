#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void rotate_bruteForce(int *arr, int arrSize, int k)    //* Time Complexity -> O(k + n-k + k) => O(n+k)         
{                                                       //* Space Complexity -> O(k)
    k = k%arrSize;
    int temp[k+1];

    for(int i=0; i<=k; i++)             // This takes O(k)
    {
        temp[i] = arr[i];
    }

    for(int i=k+1; i<arrSize; i++)     // This takes O(n-k)
    {
        arr[i-k-1] = arr[i];
    }

    for(int i=k; i<arrSize; i++)       // This takes O(k)
    {
        arr[i] = temp[i-k];
    }
}

// OPTIMAL APPROACH  -> By Reversing the Array

void reverseArray(int *arr, int low, int high)
{
    if(low >= high)
        return;
    
    swap(&arr[low], &arr[high]);
    reverseArray(arr, low+1, high-1);
}

void rotate_optimalApproach(int *arr, int arrSize, int k)      //* TIME COMPLEXITY -> O(n)      : O(n + k + n-k) => O(2n) => O(n)
{                                                              //* SPACE COMPLEXITY -> O(1)
    k = k%arrSize;

    reverseArray(arr, 0, arrSize-1);             // O(n)
    reverseArray(arr, 0, k-1);                   // O(k)
    reverseArray(arr, k, arrSize-1);             // O(n-k)
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arrSize = 7;
    int k = 3;

    // rotate_bruteForce(arr, arrSize, k);

    rotate_optimalApproach(arr, arrSize, k);

    cout << "Array After " << k << " Rotation : ";
    for(int i=0; i<arrSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    return 0;
}