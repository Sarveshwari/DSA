#include<iostream>
using namespace std;

class Node{
     
     public:

     int data;
     Node* next;
     Node* prev;

     Node(int a){

        this->data=a;
        this->next=NULL;
        this->prev=NULL;
     }
};

void printDLL(Node* &head){

    Node* temp=head;
    
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
        
    }
}

int main()
{

    Node* node1= new Node(10);
    Node* head =node1;

    printDLL(head);

 return 0;
}
