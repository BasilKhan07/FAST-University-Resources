#include<iostream>
#define SPACE 11

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

class AVL{
    public:
        Node *root;

        AVL()
        {
            root = NULL;
        }
        
        int Height(Node *n)
        {
            if(n==NULL)
            {
                return -1;
            }
            else
            {
                int Lheight = Height(n->left);
                int Rheight = Height(n->right);
                if(Lheight>Rheight)
                {
                    return (Lheight+1);
                }
                else
                {
                    return (Rheight+1);
                }
            }
        }

        int Balance(Node *n)
        {
            if(n == NULL)
            {
                return -1;
            }
            return Height(n->left) - Height(n->right);
        }

        Node *leftRotate(Node *n)
        {
            Node *n1 = n->right;
            Node *n2 = n1->left;
            
            n1->left = n;
            n->right = n2; 

            return n1;
        }

        Node *rightRotate(Node *n)
        {
            Node *n1 = n->left;
            Node *n2 = n1->right;

            n1->right = n;
            n->left = n2;

            return n1;
        }

        Node* Insert(Node *r, Node *n)
        {
            if (r == NULL)
            {
                r = n;
                cout << "Value inserted." << endl;
                return r;
            }
            if(n->data < r->data)
            {
                r->left = Insert(r->left, n);
            }
            else if(n->data > r->data)
            {
                r->right = Insert(r->right, n);
            }
            else
            {
                cout << "Value already exist. " << endl;
                return r;
            }
            int balance_factor = Balance(r);
            if(balance_factor > 1 && n->data < r->left->data)
            {
                return rightRotate(r);
            }
            if(balance_factor < -1 && n->data > r->right->data)
            {
                return leftRotate(r);
            }
            if(balance_factor > 1 && n->data > r->left->data)
            {
                r->left = leftRotate(r->left);
                return rightRotate(r);
            }
            if(balance_factor < -1 && n->data < r->right->data)
            {
                r->right = rightRotate(r->right);
                return leftRotate(r);
            }
            return r;
        }

        void Display(Node *r, int space)
        {
            if(r==NULL)
            {
                return;
            }
            space = space + SPACE;
            Display(r->right, space);
            cout << endl;
            for(int i=SPACE; i<space; i++)
            {
                cout << " ";
            }
            cout << r->data << endl;
            Display(r->left, space);
        }
};

int main()
{
    AVL obj;
    int arr[11] = { 55, 66, 77, 11, 33, 22, 35, 25, 44, 88, 99};
    for(int i=0; i<SPACE; i++)
    {
        Node *n = new Node();
        n->data = arr[i];
        obj.root = obj.Insert(obj.root, n);
    }
    obj.Display(obj.root, 11);
    cout << endl << "Height of tree: " << obj.Height(obj.root);
}
