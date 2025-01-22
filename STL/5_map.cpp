#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    map<string,int>mp;

    // map_name["key"] = val
    mp["siyam"] = 5; //O(logn)
    mp["sh"] = 7;
    mp["hi"] = 700;
    mp["No"] = 200;
    mp["Yes"] = 200;

    //map work as pair concept
    //we can access pair first and second member
    //if we want to print it using iterator we need to use dereference first

    for (auto it = mp.begin(); it != mp.end(); it++) //overall O(nlogn)
    {
        cout<<it->first<<" "<<it->second<<endl; //O(logn);
    }
    
    // cout<<mp["siyam"]<<endl;

cout<<endl;
    mp["hemel"] = 0;
    cout<<mp["hemel"]<<endl;

    if(mp.count("hemel"))
    {
        cout<<"ache\n";
    }else cout<<"nai\n";

    //insert function
    mp.insert({"insert",2});
    mp.insert(make_pair("rasel",5));
    cout<<mp["rasel"]<<endl;
    return 0;
}