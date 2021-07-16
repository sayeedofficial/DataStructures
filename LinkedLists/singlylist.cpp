#include <bits/stdc++.h>
using namespace std;

template <typename T>

class node
{
public:
    T data;
    node *next;

    node(T data)
    {
        this->data = data;
        next = NULL;
    }
    node *insertBeg(node *root, T data)
    {
        if (!root)
            return new node(data);
        node *headNode = new node(data);
        headNode->next = root;
        root = headNode;
        return root;
    }
    node *insertEnd(node *start, T data)
    {
        if (!start)
            return new node(data);
        start->next = insertEnd(start->next, data);
        return start;
    }
    bool search(node *start, T key)
    {
        if (!start)
            return false;
        if (start->data == key)
            return true;
        return search(start->next, key);
    }
    node *deleteBeg(node *start)
    {
        node *temp = start;
        start = start->next;
        delete temp;
        return start;
    }
    node *deleteEnd(node *start)
    {

        if (!start)
            return start;
        if (!start->next)
        {
            delete start->next;
            return NULL;
        }
        if (start->next->next == NULL)
        {
            node *lastNode = start->next->next;
            delete lastNode;
            start->next = NULL;
        }
        start->next = deleteEnd(start->next);
        return start;
    }
    void print(node *root){
        if(root){
            cout<<root->data<<" ";
            print(root->next);
        }
    }
};

int main(){
    node<int> *ll1 = NULL;
    for(int i=1;i<=7;i++){
        ll1 = ll1->insertEnd(ll1,i);
    }
    ll1 = ll1->insertBeg(ll1,0);
    ll1 = ll1->deleteBeg(ll1);
    ll1 = ll1->deleteEnd(ll1);

    ll1->print(ll1);
}