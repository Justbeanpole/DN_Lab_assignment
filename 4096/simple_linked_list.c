#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node {
	int data;
	node* next;
};
node* dataIN(node* header);
void dataOut(node* header);
void dataSearch(node* header);
node* dataDelete(node* header);
int printHead(int*);

int main_simple()
{
	node* header = NULL;
	int input = 0;
	int stop = 1;
	while (stop)
	{
		switch (printHead(input))
		{
		case 1:
		{
			header = dataIN(header);
			break;
		}
		case 2:
		{
			dataOut(header);
			break;
		}
		case 3:
		{
			dataSearch(header);
			break;
		}
		case 4:
		{
			header = dataDelete(header);
			break;
		}
		case 5:
		{
			stop = 0;
			break;
		}
		default:
			printf("1 ~ 5�� ���ڸ� �Է��ϼ���\n");
			break;
		}
	}
	return 0;
}
int printHead(int input)
{
	printf("----------------------------------\n");
	printf("1.�Է� 2.��� 3.�˻� 4.���� 5.����\n");
	printf("----------------------------------\n");
	printf("������ ���α׷� ��ȣ�� �Է��ϼ��� : ");
	scanf_s("%d", &input);
	printf("\n");
	return input;
}

node* dataIN(node* header)
{
	int inputData;
	printf("�����Ͱ��� �Է��ϼ��� : ");
	scanf_s("%d", &inputData);
	node* n = (node*)malloc(sizeof(node));
	n->data = inputData;
	n->next = NULL;
	node* cur = header;

	if (header == NULL)
	{
		header = n;
	}
	else
	{
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = n;
	}
	return header;
}

void dataOut(node* header)
{
	node* cur = header;
	if (cur == NULL)
	{
		printf("��°��� �����ϴ�.\n");
	}
	else
	{
		while (cur)
		{
			printf("%d\t", cur->data);
			cur = cur->next;
		}
		printf("\n");
	}
}

void dataSearch(node* header)
{
	int searchData;
	printf("ã�� ������ ���� �Է��ϼ���: ");
	scanf_s("%d", &searchData);
	printf("\n");
	node* cur = header;
	int ans;
	if (cur == NULL)
	{
		printf("�˻��� �����Ͱ� �����ϴ�.\n");
	}
	else
	{
		while (cur)
		{
			if (cur->data == searchData)
			{
				ans = 1;
				break;
			}
			else
			{
				ans = 0;
				cur = cur->next;
			}
		}
		if (ans == 1)
		{
			printf("%d : (O)\n", searchData);
		}
		else
		{
			printf("%d : (X)\n", searchData);
		}
	}
}
node* dataDelete(node* header)
{
	int deleteData;
	printf("������ ������ ���� �Է��ϼ���: ");
	scanf_s("%d", &deleteData);
	node* cur = header;
	node* temp = header;
	int ans = 0;
	while (cur)
	{
		if (cur->data == deleteData)
		{
			ans = 1;
			break;
		}
		else
		{
			cur = cur->next;
		}
	}
	if (ans == 1)
	{
		while (temp)
		{
			if (temp->next == cur)
			{
				break;
			}
			else if (temp == cur)
			{
				if (temp->next == NULL)
				{
					free(header);
					header = NULL;
					break;
				}
				else
				{
					header = temp->next;
					break;
				}
			}
			else
			{
				temp = temp->next;
			}
		}
		if (header != NULL)
		{
			temp->next = cur->next;
			free(cur);
			printf("�����Ǿ����ϴ�.\n");
		}
	}
	else
	{
		printf("���� �����ϴ�\n");
	}
	return header;
}
