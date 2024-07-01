#include<bits/stdc++.h>
using namespace std;

vector<int> divisors_bruteForce(int N)                           // Time Complexity -> O(N)
{
    vector<int> v;

    for(int i=1; i<=N; i++)
    {
        if(N%i == 0)
        {
            v.push_back(i);
        }
    }
    return v;
}


vector<int> divisors_optimalApproach(int N)                          // Time Complexity -> O(sqrt(N))
{
    vector<int> v;

    for(int i=1; i<=sqrt(N); i++)
    {
        if(N%i == 0)
        {
            v.push_back(i);

            if(i != N/i)
            {
                v.push_back(N/i);
            }
        }
    }
    sort(v.begin(), v.end());
    return v;
}

int main()
{
    int num;
    cout << "Enter the Number : ";
    cin>>num;

    // vector<int> divisors = divisors_bruteForce(num);

    vector<int> divisors = divisors_optimalApproach(num);

    cout << "Divisors of "<< num << " : ";
    for(auto it:divisors)
    {
        cout << it << " ";
    } 

    return 0;
}