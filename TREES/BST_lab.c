/*
18)	WAP to create a BST (binary search tree) and perform all following operations:
a.	Insert an element
b.	Preorder traversal
c.	Inorder traversal
d.	Postorder traversal
e.	Find smallest element
f.	Find largest element
g.	Delete an element
h.	Count the total number of nodes
i.	Exit
*/
#include<stdio.h>
#include<stdlib.h>

struct BinarySearchTreeNode{
	int data;
	struct BinarySearchTreeNode *left;
	struct BinarySearchTreeNode *right;
};
struct BinarySearchTreeNode* insert(struct BinarySearchTreeNode *root, int value){
	if(root==NULL)
	{
		root=(struct BinarySearchTreeNode*)malloc(sizeof(struct BinarySearchTreeNode));
		if(root == NULL)
		{
			printf("Memory Error\n");
			return NULL;
		}
		else{
			root->data=value;
			root->left=root->right=NULL;
		}
	}
	else
	{
		if(value <root->data)
		{
			root->left=insert(root->left,value);
		}
		else if(value > root->data)
		{
			root->right=insert(root->right,value);
		}
	}
	return root;
}

struct BinarySearchTreeNode* find(struct BinarySearchTreeNode *root,int data)
{
	if(root==NULL)
		return NULL;
	if(data < root->data)
		return find(root->left,data);
	else if(data > root->data)
		return find(root->right,data);
	return root;
}

void preorder(struct BinarySearchTreeNode *root)
{
   if(root)
   {
   	printf("%d ",root->data);
   	preorder(root->left);
   	preorder(root->right);
   }
}

void inorder(struct BinarySearchTreeNode *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void postorder(struct BinarySearchTreeNode *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}




struct BinarySearchTreeNode* min(struct BinarySearchTreeNode *root)
{
	if (root==NULL)
		return NULL;
	else if(root->left==NULL)
		return root;
	else
		return min(root->left);
}
struct BinarySearchTreeNode* max(struct BinarySearchTreeNode *root)
{
	if(root==NULL)
		return NULL;
	else if(root->right==NULL)
		return root;
	else
		return max(root->right);
}
int no_of_nodes(struct BinarySearchTreeNode *root)
{
	static int count=0;
	if(root)
	{
		count++;
		no_of_nodes(root->left);
		no_of_nodes(root->right);
	}
	return count;
}

int main()
{
	struct BinarySearchTreeNode *root=NULL;
	root=insert(root,10);
	insert(root,20);
	insert(root,30);
	insert(root,5);
	insert(root,3);
	insert(root,2);
	insert(root,1);
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	printf("MAX ELEMENT IS %d",max(root)->data);
	printf("\n");
	printf("MIN ELEMENT IS %d",min(root)->data);
	printf("\n");
	printf("NUMBER OF NODES IS %d",no_of_nodes(root));
}