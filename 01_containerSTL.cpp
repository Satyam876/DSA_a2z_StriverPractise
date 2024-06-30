// CONTAINERS -> Vectors, Maps , Queues etc

#include<bits/stdc++.h>
using namespace std;

// 1. PAIRS 

void explainPairs()
{
    pair<int, int>p = {1, 3};                // Pairs are used to store multiple variables in pairs

    cout<<"1st Element of Pair (p) : "<<p.first<<endl;
    cout<<"2nd Element of Pair (p) : "<<p.second<<endl;

    pair<int, pair<int, int>>p2 = {1, {2, 4}};

    cout<<"1st Element of Pair (p2) : "<<p2.first<<endl;
    cout<<"1st Element of 2nd Element of pair (p2) : "<<p2.second.first<<endl;
    cout<<"2nd Element of 2nd Element of pair (p2) : "<<p2.second.second<<endl;

    pair<int, int>arr[] = {{1,3}, {5,7}, {9,11}};
    cout<<"2nd Element of 3rd Index of Array : "<<arr[2].second<<endl;

}


int main()
{
    explainPairs();
    return 0;
}