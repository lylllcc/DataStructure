#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int lastop = 0;
class BinaryTree{
    struct Node{
        char data;
        Node *left, *right;
        Node(char d,Node *left = NULL,Node *right = NULL)
        {
            data = d;
            this->left = left;
            this->right = right;
        }
    };
private:
    Node *root;
public:
    void create(){ create(root); }
    void create(Node* &subtree);
    void mid(){ mid(root); }
    void mid(Node* subtree);
    int caculate(){ return caculate(root);}
    int caculate(Node* subtree);
};

int BinaryTree::caculate(Node* subtree){
    if(subtree->data == '+' )
        return caculate(subtree->left) + caculate(subtree->right);
    if(subtree->data == '-' )
        return caculate(subtree->left) - caculate(subtree->right);
    if(subtree->data == '*' )
        return caculate(subtree->left) * caculate(subtree->right);
    if(subtree->data == '/' )
        return caculate(subtree->left) / caculate(subtree->right);
    return subtree->data - '0';
}

void BinaryTree::create(Node* &subtree){
    char data;
    cin>>data;
    if(data != '@'){
        subtree = new Node(data);
        create(subtree->left);
        create(subtree->right);
    }
}
void BinaryTree::mid(Node* subtree){
    int flag = 0;
    if(subtree == NULL){
         return;
    }
    if(lastop == 1 && (subtree->data == '+' || subtree->data == '-'))
    {
        cout<<"(";
        flag = 1;
        lastop = 0;
    }
    mid(subtree->left);
    cout<<subtree->data;
    if(subtree->data == '*' || subtree->data == '/'){
        lastop = 1;
    }else lastop = 0;

    mid(subtree->right);
    if(flag == 1)
        cout<<")";
}



int main()
{

   // freopen("in.txt","r",stdin);
    BinaryTree t;
    t.create();
    t.mid();
    cout<<"=";
    cout<<t.caculate()<<endl;
    return 0;
}
