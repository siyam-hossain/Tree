#include<bits/stdc++.h>
using namespace std;

class student {
public:
    string name;
    int roll;
    int marks;

    student(string name, int rool, int marks) {
        this->name = name;
        this->roll = rool;
        this->marks = marks;
    }
};
//we remember it as a syntax
class cmp
{
    public:
        bool operator()(student l, student r)
        {

            //for ascending order
            if(l.marks > r.marks) return true;
            else if(l.marks < r.marks) return false;
            else
            {
                if(l.roll > r.roll)
                {
                    return true;
                }
            }
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
        int roll,marks;
        cin>>name>>roll>>marks;


        student obj(name,roll,marks);
        pq.push(obj);
    }

    while (!pq.empty())
    {
        cout<<pq.top().name<<" "<<pq.top().roll<<" "<<pq.top().marks<<endl;
        pq.pop();
    }
         
    return 0;
}