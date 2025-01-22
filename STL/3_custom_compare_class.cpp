#include<bits/stdc++.h>
using namespace std;

class student {
public:
    string name;
    int rool;
    int marks;

    student(string name, int rool, int marks) {
        this->name = name;
        this->rool = rool;
        this->marks = marks;
    }
};
//we remember it as a syntax
class cmp
{
    public:
        bool operator()(student l, student r)
        {
            //on the opposite of ascending order sorting
            //condition in ascending order but it work as descending order
            if(l.marks<r.marks) return true;
            else return false;
        }

};

int main(int argc, char const *argv[])
{

    priority_queue<student, vector<student>,cmp>pq;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        
        string name;
        int rool,marks;
        cin>>name>>rool>>marks;


        student obj(name,rool,marks);
        pq.push(obj);
    }

    while (!pq.empty())
    {
        cout<<pq.top().name<<" "<<pq.top().rool<<" "<<pq.top().marks<<endl;
        pq.pop();
    }
         
    return 0;
}