#include<bits/stdc++.h>
using namespace std;

struct Node 
{
	int data; 
	Node* left;
	Node* right;
};

Node* GetNewNode(int data) 
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* Insert(Node* root,int data) 
{
	if(root == NULL)                                      // empty tree
    {                                           
		root = GetNewNode(data);
	}
	
	else if(data <= root->data)                         // if data to be inserted start lesser, insert inorder left subtree. 
    {
		root->left = Insert(root->left,data);
	}
	
	else                                                // else, insert inorder right subtree. 
    {
		root->right = Insert(root->right,data);
	}
	return root;
}

bool find_path(Node* root,int value,vector<pair<Node*,char>> &v,char direction)
{
	if(root==NULL)
	return false;
	v.push_back({root,direction});

	if(root->data==value)
	return true;
	if(find_path(root->left,value,v,'L') || find_path(root->right,value,v,'R'))
	return true;

	v.pop_back();
	return false;
}

int main() 
{
	Node* root = NULL;  			// Creating an empty tree
	root = Insert(root,15);	
	root = Insert(root,10);	
	root = Insert(root,20);
	root = Insert(root,8);
	root = Insert(root,12);
	root = Insert(root,17);
	root = Insert(root,25);

	vector<pair<Node*,char>>v;
    char direction ='-';
	find_path(root,8,v,direction);

	for(int i=0;i<v.size()-1;i++)
	cout<<v[i+1].second<<" ";

}