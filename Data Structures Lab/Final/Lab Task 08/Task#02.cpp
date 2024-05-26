#include<iostream>

using namespace std;

class Node{
	public:
		int data;
		
		Node *left, *right;
		
		Node(int val)
		{
			data = val;
			left = NULL;
			right = NULL;
		}
		
		
};

Node *insertBST(Node *key, int val)
{
	if(key==NULL)
	{
		return new Node(val);
	}
	if(val < key->data)
	{
		key->left = insertBST(key->left, val);
	}
	else
	{
		key->right = insertBST(key->right, val);
	}
	return key;
}

void Display(Node *key)
{
	if(key==NULL)
	{
		return;
	}
	Display(key->left);
	cout << key->data << " ";
	Display(key->right);
	cout << key->data << " ";
}

int main()
{
	Node *key = NULL;
	key = insertBST(key, 15);
	insertBST(key, 10);
	insertBST(key, 20);
	insertBST(key, 8);
	insertBST(key, 12);
	insertBST(key, 16);
	insertBST(key, 25);
	Display(key);
}
