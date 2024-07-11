#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition_function(int *arr, int low, int high)
{
    int pivot = low;
    int i = low;
    int j = high;

    while(i < j)
    {
        while(arr[i] <= arr[pivot] && i<=high-1)
            i++;
        while(arr[j] > arr[pivot] && j>=low+1)
            j--;
        if(i < j)
            swap(&arr[i], &arr[j]);
    }
    swap(&arr[pivot], &arr[j]);
    return j;
}

void quicksort(int *arr, int low, int high)
{
    if(low < high)
    {
        int partition = partition_function(arr, low, high);
        quicksort(arr, low, partition-1);
        quicksort(arr, partition+1, high);
    }
}

// BRUTE-FORCE  -> USE ANY SORTING ALGO -> QUICK SORT 

void sort012_bruteForce(int *arr, int arrSize)                    // Time Complexity -> O(N*log N)
{
    quicksort(arr, 0, arrSize-1);
}



// BETTER APPROACH -> Count each 0,1,2 and then manually enter

void sort012_betterApproach(int *arr, int arrSize)               // Time Complexity -> O(2N) = O(N)
{
    int count_zero = 0;
    int count_one = 0;
    int count_two = 0;

    for(int i=0; i<arrSize; i++)
    {
        if(arr[i] == 0)
            count_zero++;
        else if(arr[i] == 1)
            count_one++;
        else if(arr[i] == 2)
            count_two++;
    }

    for(int i=0; i<count_zero; i++)
    {
        arr[i] = 0;
    }
    for(int i=count_zero; i < (count_zero + count_one); i++)
    {
        arr[i] = 1;
    }
    for(int i=(count_zero + count_one); i <(count_zero+count_one+count_two); i++)
    {
        arr[i] = 2;
    }
}


// OPTIMAL APPROACH -> DUTCH NATIONAL FLAG ALGORITHM

void sort012_optimalApproach(int *arr, int arrSize)            // Time Complexity -> O(N)
{
    int low = 0;
    int mid = 0;
    int high = arrSize-1;

    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(&arr[mid], &arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid] == 1)
            mid++;
        else{
            swap(&arr[mid], &arr[high]);
            high--;
        }
    }
}


int main()
{
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0};
    int arrSize = 11;

    // sort012_bruteForce(arr, arrSize);

    // sort012_betterApproach(arr, arrSize);

    sort012_optimalApproach(arr, arrSize);

    cout << "Sorted Array : ";
    for(int i=0; i<arrSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}