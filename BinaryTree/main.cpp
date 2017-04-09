#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

class Tree
{
    struct Node
    {
        char data;
        Node *left,*right;
        Node(char d,Node* l=NULL,Node* r=NULL)
        {
            data=d;
            left=l;
            right=r;
        }
    };
private:
    Node* root;
    void create(Node* &subtree);
    void pre(Node*subtree);
    void mid(Node*subtree);
    void last(Node *subtree);
    int height(Node *subtree);
    int leaf(Node *subtree);
    int node(Node *subtree);
    int findx(Node *subtree,char x);
    void print(Node *subtree,int dep);
public:
    void create()
    {
        create(root);
    }
    void mid()
    {
        mid(root);
    }
    void pre()
    {
        pre(root);
    }
    void last()
    {
        last(root);
    }
    int height()
    {
        return height(root);
    }
    int leaf()
    {
        return leaf(root);
    }
    int node()
    {
        return node(root);
    }
    int findx(char x)
    {
        return findx(root,x);
    }
    void print()
    {
        print(root,0);
    }
};
void Tree::print(Node* subtree,int dep)
{
    if(subtree == NULL)
        return ;
    for(int i=0;i<dep;i++)
        cout<<"  ";
    cout<<subtree->data<<'\n';
    print(subtree->left,dep+1);
    print(subtree->right,dep+1);
}
void Tree::create(Node* &subtree)
{
    char data;
    cin>>data;
    if(data=='#')
        return ;
    subtree =new Node(data);
    create(subtree->left);
    create(subtree->right);
}
void Tree::pre(Node *subtree)
{
    if(subtree == NULL)
        return ;
    cout<<subtree->data<<" ";
    pre(subtree->left);
    pre(subtree->right);
}
void Tree::mid(Node *subtree)
{
    if(subtree == NULL)
        return ;
    mid(subtree->left);
    cout<<subtree->data<<" ";
    mid(subtree->right);
}
void Tree::last(Node *subtree)
{
    if(subtree == NULL)
        return ;
    last(subtree->left);
    last(subtree->right);
    cout<<subtree->data<<" ";
}
int Tree::height(Node *subtree)
{
    if(subtree == NULL)
        return 0;
    return 1 + max(height(subtree->left),height(subtree->right));
}
int Tree::leaf(Node *subtree)
{
    if(subtree == NULL)
        return 0;
    if(subtree->left == NULL && subtree->right == NULL)
        return 1;
    return leaf(subtree->left) + leaf(subtree->right);
}
int Tree::node(Node *subtree)
{
    if(subtree == NULL)
        return 0;
    return node(subtree->left) + node(subtree->right) + 1;
}
int Tree::findx(Node *subtree,char x)
{
    if(subtree == NULL)
        return 0;
    if(subtree->data == x)
        return 1 + findx(subtree->left,x) + findx(subtree->right,x);
    return findx(subtree->left,x) + findx(subtree->right,x);
}
int main()
{
    //freopen("in.txt","r",stdin);
    char x[10],xx;
    Tree t;
    while(cin>>x)
    {
        switch(x[0])
        {
        case 'C':
            t.create();
            cout<<"Created success!\n";
            break;
        case 'H':
            cout<<"Height="<<t.height()<<".\n";
            break;
        case 'L':
            cout<<"Leaf="<<t.leaf()<<".\n";
            break;
        case 'N':
            cout<<"Nodes="<<t.node()<<".\n";
            break;
        case '1':
            cout<<"Preorder is:";
            t.pre();
            cout<<".\n";
            break;
         case '2':
            cout<<"Inorder is:";
            t.mid();
            cout<<".\n";
            break;
        case '3':
            cout<<"Postorder is:";
            t.last();
            cout<<".\n";
            break;
        case 'F':
            cin>>xx;
            cout<<"The count of "<<xx<<" is "<<t.findx(xx)<<".\n";
            break;
        case 'P':
            cout<<"The tree is:\n";
            t.print();
        }
    }
    return 0;
}
