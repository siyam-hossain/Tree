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

void all_lv_nodes(node *root, int x)
{
    //i am checking the first corner case
    if(root == NULL)
    {
        cout<<"Invalid\n";
        return;
    }

    queue< pair<node *, int> > lv;
    //acording to the constrain level start form 0
    lv.push({root, 0});

    int track = 0;

    while (!lv.empty())
    {
        pair< node *, int> p = lv.front();
        lv.pop();

        node *tr_node = p.first;
        int l = p.second;

        //if given level is equivalent to our tree level then do this
        if(x == l)
        {
            cout<<tr_node->val<<" ";
            track = 1;
        }
        if(tr_node->left) lv.push({tr_node->left, l+1});
        if(tr_node->right) lv.push({tr_node->right, l+1});
    }
    if(!track)  cout<<"Invalid\n";
}

int main(int argc, char const *argv[])
{


    node *root = input_tree();
    
    int x;
    cin>>x;
    all_lv_nodes(root,x);

    
    return 0;
}