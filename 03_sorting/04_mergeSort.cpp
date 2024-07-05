#include<bits/stdc++.h>
using namespace std;


void mergeFunc(int *arr, int low, int mid, int high)
{
    vector<int> v;

    int i = low;
    int j = mid+1;

    while(i <= mid && j <= high)
    {
        if(arr[i] <= arr[j])
        {
            v.push_back(arr[i]);
            i++;
        }
        else{
            v.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid)
        v.push_back(arr[i++]);
    while(j <= high)
        v.push_back(arr[j++]);

    // Copying the vector into original array

    for(int i=low; i<= high; i++)
    {
        arr[i] = v[i-low];
    }
}

void mergeSort(int *arr, int low, int high)                   // Time Complexity -> O(N*logN)
{
    if(low >= high)
        return;
    
    int mid = (low + high)/2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    mergeFunc(arr, low, mid, high);
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

    mergeSort(arr, 0, n-1);

    cout << "Array Sorted by Selection Sort : ";

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
