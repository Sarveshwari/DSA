#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *prev;

    Node(int a)
    {

        this->data = a;
        this->next = NULL;
        this->prev = NULL;
    }
};

void printDLL(Node *&head)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node *&head)
{
    int len = 0;

    Node *temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    return len;
}

void InsertHead(Node *&head, int data)
{

    Node *temp = new Node(data);

    temp->next = head;
    head->prev = temp;
    head = temp;
}

void InsertTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void InsertPosition(Node *&head, Node *&tail, int position, int data)
{

    if (position == 1)
    {
        InsertHead(head, data);
        return;
    }

    int cnt = 1;
    Node *temp = head;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL)
    {
        InsertTail(tail, data);
    }

    Node *nodeToInsert = new Node(data);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

int main()
{

    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1;

    printDLL(head);

    InsertHead(head, 11);
    printDLL(head);

    InsertTail(tail, 12);
    printDLL(head);

    InsertPosition(head, tail, 2, 13);
    printDLL(head);

    return 0;
}
