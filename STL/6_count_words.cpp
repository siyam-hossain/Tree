#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    string s;
    getline(cin,s);

//take word by word space present (stringstream)
    stringstream ss(s);
    string word;

    map<string, int> mp;
    
    
    while (ss>>word)
    {
        // mp[word] predefined value is 0
        // mp[word] = mp[word]+1;
        mp[word]++;
    }

    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    



    return 0;
}