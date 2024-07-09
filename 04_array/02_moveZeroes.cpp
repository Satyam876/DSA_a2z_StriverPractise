#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void moveZeroes_bruteForce(int *nums, int numsSize)
{
    for(int i=0; i<numsSize; i++)
    {
        if(nums[i] == 0)
        {
            for(int j=i+1; j<numsSize; j++)
            {
                if(nums[j] != 0)
                {
                    swap(&nums[i], &nums[j]);
                    break;
                }
            }
        }
    }
}


int main()
{
    int arr[] = {0, 1, 0, 3, 12};
    int arrSize = 5;
    
    moveZeroes_bruteForce(arr, arrSize);

    cout << "Array After Moving Zeroes to End : ";
    for(int i=0; i<arrSize; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
    return 0;
}