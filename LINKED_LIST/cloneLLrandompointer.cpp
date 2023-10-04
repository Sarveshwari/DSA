class Solution
{
    void InsertAtTail(Node* &head, Node* &tail, int data)
    {
        Node* Newnode=new Node(data);
        if(head==NULL)
        {
            head=Newnode;
            tail=Newnode;
            return;
        }
        else
        {
            tail->next= Newnode;
            tail=Newnode;
        }
        
    }
    
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        
        Node* clonehead=NULL;
        Node* clonetail=NULL;
        
        Node* temp=head;
        
        while(temp!=NULL)
        {
            InsertAtTail(clonehead, clonetail, temp->data);
            temp=temp->next;
        }
        
        unordered_map<Node* , Node*>oldtonew;
        
        Node* originalnode=head;
        Node* newnode=clonehead;
        
        
        while(originalnode!=NULL)
        {
            oldtonew[originalnode]=newnode;
            originalnode=originalnode->next;
            newnode=newnode->next;
        }
        
        originalnode=head;
        newnode=clonehead;
        
        while(originalnode!=NULL)
        {
            newnode->arb=oldtonew[originalnode->arb];
            originalnode=originalnode->next;
            newnode=newnode->next;
        }
        
        return clonehead;
        
    }

};
