#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct node
{
	int data;
	node * right;
	node *left;
};
//struct node *root=NULL;
struct node *insert(node *root)
{
	if(root==NULL)
	{
		int info;
		cout<<"ENTER THE DATA\n";
		cin>>info;
		node *temp;
		temp=(node*)malloc(sizeof(node));
		temp->data=info;
		temp=root;
	}
	else
	{
		node *temp;
		temp=root;
		int info;
		cout<<"ENTER THE DATA\n";
		cin>>info;
		if(info<root->data)
		{
			if(root->left==NULL)
			{
				temp=(node*)malloc(sizeof(node));
				temp=root->left;
				temp->data=info;
			}
			else{
				insert(root->left);
			}
		}
		if(info>root->data)
		{
			if(root->right==NULL)
			{
				temp=(node*)malloc(sizeof(node));
				temp=root->right;
				temp->data=info;
			}
			else{
				insert(root->right);
			}		
			}
		}
		
	return 0;
}
struct node *inorder(struct node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data;
		inorder(root->right);
	}
}
int main()
{
	struct node *root=NULL;
	int i=1;
	int ch=1;
	while(ch!=0)
	{
		cout<<"ENTER YOUR CHOICE \n1.INSERT \n2.TRAVERSE \n0.EXIT\n";
		cin>>ch;
		switch(ch)
		{
			case 1:{
				insert(root);
				break;
			}
			case 2:{
				inorder(root);
			}
			case 0:{
				break;
			}

		}
	}
	return 0;
}