#include <iostream>
#include <queue>
using namespace std;

class minHeapNode
{
	public:
		char data;
		unsigned freq;
		minHeapNode *left, *right;
		minHeapNode(char data, unsigned freq)
		{
			this->data = data;
			this->freq = freq;
			left = right = NULL;	
		}	
};

class compare
{
	public:
		bool operator()(minHeapNode* l, minHeapNode* r)
		{
			return (l->freq > r->freq);
		}	
};

void printCodes(minHeapNode* root, int arr[], int ar[], int top) 
{ 
	static int j = 0;
	if (root->left) 
	{
        arr[top] = 0;
        printCodes(root->left, arr, ar, top + 1);
    }
  
    if (root->right) 
	{
        arr[top] = 1;
        printCodes(root->right, arr, ar, top + 1);
    }
  
    if (root->data != '0') 
	{
        cout << root->data << ": ";
		for (int i = 0; i < top; ++i)
		{
			cout << arr[i];
			ar[j++] += arr[i];
		}
		cout << endl;
    }
} 

priority_queue<minHeapNode*, vector<minHeapNode*>, compare> HuffmanCode(char *data, int *freq, int size, int ar[])
{
	minHeapNode *left, *right, *top;
	
	priority_queue<minHeapNode*, vector<minHeapNode*>, compare> minHeap; 
	
	for(int i=0; i<size; i++)
		minHeap.push(new minHeapNode(data[i], freq[i]));
		
	while (minHeap.size() != 1) 
	{ 
        left = minHeap.top(); 
        minHeap.pop(); 

        right = minHeap.top(); 
        minHeap.pop(); 

        top = new minHeapNode('0', left->freq + right->freq); 

        top->left = left; 
        top->right = right; 

        minHeap.push(top); 
    } 
	
	string str;
	int arr[100] = {0};
	
	cout << endl << "Huffman Codes: " << endl;
    printCodes(minHeap.top(), arr, ar, 0); 
	
    return minHeap;
}

void HuffmanDecode(minHeapNode* root, int ar[])
{
		static int i = 0;
		if(root->left == NULL)
		{
			cout << root->data;
			return;
		}
			
		if(root->right == NULL)
		{
			cout << root->data;
			return;
		}
			
		if(ar[i++] == 0)
			HuffmanDecode(root->left, ar);
			
		if(ar[i++] == 1)
			HuffmanDecode(root->right, ar);
}

int main() 
{ 
	int size; 
	int* freq = new int [size];
	char *data = new char [size];
	int ar[100] = {0};
	cout << "Enter number of data: ";
	cin >> size;
	
	for(int i=0; i<size; i++)
	{
		cout << "Enter data " << i+1 << ": ";
		cin >> data[i];
		cout << "Enter its frequency: ";
		cin >> freq[i];
	}
	priority_queue<minHeapNode*, vector<minHeapNode*>, compare> pq = HuffmanCode(data, freq, size, ar);
	cout << endl << "Decoded Data: ";
	HuffmanDecode(pq.top(), ar);
	return 0; 
} 

