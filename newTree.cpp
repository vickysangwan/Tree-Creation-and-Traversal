#include<stdlib.h>
#include<stdio.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node* create()
{
	struct node* root;
	root=NULL;
	int size,i;
	printf("Enter size of tree\n");
	scanf("%d",&size);
	for(i=0;i<size;i++)
	{
		int data;
		printf("Enter data in data\n");
		scanf("%d",&data);
		struct node* temp;
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=data;
		temp->left=NULL;
		temp->right=NULL;
		if(root==NULL)
		{
			root=temp;
		}
		else
		{
			struct node* curr,*ptr;
			curr=root;
			while(curr)
			{
				ptr=curr;
				if(temp->data > curr->data)
				{
					curr=curr->right;
				}
				else
				{
					curr=curr->left;
				}
			}
			if(temp->data > ptr->data)
			{
				ptr->right=temp;
			}
			else
			{
				ptr->left=temp;
			}
		}
	}
	return root;	
}
void inorder(struct node* root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}
void preorder(struct node* root)
{
	if(root==NULL)
	{
		return;
	}
	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct node* root)
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->data);
}
int main()
{
	struct node* root;
	root=create();
	printf("In-Order\n");
	inorder(root);
	printf("\nPre-Order\n");
	preorder(root);
	printf("\nPost-Order\n");
	postorder(root);
	return 0; 
}
