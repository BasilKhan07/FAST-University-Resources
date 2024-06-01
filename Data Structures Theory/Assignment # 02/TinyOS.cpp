#include<iostream>

using namespace std;

class Node{
    public:
        string ID;
        int time_req;
        int quota;
        Node *next;

        Node()
        {
            next = NULL;
        }

        Node(string s, int t, int q)
        {
            ID = s;
            time_req = t;
            quota = q;
            next = NULL;
        }
};

class TinyOS{
    public:
        Node *head = new Node;

        TinyOS()
        {
            head = NULL;
        }

        TinyOS(string s, int t, int q)
        {
            head->ID = s;
            head->time_req = t;
            head->quota = q;
            head->next = head;
        }

        void Insert(string s, int t, int q)
        {
            Node *n = new Node(s, t, q);
            Node *temp = head;
            if(head==NULL)
            {
                head = n;
                head->next = head;
                return;
            }

            while(temp->next!=head)
            {
                temp = temp->next;
            }
            temp->next = n;
            n->next = head;
        }

        bool check()
        {
            if(head==NULL)
            {
                return true;
            }
            // For checking total time
            int total;
            Node *temp = head;
            do
            {
                total = total + temp->time_req;
                temp = temp->next;
            }
            while(temp!=head); // because of cicular linked list

            if(total == 0) // Checking
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        void Process()
        {
            Node *temp = head;
            while(true)
            {
                if(check())
                {
                    break;
                }
                if(temp->time_req!=0)
                {
                    cout << endl;
                    cout << temp->ID;
                    temp->time_req = temp->time_req - temp->quota;
                }
                temp = temp->next;
            }
        }
};

int main()
{
    TinyOS obj;
    int NoOFProcess;
    cin >> NoOFProcess;
    string s;
    int t, q;
    for(int i=0; i<NoOFProcess; i++)
    {
        cin >> s >> t >> q;
        obj.Insert(s, t, q);
    }
    obj.Process();
}