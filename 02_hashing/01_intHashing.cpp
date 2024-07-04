#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arrSize = 14;
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 12, 10, 6, 4, 4, 3, 10};

    int hash[13] = {0};

    for(int i=0; i<arrSize; i++)
    {
        hash[arr[i]]++;
    }

    for(int i=0; i<13; i++)
    {
        cout << "Count of Value " << i << " is : " << hash[i] << endl;
    }
    return 0;
}