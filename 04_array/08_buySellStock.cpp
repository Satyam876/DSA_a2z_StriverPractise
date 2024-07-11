// BEST TIME TO BUY AND SELL STOCK -> MAXIMUM PROFIT

#include<bits/stdc++.h>
using namespace std;

// BRUTE - FORCE APPROACH

int maxProfit_bruteForce(int *arr, int arrSize)            // Time Complexity -> O(N^2)
{
    int maxProfit = 0;

    for(int i=0; i<arrSize; i++)
    {
        int diff = 0;
        for(int j=i+1; j<arrSize; j++)
        {
            diff = arr[j] - arr[i];
            if(diff > maxProfit)
                maxProfit = diff;
        }
    }
    return maxProfit;
}


// OPTIMAL SOLUTION

int maxProfit_optimalApproach(int *arr, int arrSize)
{
    int maxProfit = 0;
    int mini = arr[0];

    for(int i=1; i<arrSize; i++)
    {
        maxProfit = max(maxProfit, (arr[i]-mini));
        mini = min(mini, arr[i]);
    }
    return maxProfit;
}

int main()
{
    int arr[] = {7, 1, 5, 3, 6, 4};
    int arrSize = 6;

    // int profit = maxProfit_bruteForce(arr, arrSize);

    int profit = maxProfit_optimalApproach(arr, arrSize);

    cout << "Maximum Profit by Stocks : "<< profit << endl;

    return 0;
}