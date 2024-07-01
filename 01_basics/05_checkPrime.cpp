#include<bits/stdc++.h>
using namespace std;

bool checkPrime_BruteForce(int N)                            // Time Complexity -> O(N)
{
    int count = 1;

    for(int i=2; i<=N; i++)
    {
        if(N%i == 0)
            count++;
    }
    if(count == 2)
        return true;
    else
        return false;
}

bool checkPrime_Optimal(int N)                               // Time Complexity -> O(sqrt(N))
{
    int count = 0;

    for(int i=1; i<=sqrt(N); i++)
    {
        if(N%i == 0)
        {
            count++;

            if(i != N/i)
            {
                count++;
            }
        }
    }

    if(count == 2)
        return true;
    else
        return false;
}

int main()
{
    int num;
    cout<< "Enter the Number : ";
    cin>>num;

    // bool result = checkPrime_BruteForce(num);
    bool result = checkPrime_Optimal(num);

    if(result == true)
        cout << num << " is a Prime Number." << endl;
    else
        cout << num << " is not a Prime Number." << endl;
    
    return 0;
}