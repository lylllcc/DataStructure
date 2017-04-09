#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>

using namespace std;

template <typename T>
class BinaryTree;

template <typename T>
struct BinaryNode
{
    T data;
    BinaryNode *left,*right;
    BinaryNode(T d,BinaryNode *l = NULL,BinaryNode *r = NULL):data(d),right(r),left(l)
    {}
};

template <typename T>
class BinaryTree
{
private:
    BinaryNode<T> *root;
    T refValue;
    void CreateBinaryTree(BinaryNode<T>* &subtree);
    int Depth(const BinaryNode<T> *subtree) const;
    int Leaf(const BinaryNode<T> *subtree) const;
    int Size(const BinaryNode<T> *subtree) const;
    void Pre(const BinaryNode<T> *subtree) const;
    void Mid(const BinaryNode<T> *subtree) const;
    void Last(const BinaryNode<T> *subtree) const;


    int Find(char x,const BinaryNode<T> *subtree) const;
public:
    BinaryTree(T refVa,BinaryNode<T> *r = NULL): refValue(refVa),root(r)
    {}
    void CreateBinaryTree()
    {
        CreateBinaryTree(root);
    }
    int Depth()
    {
        return Depth(root);
    }
    int Leaf()
    {
        return Leaf(root);
    }
    int Size()
    {
        return Size(root);
    }
    void Pre()
    {
        Pre(root);
    }
    void Mid()
    {
        Mid(root);
    }
    void Last()
    {
        Last(root);
    }
    int Find(char x){
       return Find(x,root);
    }
    void Print();
};
template <typename T>
void BinaryTree<T>::CreateBinaryTree(BinaryNode<T>* &subtree)
{
    T item;
    cin>>item;
    if(item != refValue)
    {
        subtree = new BinaryNode<T>(item);
        CreateBinaryTree(subtree->left);
        CreateBinaryTree(subtree->right);
    }
}

template <typename T>
int BinaryTree<T>::Depth(const BinaryNode<T> *subtree) const
{
    if(subtree == NULL)
        return 0;

    return 1 + max(Depth(subtree->left),Depth(subtree->right));
}


template <typename T>
int BinaryTree<T>::Leaf(const BinaryNode<T> *subtree) const
{
    if(subtree == NULL)
        return 0;
    if(subtree->left == NULL && subtree->right == NULL)
    {
        return 1;
    }
    return Leaf(subtree->left) + Leaf(subtree->right);
}

template <typename T>
int BinaryTree<T>::Size(const BinaryNode<T> *subtree) const
{
    if(subtree == NULL)
        return 0;
    return 1 + Size(subtree->left) + Size(subtree->right);
}

template <typename T>
void BinaryTree<T>::Pre(const BinaryNode<T> *subtree) const
{
    if(subtree == NULL)
        return;
    cout<<subtree->data<<" ";
    Pre(subtree->left);
    Pre(subtree->right);

}
template <typename T>
void BinaryTree<T>::Mid(const BinaryNode<T> *subtree) const
{
    if(subtree == NULL)
        return;
    Mid(subtree->left);
    cout<<subtree->data<<" ";
    Mid(subtree->right);

}
template <typename T>
void BinaryTree<T>::Last(const BinaryNode<T> *subtree) const
{
    if(subtree == NULL)
        return;
    Last(subtree->left);
    Last(subtree->right);
    cout<<subtree->data<<" ";
}

template <typename T>
int BinaryTree<T>::Find(char x,const BinaryNode<T> *subtree) const
{
    if(subtree == NULL)
        return 0;
    if(subtree->data == x)
        return 1 + Find(x,subtree->left) +Find(x,subtree->right);
    return Find(x,subtree->left) +Find(x,subtree->right);
}

template <typename T>
void BinaryTree<T>::Print()
{
    stack<BinaryNode<char>*> s;
    BinaryNode<char> *temp;
    s.push(root);
    int n = 0,le[100]={0} ,top = 1;
    while(!s.empty()){
            n = le[top];
        for(int j=0;j<n;j++)
            cout<<"  ";
        temp = s.top();
        top--;
        s.pop();

        cout<<temp->data<<endl;
        if(temp->right != NULL){
             s.push(temp->right);
             top++;
             le[top] = n + 1;
        }
        if(temp->left != NULL)
        {
              s.push(temp->left);
              top++;
              le[top] = n + 1;
        }

    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    BinaryTree<char> tree('#');
    char tag[20];
    char x[10];
    while(cin>>tag)
    {
        switch(tag[0])
        {
        case 'C':
            tree.CreateBinaryTree();
            cout<<"Created success!"<<endl;
            break;
        case 'H':
            cout<<"Height="<< tree.Depth()<<".\n";
            break;
        case 'L':
            cout<<"Leaf="<< tree.Leaf() <<".\n";
            break;

        case 'N':
            cout<<"Nodes="<< tree.Size() <<".\n";
            break;
        case '1':
            cout<<"Preorder is:";
            tree.Pre();
            cout <<".\n";
            break;
        case '2':
            cout<<"Inorder is:";
            tree.Mid();
            cout <<".\n";
             break;
        case '3':
            cout<<"Postorder is:";
            tree.Last();
            cout <<".\n";
             break;
        case 'F':
            cin>>x;
            cout<<"The count of "<<x[0]<<" is "<<tree.Find(x[0])<<".\n";
            break;
        case 'P':
            cout<<"The tree is:"<<endl;
            tree.Print();
        }
    }
    return 0;
}
