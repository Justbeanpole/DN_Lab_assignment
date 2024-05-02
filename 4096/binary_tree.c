#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node {
	int data;
	node* left;
	node* right;
};
node* createNode(node* head);

int main()
{
	node* head = NULL;
	int input = 0;
	int stop = 1;
	while (stop)
	{
		input = printHead(input);
		if (input == 1)
		{
			head = createNode(head);
		}
		else if (input == 2)
		{

		}
		else if (input == 3)
		{

		}
		else if (input == 4)
		{

		}
		else if (input == 5)
		{

		}
		else
		{
			printf("1 ~ 5의 숫자를 입력하세요\n");
		}
	}
	return 0;
}

node* createNode(node* head)
{
	int inputData;
	printf("데이터값을 입력하세요 : ");
	scanf_s("%d", &inputData);
	node* n = (node*)malloc(sizeof(node));
	n->data = inputData;
	n->left = NULL;
	n->right = NULL;

	node* cur = head;
	if (head == NULL)
	{
		head = n;
	}
	else
	{
		while (cur->left != NULL || cur->right != NULL)
		{
			if (cur->data <= n->data)
			{
				cur = cur->right;
			}
			else
			{
				cur = cur->left;
			}
		}
		if (cur->data <= n->data)
		{
			cur->right = n;
		}
		else
		{
			cur->left = n;
		}
	}
	return head;
}

void printNode(node* head)
{
	node* cur = head;
	while (cur->left != NULL && cur->right != NULL)
	{
		print(cur->data);
		if (cur->left != NULL)
		{
			cur = cur->left;
		}  
	}
}