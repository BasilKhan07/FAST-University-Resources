#include<iostream>
#include<string>

using namespace std;

class Node{
    public:
        string word;
        Node *next;
        Node *prev;

        Node()
        {
            next = NULL;
            prev = NULL;
        }

        Node(string s)
        {
            word = s;
            next = NULL;
            prev = NULL;
        }
};

class UniqueWords{
    public:
        Node *head = new Node;

        UniqueWords()
        {
            head = NULL;
        }

        UniqueWords(string s)
        {
            head->word = s;
            head->next = NULL;
            head->prev = NULL;
        }

        void Insert(string s)
        {
            Node *n = new Node(s);
            Node *temp = head;
            if(head == NULL)
            {
                n->next = head;
                head = n;
                return;
            }
            while(temp->next!=NULL)
            {
                temp = temp->next;
            }
            temp->next = n;
            n->prev = temp;
        }

        void Display()
        {
            Node *temp = head;
            while(temp!=NULL)
            {
                cout << temp->word << endl;
                temp = temp->next;
            }
            cout << endl;
        }

        void removeDuplicateNode() 
        {
            Node *currptr = head;
            Node *nextptr;
            Node *temp;  
            if(head == NULL) 
            {  
                return;  
            }  
            else 
            { 
                while(currptr!=NULL) 
                {  
                    nextptr = currptr->next;
                    while(nextptr!=NULL) 
                    {  
                        if(currptr->word == nextptr->word) 
                        {    
                            temp = nextptr;    
                            nextptr->prev->next = nextptr->next;  
                            if(nextptr->next != NULL)
                            {
                                nextptr->next->prev = nextptr->prev;
                            }   
                            temp = NULL;  
                        }  
                        nextptr = nextptr->next;
                    }
                    currptr = currptr->next;  
                }  
            }  
        }  

        void sorting()
        {
            Node *temp1 = head;
            Node *temp2;
            while(temp1!=NULL)
            {
                temp2 = temp1->next;
                while(temp2!=NULL)
                {
                    if(temp1->word[0] == 'H' || temp1->word[0] == 'I')
                    {
                        temp1->word[0] = temp1->word[0]+32;
                    }
                    if(temp2->word[0] == 'H' || temp2->word[0] == 'I')
                    {
                        temp2->word[0] = temp2->word[0]+32;
                    }
                    if(temp1->word[0]==temp2->word[0])
                    {
                        if(temp1->word[1]>temp2->word[1])
                        {
                            string s = temp2->word;
                            temp2->word = temp1->word;
                            temp1->word = s;
                        }
                    }
                    if(temp1->word[0] > temp2->word[0])
                    {
                        string s = temp2->word;
                        temp2->word = temp1->word;
                        temp1->word = s;
                    }
                    if(temp1->word[0] == 'i' || temp1->word[0] == 'h')
                    {
                        temp1->word[0] = temp1->word[0]-32;
                    }
                    if(temp2->word[0] == 'i' || temp2->word[0] == 'h')
                    {
                        temp2->word[0] = temp2->word[0]-32;
                    }
                    temp2= temp2->next;
                }
                temp1 = temp1->next;
            }
        }
};

int main()
{
    UniqueWords obj;
    string s;
    getline(cin,s);
    string ans = "";
    for(int i=0; i<=s.length(); i++)
    {
        if(s[i]==' ' || i == s.length())
        {
            obj.Insert(ans);
            ans = "";
        }
        else
            ans = ans + s[i];
    }
    obj.removeDuplicateNode();
    obj.Display();
    obj.sorting();
    obj.Display();
    
}