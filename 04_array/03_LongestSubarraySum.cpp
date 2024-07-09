#include<bits/stdc++.h>
using namespace std;

// BRUTE - FORCE APPROACH 

int longestSubarraySum_bruteForce(int *arr, int arrSize, int k)          // TIME COMPLEXITY -> O(N^2)
{
    int maxLen = 0;

    for(int i=0; i<arrSize; i++)
    {
        int sum = 0;
        for(int j=i; j<arrSize; j++)
        {
            sum += arr[i];
            if(sum == k)
            {
                int len = j-i+1;
                if(len > maxLen)
                    maxLen = len;
            }
        }
    }
    return maxLen;
}


//* BETTER APPROACH -> USING HASHMAP                  

int longestSubarraySum_betterApproach(int *arr, int arrSize, int k)      // TIME COMPLEXITY -> O(N*log N)
{
    map<int, int> hashMap;
    int prefixSum = 0;
    int maxLen = 0;

    for(int i=0; i<arrSize; i++)
    {
        prefixSum += arr[i];

        if(prefixSum == k)
        {
            maxLen = max(maxLen, i+1);
        }

        int rem = prefixSum - k;

        if(hashMap.find(rem) != hashMap.end())
        {
            int len = i - hashMap[rem];
            maxLen = max(maxLen, len);
        }

        if(hashMap.find(prefixSum) == hashMap.end())
        {
            hashMap[prefixSum] = i;
        }
    }
    return maxLen;
}


//* OPTIMAL APPROACH -> ** ONLY FOR POSITIVE ELEMENT ARRAY ** 

int longestSubarraySum_OptimalApproach(int *arr, int arrSize, int k)          // TIME COMPLEXITY -> O(N + N) = O(2N) = O(N)
{
    int sum = arr[0];
    int maxLen = 0;

    int i=0, j=0;

    while(i < arrSize)
    {
        while(sum > k && j <= i)
        {
            sum = sum - arr[j];
            j++;
        }

        if(sum == k)
        {
            int len = i-j+1;
            maxLen = max(maxLen, len);
        }

        i++;
        if(i < arrSize)
            sum += arr[i];
    }
    return maxLen;
}


int main()
{
    int arr[] = {1, 2, 3, 1, 1, 1, 1, 3, 3};
    int arrSize = 9;
    int k = 6;
    
    // int maxLengthSubarray = longestSubarraySum_bruteForce(arr, arrSize, k); 

    // int maxLengthSubarray = longestSubarraySum_betterApproach(arr, arrSize, k);

    int maxLengthSubarray = longestSubarraySum_OptimalApproach(arr, arrSize, k);

    cout << "Longest Subaaray Sum Length : "<< maxLengthSubarray << endl;

    return 0;
}