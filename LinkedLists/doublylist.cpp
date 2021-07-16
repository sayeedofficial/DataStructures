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
        if(!start) return new node(data);
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
            return start;
        }
        start->next = insertEnd(start->next,data);
        return start;
    }
    node * deleteFront(node *start){
        node *temp = start;
        start = start->next;
        delete temp;
        return start;
    }
    node * deleteEnd(node *start){
         if(!start) return start;
         if(start->next->next==NULL){
             node *lastNode = start->next->next;
             start->next = NULL;
             delete lastNode;
             return start;
         }     

         start->next = deleteEnd(start->next);
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
    ll1 = ll1->insertEnd(ll1,5);
    ll1 = ll1->insertEnd(ll1,6);
    ll1 = ll1->insertEnd(ll1,7);
    ll1 = ll1->insertEnd(ll1,8);
    ll1 = ll1->deleteEnd(ll1);

    ll1->printForward(ll1);

}