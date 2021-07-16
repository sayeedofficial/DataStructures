#include <bits/stdc++.h>

using namespace std;

template<typename T>

class node{
public:
    T data;
    node *next,*prev;
    
    node(T data){
        this->data = data;
        next = prev = NULL;
    }
    node * insertFront(node *start,T data){
        node *newnode = new node(data);
        newnode->next = start;
        start->prev = newnode;
        start = newnode;
        return start;
    }
    node * insertEnd(node *start,T data){
        if(!start) return new node(data);
        if(start->next==NULL){
            node *newnode = new node(data);
            start->next = newnode;
            newnode->prev = start;
            newnode->next = NULL;
        }
        start->next = insertEnd(start->next,data);
        return start;
    }
    void printForward(node *start){
        if(start){
            cout<<start->data<<" ";
            printForward(start->next);
        }
    }

};


int main(){
    node<int> *ll1 = NULL;
    for(int i=0;i<=7;i++){
        ll1 = ll1->insertFront(ll1,i);
    }
    cout<<ll1->data<<endl;
    //ll1->printForward(ll1);
}