#include<iostream>
#define SPACE 10

using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node()
        {
            data = 0;
            left = NULL;
            right = NULL;
        }

        Node(int val)
        {
            data = val;
            left = NULL;
            right = NULL;
        }
};

class BST{
    public:
        Node *root;

        BST()
        {
            root = NULL;
        }

        bool IsEmpty()
        {
            if(root==NULL)
            {
                return true;
            }
            return false;
        }

        void Insert(Node *n)
        {
            if(root == NULL)
            {
                root = n;
                cout << "Value inserted at root." << endl;
            }
            else
            {
                Node *temp = root;
                while(temp!=NULL)
                {
                    if(n->data == temp->data)
                    {
                        cout << "Value already exist." << endl;
                        return;
                    }
                    else if((n->data < temp->data) && (temp->left == NULL))
                    {
                        temp->left = n;
                        cout << "Value inserted to the left. " << endl;
                        break;
                    }
                    else if(n->data < temp->data)
                    {
                        temp= temp->left;
                    }
                    else if((n->data > temp->data) && (temp->right == NULL))
                    {
                        temp->right = n; 
                        cout << "Value inserted to the right. " << endl;
                        break;
                    }
                    else 
                    {
                        temp= temp->right;
                    }


                }
            }
        }

        void Print(Node *r, int space)
        {
            if(r==NULL)
            {
                return;
            }
            space = space + SPACE;
            Print(r->right, space);
            cout << endl;
            for(int i=SPACE; i<space; i++)
            {
                cout << " ";
            }
            cout << r->data << endl;
            Print(r->left, space);
        }
};

int main()
{
    BST obj;
    int choice, val;
    do
    {
        cout << "Which operation to perform: " << endl;
        cout << "1. Insert Node. " << endl;
        cout << "2. Search Node. " << endl;
        cout << "3. Delete Node. " << endl;
        cout << "4. Print BST Tree. " << endl;
        cout << "5. Clear Screen. " << endl;
        cout << "0. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        Node *new_node = new Node();
        switch(choice)
        {
            case 0:
                {
                    break;
                }
            case 1:
                {
                    cout << "INSERTION: " << endl;
                    cout << "Enter value to insert: ";
                    cin >> val;
                    new_node->data = val;
                    obj.Insert(new_node);
                    break;
                }
            case 2:
                {
                    cout << "SEARCHING: " << endl;
                    break;
                }
            case 3:
                {
                    cout << "DELETION: " << endl;
                    break;
                }
            case 4:
                {
                    cout << "DISPLAY: " << endl;
                    obj.Print(obj.root, 5);
                    break;
                }
            case 5:
                {
                    cout << "CLEAR SCREEN: " << endl;
                    system("cls");
                    break;
                }
            default:
                {
                    cout << "Enter valid choice!" << endl;
                    break;
                }
        }
    } 
    while (choice!=0);
    
}