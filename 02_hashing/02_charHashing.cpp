#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout << "Enter the string : ";
    cin >> s;

    int hash_lowerCase[26] = {0};                    // For all Characters -> hash[256]

    for(int i=0; i<s.size(); i++)
    {
        hash_lowerCase[s[i] - 'a']++;              // For Upper Case -> hash[s[i] - 'A']++
    }

    char ch;
    cout << "Enter the character to fetch : ";
    cin >> ch;

    cout << hash_lowerCase[ch - 'a'] << endl;

    return 0;
}