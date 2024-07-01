#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int gcd_bruteForce(int N1,int N2){                 // Time Complexity -> O(min(N1, N2))
    int gcd = 1;

    for(int i=1; i<= min(N1, N2); i++)
    {
        if(N1%i == 0 && N2%i == 0)
            gcd = i;
    }
    return gcd;
}


int gcd_betterApproach(int N1, int N2)              // Time Complexity -> O(min(N1, N2))
{
    for(int i= min(N1, N2); i>0; i--)
    {
        if(N1%i == 0 && N2%i == 0)
            return i;
    }
    return 1;
}


int gcd_optimal(int N1, int N2)                     //   LCM -> gcd * (N1/gcd) * (N2/gcd)
{                                                   // Time Complexity -> O(min(N1, N2))
    if(N1 == 0 && N2 == 0)
        return 0;
    if(N1 == 0 )
        return N2;
    if(N2 == 0)
        return N1;

    if(N1 == min(N1, N2))
        return gcd_optimal(N1, N2-N1);
    else
        return gcd_optimal(N1-N2, N2);
}



int main()
{
    // cout << gcd_bruteForce(9, 12) << endl;

    // cout << gcd_betterApproach(9, 12) << endl;

    cout << gcd_optimal(9, 12) << endl;
}