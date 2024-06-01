#include<iostream>
#define SPACE 5

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
            right - NULL;
        }
};

class BST{
    public:
        Node *root;

        BST()
        {
            root = NULL;
        }

        Node* Insert(Node *temp, int val)
        {
            if(temp==NULL)
            {
                temp = new Node;
                temp->data = val;
                temp->left = NULL;
                temp->right = NULL;
            }
            else if(val < temp->data)
            {
                temp->left = Insert(temp->left, val);
            }
            else if(val > temp->data)
            {
                temp->right = Insert(temp->right, val);
            }
            return temp;
        }

        void InOrder(Node *temp)
        {
            if(temp == NULL)
            {
                return;
            }
            InOrder(temp->left);
            cout << temp->data << " ";
            InOrder(temp->right);
        }

        void PreOrder(Node *temp)
        {
            if(temp==NULL)
            {
                return;
            }
            cout << temp->data << " ";
            PreOrder(temp->left);
            PreOrder(temp->right);
        }

        void PostOrder(Node *temp)
        {
            if(temp==NULL)
            {
                return;
            }
            PreOrder(temp->left);
            PreOrder(temp->right);
            cout << temp->data << " ";
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
    obj.root = obj.Insert(obj.root, 4);
    obj.Insert(obj.root, 2);
    obj.Insert(obj.root, 1);
    obj.Insert(obj.root, 4);
    obj.Insert(obj.root, 3);
    obj.Insert(obj.root, 38);
    obj.Print(obj.root, 5);
    obj.InOrder(obj.root);
    cout << endl;
    obj.PreOrder(obj.root);
    cout << endl;
    obj.PostOrder(obj.root);
}