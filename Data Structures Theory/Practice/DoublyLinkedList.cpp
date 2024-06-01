#include<iostream>

using namespace std;

class node{
    public:
        int data;
        node *next;
        node *prev;

        node(int val)
        {
            data = val;
            next = NULL;
            prev = NULL;
        }
};

void InsertAtHead(node* &head, int val)
{
    node *n = new node(val);
    n->next = head;
    if(head!=NULL) // if head == NULL we cannot point it to previous
    {
        head->prev = n;
    }
    head = n;
}

void InsertAtTail(node* &head, int val)
{
    if(head==NULL) // if no node exist in linked list
    {
        InsertAtHead(head, val);
        return;
    }
    node *n = new node(val);
    node *temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}
// DELETE HEAD BY USING POSITION
void deleteheadpos(node* &head, int pos)
{
    node* todel = head;
    head = head->next;
    head->prev = NULL;
    delete todel;
}
// DELETE HEAD BY USING VALUE
void deleteheadvalue(node* &head, int val)
{
    node* todel = head;
    head = head->next;
    head->prev = NULL;
    delete todel;
}
// DELETE BY VALUE
void deletenodebyvalue(node* &head, int key)
{
    if(head->data==key) // if value is at head
    {
        deleteheadvalue(head, key);
        return;
    }
    node *temp=head;
    while(temp->data!=key)
    {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    if(temp->next!=NULL) // beacuse if value is at last node
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}
// DELETE BY POSITION
void deletenodebypos(node* &head, int pos)
{
    if(pos==1) // if position is head
    {
        deleteheadpos(head, pos);
        return;
    }
    node *temp = head;
    int count = 1;
    while (temp!=NULL && count!=pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if(temp->next!=NULL) // beacuse if value is at last node
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

void Display(node* head)
{
    node *temp=head;
    while (temp!=NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    cout << "Inserting node at end." << endl;
    InsertAtTail(head, 1);
    InsertAtTail(head, 2);
    InsertAtTail(head, 3);
    InsertAtTail(head, 4);
    InsertAtTail(head, 5);
    InsertAtTail(head, 6);
    Display(head);
    cout << endl << "Insering node at head." << endl;
    InsertAtHead(head, 0);
    Display(head);
    cout << endl << "Deletion using value." << endl;
    deletenodebyvalue(head, 2);
    Display(head);
    cout << endl << "Deletion using position" << endl;
    deletenodebypos(head, 4);
    Display(head);
    cout << endl << "Deletion of head using value" << endl;
    deletenodebyvalue(head, 0);
    Display(head);
    cout << endl << "Deletion of head using position" << endl;
    deletenodebypos(head, 1);
    Display(head);
}