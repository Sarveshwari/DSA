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

void InsertPosition(Node *&tail, int element, int data)
{
    if (tail == NULL)
    {

        Node *newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    }

    else
    {

        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void printCLL(Node *&tail)
{
    Node *temp = tail;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);

    cout << endl;
}

int main()
{
    Node *tail = NULL;

    InsertPosition(tail, 5, 3);
    printCLL(tail);

    InsertPosition(tail, 3, 4);
    printCLL(tail);

    InsertPosition(tail, 4, 5);
    printCLL(tail);

    return 0;
}
