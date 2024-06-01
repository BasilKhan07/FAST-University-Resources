#include<iostream>

using namespace std;

class node{
	public:
		node *left;
		node *right;
		int data;
		node(){
			data = 0;
			left = NULL;
			right = NULL;
		}
		node(int val){
			left = NULL;
			right = NULL;
			data = val;
		}
};

class AVL {
	public:
		node *root;
		AVL(){
			root=NULL;
		}
		node* insertNode(node *&r,node *newnode){
			if(r==NULL){
				r = newnode;
				return r;
			}
			else{
				if(newnode->data < r->data){
					r->left = insertNode(r->left,newnode);
				}else if(newnode->data > r->data){
					r->right = insertNode(r->right,newnode);
				}else{
					cout<<"no duplicates allowed"<<endl;
					return r;
				}
				int bf = GetBalanceFactor(r);
				if(bf>1 && newnode->data < r->left->data){
					return rightRotate(r);
				}
				else if(bf<-1 && newnode->data > r->right->data){
					return leftRotate(r);
				}else if(bf>1 && newnode->data > r->left->data){
					r->left = leftRotate(r->left);
					return rightRotate(r);
				}else if(bf<-1 && newnode->data < r->right->data){
					r->right = rightRotate(r->right);
					return leftRotate(r);
				}
				return r;
			}
		}
		int height(node *n){
			if(n==NULL){
				return -1;
			}
			else{
				int lheight = height(n->left);
				int rheight = height(n->right);
				if(lheight>rheight){
					return lheight+1;
				}else{
					return rheight+1;
				}
			}
		}
		int GetBalanceFactor(node *n){
			if(n==NULL){
				return -1;
			}else{
				return(height(n->left)-height(n->right));
			}
		}
		node* rightRotate(node* y){
			node *x=y->left;
			node *T2 = x->right;
			x->right = y;
			y->left = T2;
			return x;
		}
		node* leftRotate(node* x){
			node* y = x->right;
			node* T2 = y->left;
			y->left = x;
			x->right = T2;
			return y;
		}
		void preorder(node *&r){
			if(r==NULL){
				return;
			}
			cout<<r->data<<" ";
			preorder(r->left);
			preorder(r->right);
		} 
		node* deleteNode(node *&r,int val){
			if(r==NULL){
				return r;
			}
			else{
				if(val < r->data){
					r->left = deleteNode(r->left,val);
				}else if(val > r->data){
					r->right=deleteNode(r->right,val);
				}else{
					if(r->left==NULL){
						node* temp = r->right;
						delete r;
						return temp;
					}else if(r->right==NULL){
						node *temp = r->left;
						delete r;
						return temp;
					}else{
						node* temp = getMinValueNode(r->right);
						r->data = temp->data;
						r->right = deleteNode(r->right,temp->data);
					}
				}
			}
			int bf = GetBalanceFactor(r);
			if(bf == 2 && GetBalanceFactor(r->left) >= 0){
				return rightRotate(r);
			}
			else if(bf == 2 && GetBalanceFactor(r->left) == -1){
				r->left = leftRotate(r->left);
				return rightRotate(r);
			}
			else if(bf==-2 && GetBalanceFactor(r->right)<=0){
				return leftRotate(r);
			}else if(bf==-2 && GetBalanceFactor(r->right) == 1){
				r->right = rightRotate(r->right);
				return leftRotate(r);
			}
			return r;
		}
		node* getMinValueNode(node *r){
			node *temp = r;
			while(temp->left!=NULL){
				temp = temp->left;
			}
			return temp;
		}
};

int main(){
	AVL tree;
	int x;
	for(int i=0;i<4;i++){
		cin>>x;
	node* n = new node(x);
    tree.root = tree.insertNode(tree.root,n);	
	}
	tree.preorder(tree.root);
	tree.root = tree.deleteNode(tree.root,40);
	cout<<endl;
		tree.preorder(tree.root);
}
