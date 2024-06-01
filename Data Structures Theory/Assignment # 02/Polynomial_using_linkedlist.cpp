#include<iostream>
#include<conio.h>

using namespace std;

class Node{
    public:
        int coeff;
        int  exp;
        char variable;
        Node *next;

        Node()
        {
            coeff = 0;
            exp = 0;
            variable = NULL;
            next = NULL;
        }   

        Node(int val1, char var, int val2)
        {
            coeff = val1;
            variable = var;
            exp = val2;
            next = NULL;
        }
};

class Polynomial{
    public:
        Node *head = new Node;
        int count;

        Polynomial()
        {
            head = NULL;
        }

        Polynomial(int val1, char var, int val2)
        {
            head->coeff = val1;
            head->variable = var;
            head->exp = val2;
            head->next = NULL;
        }
    
        void insert(int val1, char var, int val2)
        {
            Node *n = new Node(val1, var, val2);
            if(head == NULL || val2 > head->exp || var == 'Y')
            {
                n->next = head;
                head = n;
                return;
            }
            Node *temp = head;
            while(temp->next!=NULL && temp->next->exp >= val2)
            {
                temp = temp->next; 
            }
            n->next = temp->next;
            temp->next = n;
        }

        void Display()
        {
            count = 0;
            Node *temp = head;
            while(temp!=NULL)
            {
                count++;
                temp = temp->next;
            }
            cout << count << endl;
            temp = head;
            while(temp!=NULL)
            {
                cout << temp->coeff << " " << temp->variable << " " << temp->exp << endl;
                temp = temp->next;
            }
        }

        void reverse()
        {
            Node *prevptr = NULL;
            Node *currptr = head;
            Node *nextptr;
            Node *n = new Node;
            while(currptr!=NULL)
            {
                nextptr = currptr->next;
                currptr->next = prevptr;
                prevptr = currptr;
                currptr = nextptr;
            }
            this->head = prevptr;
        }

        void Addition(Polynomial obj1, Polynomial obj2)
        {
            Node *n = new Node;
            Node *temp1 = obj1.head;
            Node *temp2 = obj2.head;
            while (temp1 != NULL && temp2 != NULL)
            {
                if((temp1->exp == temp2->exp) && (temp1->variable == temp2->variable))
                {
                    this->insert(temp1->coeff+temp2->coeff, temp1->variable, temp1->exp);
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                }
                else if(temp1->exp > temp2->exp)
                {
                    this->insert(temp1->coeff, temp1->variable, temp1->exp);
                    temp1 = temp1->next;
                }
                else if(temp2->exp > temp1->exp)
                {
                    this->insert(temp2->coeff, temp2->variable, temp2->exp);
                    temp2 = temp2->next;
                }
                else if(temp1->variable == 'Y')
                {
                    this->insert(temp1->coeff, temp1->variable, temp1->exp);
                    temp1 = temp1->next;
                }
                else if(temp2->variable == 'Y')
                {
                    this->insert(temp2->coeff, temp2->variable, temp2->exp);
                    temp2 = temp2->next;
                }
            }
            while(temp1!=NULL)
            {
                this->insert(temp1->coeff, temp1->variable, temp1->exp);
                temp1 = temp1->next;
            }
            while(temp2!=NULL)
            {
                this->insert(temp2->coeff, temp2->variable, temp2->exp);
                temp2 = temp2->next;
            }
            this->reverse();
        }
};

int main()
{
    int numofterms, num1, num2;
    char var;
    cin >> numofterms;
    Polynomial obj1;
    for(int i=0; i<numofterms; i++)
    {
        cin >> num1 >> var >> num2;
        obj1.insert(num1, var, num2);
    }
    cin >> numofterms;
    Polynomial obj2;
    for(int i=0; i<numofterms; i++)
    {
        cin >> num1 >> var >> num2;
        obj2.insert(num1, var, num2);
    }
    Polynomial obj3;
    obj3.Addition(obj1, obj2);
    cout << endl;
    obj3.Display();
}