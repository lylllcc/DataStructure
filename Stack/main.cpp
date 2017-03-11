#include <iostream>

using namespace std;

template<typename T>
class Stack
{
public:
    Stack();
    void pop();
    bool empty();
    T top();
    int size();
    void push(const T& data);
private:
    struct StackNode
    {
        T data;
        StackNode *link;
        StackNode(const T& d,StackNode* l):data(d),link(l)
        {}
    };
    T data;
    // top
    StackNode *t;
    // size
    int s;
};
template <typename T>
Stack<T>::Stack()
{
    s = 0;
    t = NULL;
}


template <typename T>
void Stack<T>::pop()
{
    StackNode * temp = t;
    t = t->link;
    --s;
    delete temp;
}
template <typename T>
bool Stack<T>::empty()
{
    return !s;
}

template <typename T>
T Stack<T>::top()
{
    return t->data;
}

template <typename T>
int Stack<T>::size()
{
    return s;
}

template <typename T>
void Stack<T>::push(const T& data)
{
    t = new StackNode(data,t);
    ++s;
}
int main()
{

    return 0;
}
