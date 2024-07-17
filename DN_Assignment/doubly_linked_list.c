#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node {
	int data;
	node* next;
	node* prev;
};

void dataOut_d(node* header);
void dataSearch_d(node* header);
node* dataDelete_d(node* header);
node* dataIN_d(node* header, node*tail);
node* createTail(node* header, node* tail);


int main_doubly()
{
	node*header = NULL;
	node*tail = NULL;
	int input = 0;
	int stop = 1;
	while (stop)
	{
		switch (printHead(input))
		{
		case 1:
		{
			header = dataIN_d(header, tail);
			tail = createTail(header, tail);
			break;
		}
		case 2:
		{
			dataOut_d(header, tail);
			break;
		}
		case 3:
		{
			dataSearch_d(header);
			break;
		}
		case 4:
		{
			header = dataDelete_d(header);
			tail = createTail(header, tail);
			break;
		}
		case 5:
		{
			stop = 0;
			break;
		}
		default:
			printf("1 ~ 5의 숫자를 입력하세요\n");
			break;
		}
	}
	return 0;
}

node* dataIN_d(node* header, node*tail)
{
	int inputData;
	printf("데이터값을 입력하세요 : ");
	scanf_s("%d", &inputData);
	node* n = (node*)malloc(sizeof(node));
	n->data = inputData;
	n->next = NULL;
	n->prev = NULL;
	node* cur = header;
	if (header == NULL)
	{
		header = n;
		header->prev = NULL;
	}
	else
	{
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = n;
		n->prev = cur;
	}
	return header;
}
node* createTail(node* header, node* tail)
{
	node* cur = header;
	if (tail == NULL || header == NULL)
	{
		tail = header;
	}
	else
	{
		while (cur->next)
		{
			cur = cur->next;
		}
		tail = cur;
	}
	return tail;
}

void dataOut_d(node* header, node*tail)
{
	node* cur = header;
	if (cur == NULL)
	{
		printf("출력값이 없습니다.\n");
	}
	else
	{
		while (cur)
		{
			printf("%d\t", cur->data);
			cur = cur->next;
		}
		printf("\n\n");
		while (cur)
		{
			printf("%d\t", cur->data);
			cur = cur->prev;
		}
		printf("\n");
	}
}

void dataSearch_d(node* header)
{
	int searchData;
	printf("찾을 데이터 값을 입력하세요: ");
	scanf_s("%d", &searchData);
	printf("\n");
	node* cur = header;
	int ans;
	if (cur == NULL)
	{
		printf("검색할 데이터가 없습니다.\n");
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
node* dataDelete_d(node* header)
{
	int deleteData;
	printf("삭제할 데이터 값을 입력하세요: ");
	scanf_s("%d", &deleteData);
	node* cur = header;
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
		if (cur->next == NULL)
		{
			if (cur->prev == NULL)
			{
				header = NULL;
			}
			else
			{
				cur->prev->next = NULL;
			}
		}
		else
		{
			if (cur->prev == NULL)
			{
				header = cur->next;
				header->prev = NULL;
			}
			else
			{
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
			}
		}
		free(cur);
	}
	else
	{
		printf("값이 없습니다\n");
	}
	return header;
}