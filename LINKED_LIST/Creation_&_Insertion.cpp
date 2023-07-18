#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void InsertHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void InsertTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void InsertPosition(Node *&head, Node *&tail, int data, int position)
{
    if (position == 1)
    {
        InsertHead(head, data);
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
    temp->next = nodeToInsert;
}

void printLL(Node *&head)
{

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main()
{
    Node *node1 = new Node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;

    Node *head = node1;
    Node *tail = node1;
    printLL(head);

    InsertHead(head, 12);
    printLL(head);

    InsertTail(tail, 15);
    printLL(head);

    InsertPosition(head,tail,22,3);
    printLL(head);

    return 0;
}
