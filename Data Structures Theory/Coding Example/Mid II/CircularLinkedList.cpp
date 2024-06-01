#include <iostream>

using namespace std;

class Node
{
public:
    int info;
    Node *next;

    Node()
    {
        next = 0;
    }

    Node(int value, Node *ptr = 0)
    {
        info = value;
        next = ptr;
    }
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList()
    {
        head = 0;
    }

    void AddToHead(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node *temp = head;

            while (temp->next != head)
                temp = temp->next;

            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void AddAfter(int info, int value = 0)
    {
        if (isEmpty())
        {
            AddToHead(value);
        }
        else
        {
            Node *temp = head;

            while (temp->info != info && temp->next != head)
            {
                temp = temp->next;
            }
            if (temp->next != head)
            {
                Node *newNode = new Node(value);
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
    }

    void AddToTail(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void DeleteHead()
    {
        if (isEmpty())
        {
            cout << "List is Already Empty";
        }
        else
        {
            Node *pred = head, *temp = head;
            if (temp->next == head)
            {
                head = NULL;
                delete temp;
            }
            else
            {
                while (temp->next != head)
                {
                    temp = temp->next;
                }
                temp->next = head->next;
                delete head;
                head = temp->next;

                cout << "HERE....";
            }
        }
    }

    void DeleteSpecific(int value)
    {
        // Class Activity
    }

    void DeleteEnd()
    {
        if (isEmpty())
        {
            cout << "List is already Empty";
        }
        else
        {
            Node *pred = head, *temp = head->next;
            if (temp->next == head)
            {
                head = NULL;
                delete temp;
            }
            else
            {
                while (temp->next != head)
                {
                    pred = temp;
                    temp = temp->next;
                }
                pred->next = head;
                delete temp;
            }
        }
    }

    void PrintList()
    {
        if (isEmpty())
        {
            cout << "List is Empty..." << endl;
        }
        else
        {
            Node *temp = head;
            cout << endl;

            do
            {
                cout << temp->info << "\t";
                temp = temp->next;

            } while (temp != head);
        }
    }

    bool ValueExist(int val) const
    {
        Node *temp = head;
        while (temp->next != head && temp->info != val)
            temp = temp->next;

        return temp != 0;
    }

    ~CircularLinkedList()
    {
        for (Node *p; !isEmpty();)
        {
            p = head->next;
            delete head;
            head = p;
        }
    }

    int isEmpty()
    {
        return head == 0;
    }
};

int main()
{
    CircularLinkedList list;
    list.AddToHead(1);
    list.AddToHead(2);
    list.AddToTail(3);

    list.AddAfter(1, 4);

    list.PrintList();

    list.AddToHead(6);
    list.DeleteEnd();
    list.AddToTail(7);
    list.AddToHead(11);
    list.DeleteHead();

    list.PrintList();
    cout << endl;
    cout << "VALUE: \t" << list.ValueExist(4);
    cout << endl;
    return 0;
}