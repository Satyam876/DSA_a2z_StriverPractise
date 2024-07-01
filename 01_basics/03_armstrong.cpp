#include<bits/stdc++.h>
#include<math.h>
using namespace std;

bool checkArmstrong(int N)
{
    int org = N;
    int sum = 0;

    while(N)
    {
        int rem = N%10;
        sum += rem*rem*rem;
        N = N/10;
    }

    if(sum == org)
        return true;
    else
        return false;
}


int main()
{
    int num;
    cout << "Enter the Number : ";
    cin>>num;

    bool result = checkArmstrong(num);

    if(result == true)
        cout << num <<" is Armstrong Number" << endl;
    else
        cout << num << " is Not Armstrong Number" << endl;
    return 0;
}