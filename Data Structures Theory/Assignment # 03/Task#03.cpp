#include<iostream>
#define INT_MAX 2147483647
#define INT_MIN (-2147483647 - 1)

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

        void InsertData(Node *n)
        {
            if(root == NULL)
            {
                root = n;
            }
            else
            {
                Node *temp = root;
                while(temp!=NULL)
                {
                    if(n->data == temp->data)
                    {
                        return;
                    }
                    else if((n->data < temp->data) && (temp->left == NULL))
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

        int GetHeight(Node *n)
        {
            if(n==NULL)
            {
                return -1;
            }
            int L_height = GetHeight(n->left);
            int R_height = GetHeight(n->right);

            if(L_height > R_height)
            {
                return L_height+1;
            }
            else
            {
                return R_height+1;
            }
        }

        void GetLevel(Node *n, int l, int &Min, int &Max)
        {
            if(l == 0)
            {
                if(n->data < Min)
                {
                    Min = n->data;
                }
                if(n->data > Max)
                {
                    Max = n->data;
                }
            }
            else
            {
                GetLevel(n->left, l-1, Min, Max);
                GetLevel(n->right, l-1, Min, Max);
            }
        }

        void LevelWiseMinMax(Node *n)
        {
            int height = GetHeight(n);
            for(int i=0; i<=height; i++)
            {
                int Min = INT_MAX;
                int Max = INT_MIN;
                GetLevel(n, i, Min, Max);
                cout << Min << " " << Max << endl;
            }
        }
};

int main()
{
    BST obj;
    int N, val;
    cin >> N;
    
    for(int i=0; i<N; i++)
    {
        cin >> val;
        Node *new_node = new Node();
        new_node->data = val;
        obj.InsertData(new_node);
    }
    cout << endl;
    obj.LevelWiseMinMax(obj.root);
}