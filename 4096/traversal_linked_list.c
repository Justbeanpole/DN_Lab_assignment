#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node {
	int data;
	node* next;
};
node* dataIN_t(node* header);
void dataOut_t(node* header);
void dataSearch_t(node* header);
node* dataDelete_t(node* header);

int main_traversal()
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
			header = dataIN_t(header);
			break;
		}
		case 2:
		{
			dataOut_t(header);
			break;
		}
		case 3:
		{
			dataSearch_t(header);
			break;
		}
		case 4:
		{
			header = dataDelete_t(header);
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
node* dataIN_t(node* header)
{
	int inputData;
	printf("데이터값을 입력하세요 : ");
	scanf_s("%d", &inputData);
	node* n = (node*)malloc(sizeof(node));
	n->data = inputData;
	n->next = header;
	node* cur = header;

	if (header == NULL)
	{
		header = n;
		header->next = header;
	}
	else
	{
		while (cur->next)
		{
			if (cur->next == header)
			{
				break;
			}
			cur = cur->next;
		}
		cur->next = n;
	}
	return header;
}

void dataOut_t(node* header)
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
			if (cur == header)
			{
				break;
			}
		}
		printf("\n");
	}
}

void dataSearch_t(node* header)
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
				if (cur == header)
				{
					break;
				}
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

node* dataDelete_t(node* header)
{
	int deleteData;
	printf("삭제할 데이터 값을 입력하세요: ");
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
			if (cur->next == header)
			{
				break;
			}
			cur = cur->next;
		}
	}
	if (ans == 1)
	{
		while (temp)
		{
			if (temp == cur)
			{
				if (temp->next == header)
				{
					free(header);
					header = NULL;
					printf("삭제되었습니다.\n");
					break;
				}
				else
				{
					while (1)
					{
						if (temp->next == header)
						{
							header = cur->next;
							/*temp->next = header;*/
							break;
						}
						temp = temp->next;
					}
					break;
				}
			}
			else if (temp->next == cur)
			{
				break;
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
			printf("삭제되었습니다.\n");
		}
	}
	else
	{
		printf("값이 없습니다\n");
	}
	return header;
}