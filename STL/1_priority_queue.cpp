//max priority queue
#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    priority_queue<int> pq;

    pq.push(10);
    pq.push(5);
    pq.push(30);
    cout<<pq.top()<<endl;
    pq.push(110);
    pq.pop();
    pq.pop();
    cout<<pq.top()<<endl;//top refers as front
    return 0;
}