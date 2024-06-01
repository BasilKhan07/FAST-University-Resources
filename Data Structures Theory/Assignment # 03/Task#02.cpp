#include<iostream>
#include<string>

using namespace std;

class ListNode{
    public:
        string Term;
        ListNode *next;

        ListNode()
        {
            Term = " ";
            next = NULL;
        }

        ListNode(string val)
        {
            Term = val;
            next = NULL;
        }
};

class TreeNode{
    public:
        string data;
        TreeNode *left;
        TreeNode *right;
        
        TreeNode()
        {
            data = "";
            left = NULL;
            right = NULL;
        }

        TreeNode(string val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};

class LinkedList{
    public:
        ListNode *head;

        LinkedList()
        {
            head = NULL;
        }

        void InsertNode(string val)
        {
            ListNode *n = new ListNode(val);
            if(head == NULL)
            {
                head = n;
                return;
            }
            else
            {
                ListNode *temp = head;
                while(temp->next!=NULL)
                {
                    temp = temp->next;
                }
                temp->next = n;
            }
        }

};

void IndexGenerator(string val, LinkedList *obj, int val2)
{
    ListNode *temp = obj->head;
    string *arr;
    arr = new string[val2];
    for(int j=0; j<val2; j++)
    {
        int i = 0;
        while(temp->Term[i] != ' ')
        {
            arr[j] = arr[j] + temp->Term[i];
            i++; 
        }
        temp = temp->next;
    }
    temp = obj->head;
    for(int i=0; i<val2; i++)
    {
        if (std::string::npos != temp->Term.find(val))
        {
            cout << arr[i] << " ";
        }
        temp = temp->next;
    }
    cout << endl;
}

class BST{
    public:
        TreeNode *root;

        BST()
        {
            root = NULL;
        }

        void InsertData(string val)
        {
            TreeNode *n = new TreeNode(val);
            if(root == NULL)
            {
                root = n;
            }
            else
            {
                TreeNode *temp = root;
                while(temp!=NULL)
                {
                    if((n->data < temp->data) && (temp->left == NULL))
                    {
                        temp->left = n;
                        break;
                    }
                    else if(n->data < temp->data)
                    {
                        temp = temp->left;
                    }
                    else if((n->data > temp->data) && (temp->right == NULL))
                    {
                        temp->right = n;
                        break;
                    }
                    else
                    {
                        temp = temp->right;
                    }
                }
            }
        }

        void Display(TreeNode *temp1, LinkedList *obj, int val2)
        {
            if(temp1==NULL)
            {
                return;
            }
            Display(temp1->left, obj, val2);
            cout << temp1->data << " ";
            IndexGenerator(temp1->data, obj, val2);
            Display(temp1->right, obj, val2);
        }
};

int main()
{
    BST obj1;
    int NumOfTermonoligies;
    cin >> NumOfTermonoligies;
    char c = cin.get();
    string Termonoligies;
    for(int i=0; i<NumOfTermonoligies; i++)
    {
        fflush(stdin);
        getline(cin, Termonoligies);
        fflush(stdin);
        obj1.InsertData(Termonoligies);
    }
    LinkedList obj2;
    int NumOfLines;
    cin >> NumOfLines;
    c = cin.get();
    string *arr;
    arr = new string[NumOfLines];
    for(int i=0; i<NumOfLines; i++)
    {
        fflush(stdin);
        getline(cin, arr[i]);
        fflush(stdin);
        obj2.InsertNode(arr[i]);
    }
    obj1.Display(obj1.root, &obj2, NumOfLines);
}