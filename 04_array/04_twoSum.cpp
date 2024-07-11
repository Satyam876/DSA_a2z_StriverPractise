#include<bits/stdc++.h>
using namespace std;

// BRUTE-FORCE APPROACH

vector<int> twoSum_bruteForce(int *arr,int arrSize, int target)      // TIME COMPLEXITY -> O(N^2)
{
    vector<int> v;
    for(int i=0; i<arrSize; i++)
    {
        for(int j=i+1; j<arrSize; j++)
        {
            if((arr[i] + arr[j]) == target)
            {
                v.push_back(arr[i]);
                v.push_back(arr[j]);
            }
        }
    }
    return v;
}


//* BETTER APPROACH -> Using HASHMAP

vector<int> twoSum_betterApproach(int *arr, int arrSize, int target)       // TIME COMPLEXITY -> O(N*log N)
{
    vector<int> v;
    map<int, int> hashMap;

    for(int i=0; i<arrSize; i++)
    {
        int rem = target - arr[i];

        if(hashMap.find(rem) != hashMap.end())
        {
            v.push_back(i);
            v.push_back(hashMap[rem]);
        }

        hashMap[arr[i]] = i;
    }
    return v;
}


// OPTIMAL APPROACH -> for some cases -> two pointer approach   // Not Preferable         

vector<int> twoSum_optimalApproach(int *arr, int arrSize, int target)        // TIME COMPLEXITY -> O(N) + O(N*log N) 
{
    vector<int> v;
    int i = 0;
    int j = arrSize-1;

    sort(arr, arr+arrSize);

    while(i < j)
    {
        int sum = arr[i] + arr[j];

        if(sum == target)
        {
            v.push_back(arr[i]);
            v.push_back(arr[j]);
        }

        else if(sum < target)
            i++;
        else if(sum > target)
            j--;
    }
    return v;
}


int main()
{
    int arr[] = {2, 7, 11, 15};
    int arrSize = 4;
    int target = 9;

    // vector<int> result = twoSum_bruteForce(arr, arrSize, target);

    vector<int> result = twoSum_betterApproach(arr, arrSize, target);

    // vector<int> result = twoSum_optimalApproach(arr, arrSize, target);

    cout << "Element that makes Two Sum of " << target << " is : ";
    for(auto it:result)
    {
        cout << it << " & ";
    }

    cout << endl;

    return 0;
}