#include <bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
    node *insertFront(node *head, int data)
    {
        node *newNode = new node(data);
        node *getLastNode = head;
        while (getLastNode->next != head)
        {
            getLastNode = getLastNode->next;
        }
        newNode->next = head;
        getLastNode->next = newNode;
        head = newNode;
        return head;
    }
    node * insertEnd(node *head,int data){
        node *curr = head;
        node *newNode = new node(data);
        while(curr->next != head){
            curr = curr->next;
        }
        newNode->next = head;
        curr->next = newNode;
        return head;
    }
    node * deleteFront(node *head){
        node *curr = head;
        node *currentHead = head;
        node *nodeAfterHead = head->next;
        while(curr->next!=head){
            curr = curr->next;
        }
        delete currentHead;
        curr->next = nodeAfterHead;
        head = nodeAfterHead;
        return head;
    }
    node * deleteEnd(node *head){
        node *curr = head;
        
        while(curr->next->next!=head){
            curr = curr->next;
        }
        node *lastnode = curr->next->next;
        delete lastnode;
        curr->next = head;
        return head;
    }
    
};

node *createList(int data)
{
    node *tempNode = new node(data);
    tempNode->next = tempNode;
    return tempNode;
}

void printList(node *head)
{
    node *temp = head;
    while(temp->next!=head){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<" ";
}

int main()
{

    node *ll1 = NULL;
    ll1 = createList(5);
    ll1 = ll1->insertFront(ll1,4);
    ll1 = ll1->insertFront(ll1,3);
    ll1 = ll1->insertFront(ll1,2);
    ll1 = ll1->insertFront(ll1,1);
    ll1 = ll1->insertEnd(ll1,7);
    ll1 = ll1->insertEnd(ll1,8);
    ll1 = ll1->insertEnd(ll1,9);
    ll1 = ll1->insertEnd(ll1,10);

    ll1 = ll1->deleteEnd(ll1);
    ll1 = ll1->deleteFront(ll1);


    printList(ll1);

}