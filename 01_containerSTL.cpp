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


// 2. VECTORS -> Dynamic in nature -> store data according to our sizes 

void explainVectors()
{
    vector<int> v;

    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int, int>> v2;
    v2.push_back({1,3});              // push_back -> pairs have to be included in {}
    v2.emplace_back(1,3);             // emplace_back -> automatically assigns to pair

    vector<int> v3(5, 100);        // Creates 5 instances of value 100 -> {100, 100, 100, 100, 100}

    vector<int> v4(5);             // Same Creates 5 instances with some garbage values

    vector<int> v5(7, 20);
    vector<int>v6(v5);

    vector<int>v7 = {10, 20, 30, 40, 50};

    // Accessing the Vectors

    vector<int>::iterator it = v6.begin();
    cout<< *(it)<<" ";                          // Printing only 1st index because we have not used loops
    it++;

    // other ways of iterator initializations

    // {10, 20, 30, 40, 50}

    // vector<int>::iterator it = v6.end();            // It points to adress of last index + 1 & not on last index ** -> (address of )50 + 1;
    // vector<int>::iterator it = v6.rend();           // Points to reverse of vector i.e address of 10 + 1;
    // vector<int>::iterator it = v5.rbegin();

    cout<<v6[0]<<" "<<v6.at(0)<<endl;
    cout<<v6.back()<<endl;

/*  for(vector<int>::iterator it = v7.begin(); it != v7.end(); it++)
    {
        cout<< *(it) <<" ";
    }
    cout<<endl;

    for(auto it = v7.begin(); it != v7.end(); it++)
    {
        cout<< *(it) <<" ";
    }
    cout<<endl;

    for(auto it : v7){
        cout<< (it) <<" ";
    }
    cout<<endl;
*/


    // ERASE FUNCTION

    vector<int> v8(v7);               //  {10, 20, 30, 40, 50}
    
    // v8.erase(v8.begin() + 2);      // Erase 30

    v8.erase(v8.begin()+2, v8.begin()+4);            // [start, end)  -> v8 = {10, 20, 50}


    // INSERT FUNCTION

    vector<int>v9(2,100);

    v9.insert(v9.begin()+2, 300);
    v9.insert(v9.begin()+1, 3, 9);

    vector<int>copy(2,50);

    v9.insert(v9.begin(), copy.begin(), copy.end());

    // for(auto it:v9){
    //     cout<< it <<" ";
    // }


    cout<<v9.size()<<endl;


    // POP ELEMENT

    v9.pop_back();


    // SWAP TWO VECTORS 

    vector<int>v10 = {1,2};
    vector<int>v11 = {3,4};

    v11.swap(v10);             // V10 -> {3,4}    V11-> {1,2}

    
    // CLEAR THE VECTOR
    v11.clear();
    cout<< v11.empty() <<endl;
}




// 3.  LISTS   -> Dynamically stores data and can insert data at front 

void explainList(){
    list<int> ls;

    ls.push_back(2);          // ls -> {2}
    ls.emplace_back(4);       // ls -> {2, 4}

    ls.push_front(5);         // ls -> {5, 2, 4}
    ls.emplace_front(10);     // ls -> {10, 5, 2, 4}

    for(auto it:ls){
        cout<< it <<" ";
    }

    // Rest functions are same as Vector
}



//   4. PRIORITY QUEUE  

void explainPriorityQueue()
{
    priority_queue<int> pq;

    pq.push(5);       // pq -> {5}
    pq.push(2);       // pq -> {5, 2}      
    pq.push(8);       // pq -> {8, 5, 2}      
    pq.emplace(10);      // pq -> {10, 8, 5, 2}

    cout<< pq.top() <<endl;       // prints 10

    // pq.pop();          // pq -> {8, 5, 2}

    cout<< pq.top() <<endl;       // prints 8


    // Min Heap  -> Priority queue based on ascending order

    priority_queue<int, vector<int>, greater<int>> pq_min;

    pq_min.push(20);           // pq_min -> {20}
    pq_min.push(5);            // pq_min -> {5, 20}
    pq_min.push(50);           // pq_min -> {5, 20, 50}

    cout<< pq_min.top() << endl;       // prints 5
}




// 5. SET  -> Stores Unique data in Sorted Order

void explainSet(){
    set<int> st;

    st.insert(1);                // st -> {1}
    st.insert(2);                // st -> {1, 2}
    st.insert(2);                // st -> {1, 2}    doesn't store duplicate values
    st.insert(4);                // st -> {1, 2, 4}
    st.emplace(3);               // st -> {1, 2, 3, 4}

    // auto it = st.find(1);
    // cout << *(it) << endl;

    // auto it = st.find(9);         // If not Found -> returns next address just after end()
    // cout << *(it) << endl;

    st.erase(4);                     // erases 4

    // for(auto it:st)
    // {
    //     cout<< it <<" ";
    // }

    int count = st.count(2);     // If present -> returns 1 otherwise returns 0
    cout<< count << endl;

    // auto it = st.find(2);
    // st.erase(it);

    // {1, 2, 3, 4, 5}
    auto it1 = st.find(2);
    auto it2 = st.find(4);

    st.erase(it1, it2);     // after erase -> {1, 4, 5}    [start, end)

 }


// 6. MULTI SET -> Sorted Order & No uniqueness -> allows duplicate values 

 void explainMultiSet(){

        multiset<int> ms;

        ms.insert(20);      // ms -> {20}
        ms.insert(10);      // ms -> {10, 20}
        ms.insert(10);      // ms -> {10, 10, 20}
        ms.insert(10);      // ms -> {10, 10, 10, 20}

        // ms.erase(10);       // it will erase all 10 


        // ms.erase(ms.find(10));     // erase 1st occurence of 10

        // ms.erase(ms.find(10), ms.find(10)+2);

        for(auto it:ms){
            cout << it << endl;
        }
 }


// 7. MAPS

void explainMap(){

    // Map -> 1. {key, value} where KEY is unnique & KEY can be of any datatype.
            //   2. Stores in sorted order

    map<int, int> mp;

    map<int, pair<int, int>> mpp;

    map<pair<int, int>, int> mpp1;

    mp[1] = 10;
    mp.insert({2, 20});
    mp.emplace(3, 30);

    // for(auto it:mp){
    //     cout << "Key : "<< it.first <<" ,Value : "<< it.second << endl;
    // }
    

    mpp.insert({2, {300, 400}});
    mpp.insert({1, {100, 200}});
    mpp.insert({3, {500, 600}});

        for(auto it:mpp){
        cout << "Key : "<< it.first <<" ,Pair Value 1 : "<< it.second.first << " ,Pair Value 2 : " << it.second.second << endl;
    }

    cout << mp[1] << endl;
    cout << mp[5] << endl;          // If not present then return 0 or null;

    auto it1 = mp.find(3);
    cout << (*it1).second << endl;

    auto it2 = mp.find(5);
    cout << (*it2).second << endl;            // points to next address after mp.end()
}








int main()
{
    // explainPairs();

    // explainVectors();

    // explainList();

    // explainPriorityQueue();

    // explainSet();

    // explainMultiSet();

    explainMap();

    return 0;
}