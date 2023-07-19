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

    ~Node()
    {

        int value = this->data;

        if (this->next != NULL)
        {
            this->next = NULL;
            delete this;
        }

        cout << "memory freed for node with data " << value << endl;
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

void InsertHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;

        return;
    }

    Node *temp = new Node(data);

    temp->next = head;
    head->prev = temp;
    head = temp;
}

void InsertTail(Node *&tail, Node *&head, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;

        return;
    }

    Node *temp = new Node(data);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void InsertPosition(Node *&head, Node *&tail, int position, int data)
{

    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;

        return;
    }

    if (position == 1)
    {
        InsertHead(head, tail, data);
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
        InsertTail(tail, head, data);

        return;
    }

    Node *nodeToInsert = new Node(data);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

void deletePosition(Node *&head, int position)
{

    if (position == 1)
    {
        Node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {

        Node *prev = NULL;
        Node *curr = head;

        int cnt = 1;
        while (cnt < position)
        {

            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{

    Node *head = NULL;
    Node *tail = NULL;

    InsertHead(head, tail, 11);
    printDLL(head);

    InsertHead(head, tail, 13);
    printDLL(head);

    InsertHead(head, tail, 8);
    printDLL(head);

    InsertTail(tail, head, 25);
    printDLL(head);

    InsertPosition(head, tail, 2, 100);
    printDLL(head);

    InsertPosition(head, tail, 1, 101);
    printDLL(head);

    InsertPosition(head, tail, 7, 102);
    printDLL(head);

    deletePosition(head, 6);
    printDLL(head);

    return 0;
}
