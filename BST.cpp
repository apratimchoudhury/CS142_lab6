//Binary Search Tree

#include <iostream>
using namespace std;

/*

BINARY TREE:

Each node has one data and a maximum of two pointers to connect to its children
The node that does not have any parent is called the root
When the tree is empty the root becomes NULL
A node that does not have any children is called a leaf
Only one directional connection
A tree whose each node has a maximum of two pointers is called a binary tree
path, edge, length of a path, height
A tree is said to be balanced if it has the least possible height. Equivalently, only the last and the penutimate levels are allowed to have less than two children.

BINARY SEARCH TREE:

Everything that is on the left hand side has to be less than the ones on the right hand side

1. Check if current is NULL
2. If NULL, insert there
3. Else move right or left according to the values
4. And the recursion goes on

*/

class Node
{
	public:	
		int data;
		Node *left;
		Node *right;
		Node(int val)
		{
			data=val;
			left=NULL;
			right=NULL;	
		}	
};

class BST
{
	public:
	Node *root;
	BST()
	{
		root=NULL;
	}
	void insert(int value)
	{
		insertHelper(root, value);
	}
	void insertHelper( Node *current,int value)
	{
		
		if(current==NULL) 
		{
			current = new Node(value);
			if(root==NULL)
			{
				root=current;
			}
			
			return;
		}
		else if(current->data>value)
		{
			if(current->left==NULL) current->left=new Node(value);
			else insertHelper(current->left,value);
		}
		else
		{
			if(current->right==NULL) current->right= new Node(value);
			else insertHelper(current->right,value);
		}
	}
	
	void fancyInsert(int value)
	{
		fancyInsertHelp(&root,value);
	}
	
	void fancyInsertHelp(Node **current, int value)
	{
		
	}
	void display()
	{
		display2(root);
		cout<<endl;
	}
	void display2(Node *current)
	{
		//base condition
		if(current==NULL) return;
		//display left
		display2(current->left);
		//display current
		cout<<current->data;
		//display right
		display2(current->right);
	}
	Node * search(int value)
	{
		return search2(root,value);
	}
	
	Node *search2(Node *current,int value)
	{
		if(current->data==value||current==NULL) return current;
		else if(current->data>value)
		{
			return search2(current->left, value);
		}
		else
		{
			return search2(current->right, value);
		}
	}

};

int main()
{
	BST t1;
	t1.insert(3);
	t1.insert(4);
	t1.insert(7);
	t1.insert(2);
	t1.display();
	if(t1.search(3)->data==3) cout<<"Present!"<<endl;
	else cout<<"Absent!"<<endl;
	return 0;
}











