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
        
        bool Search(int val1, int val2, int val3)
        {
        	int arr[3]={val1, val2, val3};
        	for(int i=0; i<3; i++)
        	{
        		Node *current = root;
        		while(current->data!=arr[i])
        		{
					if(current->data > arr[i])
					{
						current = current->left;
					}
					else
					{
						current = current->right;
					}
					if(current==NULL)
					{
						return false;
					}
				}
			}
			return true;
		}
		
		Node* min(Node *n)
		{
			Node *temp = n;
			while(temp && temp->left!=NULL)
			{
				temp = temp->left;
			}
			return temp;
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
        
        Node* Balancing(Node *r)
        {
        	int balance_factor = Balance(r);
            if(balance_factor > 1 && r->data < r->left->data)
            {
                return rightRotate(r);
            }
            if(balance_factor < -1 && r->data > r->right->data)
            {
                return leftRotate(r);
            }
            if(balance_factor > 1 && r->data > r->left->data)
            {
                r->left = leftRotate(r->left);
                return rightRotate(r);
            }
            if(balance_factor < -1 && r->data < r->right->data)
            {
                r->right = rightRotate(r->right);
                return leftRotate(r);
            }
            return r;
		}
        
        Node* Delete(Node *root, int val)
        {
        	if(root == NULL)
        	{
        		return root;
			}
			if(val < root->data)
			{
				root->left = Delete(root->left, val);
			}
			else if(val > root->data)
			{
				root->right = Delete(root->right, val);
			}
			else
			{
				if(root->left == NULL || root->right == NULL)
				{
					return NULL;
				}
				else if(root->left == NULL)
				{
					Node *temp = root->right;
					delete root;
					return temp;
				}
				else if(root->right == NULL)
				{
					Node *temp = root->left;
					delete root;
				}
				Node *temp = min(root->right);
				
				root->data = temp->data;
				root->right = Delete(root->right, temp->data);
			}
			return root;
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
    int val;
    int arr[11] = { 55, 66, 77, 11, 33, 22, 35, 25, 44, 88, 99};
    for(int i=0; i<11; i++)
    {
        Node *n = new Node();
        n->data = arr[i];
        obj.root = obj.Insert(obj.root, n);
    }
    obj.Display(obj.root, 11);
    cout << endl << "Height of tree: " << obj.Height(obj.root) << endl << endl;
    cout << "Searching: " << endl << endl;
    if(obj.Search(66, 22, 44))
    {
    	cout << "All values exist in tree." << endl;
	}
	else
	{
		cout << "All values dont exist in tree." << endl;
	}
    cout << endl << endl;
    cout << "Deletion: " << endl << endl;
    cout << "Deletion of 35: " << endl;
	obj.root = obj.Delete(obj.root, 35);
	obj.root = obj.Balancing(obj.root);
	cout << endl << "Height of tree: " << obj.Height(obj.root) << endl;
	obj.Display(obj.root, 10);
    cout << "Deletion of 99: " << endl;
	obj.root = obj.Delete(obj.root, 99);
	obj.root = obj.Balancing(obj.root);
	cout << endl << "Height of tree: " << obj.Height(obj.root) << endl;
	obj.Display(obj.root, 9);
}
