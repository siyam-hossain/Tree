#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    /*
    
        1. remove duplicate
        2. sorted manner
            in_order traversal
        3. set is a bst STL
    */ 
   //working on unique value 
   set<int> s;
   int n;
   cin>>n;
   while (n--)
   {
    int val;
    cin>>val;
    s.insert(val); //logN

   }
   for (auto it = s.begin(); it != s.end(); it++)
   {
        cout<<*it<<endl;
   }
   //if we need to reverse it then it require a vector push on it and reverse it
    
    cout<<endl;
    if(s.count(1)) cout<<"ache";
    else cout<<"nai";
    return 0;
}