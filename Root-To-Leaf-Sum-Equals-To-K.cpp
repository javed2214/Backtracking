// Program to Print All the Paths from Root to Leaf with a Specified Sum in Binary Tree

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;


node *createNode(int x){

	node *temp = (node *)malloc(sizeof(node));
	temp->left = NULL;
	temp->right = NULL;
	temp->data = x;

	return temp;		
}


void printPaths(vector<int>v){
	for(auto it:v) cout << it << " ";
		cout << "\n";
}

void getPaths(node *root, vector<int> &v, int target, int sum){

	if(root == NULL) return;
	
	v.push_back(root->data);

	sum += root->data;
	
	if(sum == target and root->left == NULL and root->right == NULL)
		printPaths(v);

	getPaths(root->left,v,target,sum);
	getPaths(root->right,v,target,sum);
	
	v.pop_back();
}

int main(){

	node *root = createNode(2);
	root->left = createNode(7);
	root->right = createNode(4);
	root->left->left = createNode(6);
	root->left->right = createNode(8);
	root->right->left = createNode(9);
	root->right->right = createNode(1);

	int target = 17;
	
	vector<int> v;
	
	getPaths(root, v, target, 0);

	return 0;
}
