//  MAP HASHING -> 
//                It basically solves the problem of space complexity b/c of 
//                limited array sizes (in main -> 10e+6 & in global space -> 10e+7)
//                *Map stores the data in <key, value> pair in which value has to be increased upon occurence.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int arrSize = 13;
    int arr[] = {1, 2, 3, 12, 10, 2, 2, 2, 3, 12, 7, 6, 5};

   unordered_map<int, int> mpp;

   for(int i=0; i<arrSize; i++)
   {
        mpp[arr[i]]++;
   }

    // Iterate through the map
   for(auto it:mpp)
   {
        cout << it.first << " -> " << it.second << endl;
   }

//    int num;
//    cout << "Enter the Element to get its Count : ";
//    cin>> num; 
//    cout << mpp[num] << endl;

    return 0;
}


/* 
    *NOTE :- 

    *1. Time Complexity : 
        1. Ordered Map takes O(log N) for its computing.
        2. Unordered Map takes -> Best and Average Case : O(1) and Worst Case : O(N) { Worst Case happens Rarely -> Divison Method Collision is an Example}
    
    2. So for HashMap we should use Unordered Map so that our overall time complexity becames O(N) i.e O(N x 1).
*/