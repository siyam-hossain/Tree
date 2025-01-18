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

node *input_tree()
{
    int data;
    cin>>data;
    node *root = new node(data);

    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {

       node *f = q.front();
       q.pop();

        node *lchild, *rchild;
        int lft, rgt;
        cin>>lft>>rgt;

        (lft == -1) ? lchild = NULL : lchild = new node(lft);
        (rgt == -1) ? rchild = NULL : rchild = new node(rgt);
            f->left = lchild;
            f->right = rchild;

        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);
    }
    
    return root;
};

int max_height(node *root)
{
    if(root == NULL) return 0;
    int lft = max_height(root->left);
    int rgt = max_height(root->right);

    return max(lft , rgt) + 1;
}

int cnt(node *root)
{
    if(root == NULL) return 0;
    int lft = cnt(root->left);
    int rgt = cnt(root->right);

    return lft+rgt+1;
}


int main(int argc, char const *argv[])
{


    node *root = input_tree();
    
    int md = max_height(root);
    
    int n_nodes = pow(2,md) - 1;
    //we can do this manully
    // int num_nod = 1;
    // for (int i = 1; i <= md; i++)
    // {
    //     num_nod = num_nod*2;
    // }
    // num_nod -=1 ;
    int node_present = cnt(root);

    if(n_nodes == node_present) cout<<"YES\n";
    // if(num_nod == node_present) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}