#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int val;
    node *left;
    node *right;

    node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};


void level_order(node *root)
{

    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        node *front = q.front();
        q.pop();

        cout<<front->val<<" ";

        if(front->left) q.push(front->left);
        if(front->right) q.push(front->right);
    }
}

node *convert(int a[], int n, int l, int r)
{
    // base case
    if(l > r) return NULL;


    int mid = (l+r)/2;
    node *root = new node(a[mid]);
    
    node *lf_root = convert(a,n,l,mid-1);
    node *rgt_root = convert(a,n,mid+1,r);

    root->left = lf_root;
    root->right = rgt_root;

    return root;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int a[n] ;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    node *root = convert(a,n,0,n-1);
    
    level_order(root);

    return 0;
}