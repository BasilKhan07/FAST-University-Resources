#include<iostream>

using namespace std;

class node{
    public:
        int data;
        node* next;
        node(int val)
        {
            data = val;
            next = NULL;
        }
};

void insertathead(node* &head, int val)
{
	node* n = new node(val);
	n->next = head;
	head = n;
}

void insertattail(node* &head, int val)
{
    node* n = new node(val);
    if(head==NULL)
    {
    	head = n;
    	return;
	}
    node* temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next=n;
}

void deletehead(node* &head)
{
	node* todelete = head;
	head = head->next;
	delete todelete;
}

void deletion(node* &head, int val)
{
	node* temp=head;
	if(head==NULL)
	{
		return;
	}
	if(head->next==NULL)
	{
		deletehead(head);
		return;
	}
	while(temp->next->data!=val)
	{
		temp = temp->next;
	}
	node* todelete = temp->next;
	temp->next = temp->next->next;
	delete todelete;
}

bool search(node* head, int val)
{
	node* temp = head;
	while(temp!=NULL)
	{
		if(temp->data == val)
		{
			return true;
		}
		temp=temp->next;
	}
	return false;
}

void display(node* head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    // using insertattail to add nodes
    insertattail(head, 1);
    insertattail(head, 2);
    insertattail(head, 3);
    display(head);
    // using insertathead to insert node in beginning
    insertathead(head, 0);
    insertattail(head, 4);
    display(head);
    // for searching node using value
    cout << search(head, 3) << endl;
    // deletion of node excluding head
    deletion(head, 3);
    display(head);
    insertattail(head, 5);
    display(head);
    // function using for deletion of head only
    deletehead(head);
    display(head);
}
