// Find  Majority  Element  which  occurs  more  than  N/2  times.

#include<bits/stdc++.h>
using namespace std;

// BRUTE-FORCE APPROACH  

int majorityElement_bruteForce(vector<int>&v)             // Time Complexity  ->  O(N^2)
{
    for(int i=0; i<v.size(); i++)
    {
        int count = 0;
        for(int j=i; j<v.size(); j++)
        {
            if(v[j] == v[i])
                count++;
        }
        if(count > v.size()/2)
            return v[i];
    }
    return -1;
}


// BETTER APPROACH ->  HASHMAP

int majorityElement_betterApproach(vector<int>&v)          // Time Complexity  -> O(N*log N)  + O(N)
{
    map<int, int>mpp;

    for(int i=0; i<v.size(); i++)
    {
        mpp[v[i]]++;
    }

    for(auto it:mpp)
    {
        if(it.second > v.size()/2)
            return it.first;
    }
    return -1;
}



// OPTIMAL APPROACH  ->  MOORE'S VOTING ALGORITHM

int majorityElement_optimalApproach(vector<int>&v)        // Time Complexity  -> O(N)
{
    int count = 0;
    int element = -1;
    int verifyCount = 0;

    for(int i=0; i<v.size(); i++)
    {
        if(count == 0)
        {
            element = v[i];
            count = 1;
        }
        else if(v[i] == element)
            count++;
        else
            count--;
    }
    
    for(int i=0; i<v.size(); i++)             // This is to Verify the count of final elemnet is greater than n/2 or not.
    {
        if(v[i] == element)
            verifyCount++;
    }

    if(verifyCount > v.size()/2)
        return element;
    
    return -1;
}



int main()
{
    vector<int>v = {7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5};
    int arrSize = 16;

    // int majElement = majorityElement_bruteForce(v);

    // int majElement = majorityElement_betterApproach(v);

    int majElement = majorityElement_optimalApproach(v);

    cout << "Majority Element greater than " << v.size()/2 << " times is : " << majElement << endl;

    return 0;
}