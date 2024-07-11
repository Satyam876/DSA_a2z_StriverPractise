#include<bits/stdc++.h>
using namespace std;

// BRUTE - FORCE APPROACH OR BETTER APPROACH -> Traversing the Array using 2 loops

int maxSubarraySum_bruteForce(int *arr, int arrSize)           // Time Complexity -> O(N^2)
{
    int maxSum = INT_MIN;
    for(int i=0; i<arrSize; i++)
    {
        int sum = 0;
        for(int j=i; j<arrSize; j++)
        {
            sum += arr[j];
            
            if(sum > maxSum)
                maxSum = sum;
        }
    }
    return maxSum;
}


// OPTIMAL APPROACH  ->  KADANE'S ALGORITHM

int maxSubarraySum_optimalApproach(int *arr, int arrSize)      // Time Complexity -> O(N)
{
    int maxSum = INT_MIN;
    int sum = 0;
    int start = -1;
    int subStart = -1;
    int subEnd = -1;

    for(int i=0; i<arrSize; i++)
    {
        if(sum == 0)
            start = i;

        sum += arr[i];

        if(sum > maxSum)
        {
            maxSum = sum;
            subStart = start;
            subEnd = i;
        }

        if(sum < 0)
            sum = 0;
    }

    // FOR PRINTING MAXIMUM SUM SUBARRAY
    
    cout<< "MAXIMUM SUM SUBARRAY : ";
    for(int i=subStart; i<=subEnd; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;

    return maxSum;
}


int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int arrSize = 8;

    // int maxSubarraySum = maxSubarraySum_bruteForce(arr, arrSize);

    int maxSubarraySum = maxSubarraySum_optimalApproach(arr, arrSize);

    cout << "Maximum Subarray Sum : "<< maxSubarraySum << endl;

    return 0;
}