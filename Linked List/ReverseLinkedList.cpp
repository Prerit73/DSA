#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int data1)
    {
        data = data1;
        next = NULL;
    }

    Node(int data1, Node *next)
    {
        data = data1;
        next = next;
    }
};

Node* reverseLinkedList(Node* head){
    Node* tail = head;
    Node* prev = NULL;
    Node* temp = NULL;

    while(tail){
        temp = tail->next;
        tail->next = prev;

        prev = tail;
        tail = temp;
    }

    return prev;
}

Node* recursiveReverseLinkedList(Node* head){
    if(head==NULL ||head->next==NULL){
        return head;
    }
    
    Node* newHead =  recursiveReverseLinkedList(head->next);
    Node* front =  head->next;
    front->next = head;
    
    head->next = NULL;
    return newHead;
    
}

void printLinkedList(Node* head){
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head = recursiveReverseLinkedList(head);
    printLinkedList(head);
    
    return 0;
}
