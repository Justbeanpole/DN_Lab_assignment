#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node {
	int data;
	node* left;
	node* right;
};
node* createNode(node* head);
void preorderTraversal(node* head);
void inorderTraversal(node*);
void postorderTraversal(node*);
node* backTracking(node*, node*);
void searchNode(node*);
node* deleteNode(node*);

int main()
{
	node* head = NULL;
	int input = 0;
	int stop = 1;
	while (stop)
	{
		printf("----------------------------------\n");
		printf("1.입력 2.출력 3.검색 4.삭제 5.종료\n");
		printf("----------------------------------\n");
		printf("원하는 번호를 선택하세요 : ");
		scanf_s("%d", &input);
		if (input == 1)
		{
			head = createNode(head);
		}
		else if (input == 2)
		{
			preorderTraversal(head); printf("\n");
		}
		else if (input == 3)
		{
			searchNode(head);
		}
		else if (input == 4)
		{
			//삭제
			head = deleteNode(head);
		}
		else if (input == 5)
		{
			//종료
			stop = 0;
			printf("종료합니다.\n");
		}
		else
		{
			printf("1 ~ 5번 중 하나를 골라주세요.\n");
		}
	}
	return 0;
}

node* createNode(node* head)
{
	int inputData;
	printf("데이터 값을 입력하세요 : ");
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
	else {
		while (1)
		{
			if (cur->data < n->data)
			{
				if (cur->right == NULL) {
					cur->right = n;
					break;
				}
				else {
					cur = cur->right;
				}
			}
			else if (cur->data == n->data) {
				printf("중복되는 숫자가 있습니다 다시 입력하세요 : ");
				scanf_s("%d", &inputData);
				n->data = inputData;
				continue;
			}
			else
			{
				if (cur->left == NULL) {
					cur->left = n;
					break;
				}
				else {
					cur = cur->left;
				}
			}
		}
	}

	return head;
}

void preorderTraversal(node* cur)
{
	if (cur != NULL) {
		printf("%d\t", cur->data);
		preorderTraversal(cur->left);
		preorderTraversal(cur->right);
	}
}
void inorderTraversal(node*head) {
	
}

void postorderTraversal(node*head) {
	
}

node* backTracking(node* head, node* var) {
	node* cur = head;
	if (var == cur) {
		return var;
	}

	while (var != cur->left && var != cur->right) {
		if (var->data > cur->data) {
			cur = cur->right;
		}
		else
		{
			cur = cur->left;
		}
	}
	return cur;
 }

void searchNode(node*head) {
	node* cur = head;
	int searchData;
	printf("검색할 숫자를 적어주세요 : ");
	scanf_s("%d", &searchData);
	while (cur) {
		if (searchData == cur->data) {
			printf("검색한 숫자 : %d\n", cur->data);
			break;
		}
		else if (searchData > cur->data) {
			cur = cur->right;
		}
		else if (searchData < cur->data) {
			cur = cur->left;
		}
	}
	if (cur == NULL) {
		printf("해당 숫자를 찾을 수 없습니다.\n");
	}
}

node* deleteNode(node*head) {
	int deleteData;
	printf("삭제할 숫자를 적어주세요 :  ");
	scanf_s("%d", &deleteData);
	node* delNode = head;
	while (delNode) {
		if (deleteData == delNode->data) {
			break;
		}
		else if (deleteData > delNode->data) {
			delNode = delNode->right;
		}
		else if (deleteData < delNode->data) {
			delNode = delNode->left;
		}
	}
	if (delNode == NULL) {
		printf("해당 숫자를 찾을 수 없습니다.\n");
		return head;
	}
	printf("%d\n", delNode->data);
	node* heir = delNode;
	if (heir->left == NULL && heir->right == NULL) {
		node* temp = backTracking(head, heir);
		if (temp->left == heir) {
			temp->left = NULL;
		}
		else {
			temp->right = NULL;
		}
		free(delNode);
		return head;
	}
	else if (heir->left != NULL && heir->right != NULL) {
		if (heir->left != NULL) {
			heir = heir->left;
			while (heir->right) {
				heir = heir->right;
			}
			if (heir->left == NULL) {
				
			}
		}
	}
	else {
		node*temp = backTracking(head, heir);
		if (heir->left != NULL) {
			heir = heir->left;
		}
		else {
			heir = heir->right;
		}
		if (temp->left == delNode) {
			temp->left = heir;
		}
		else {
			temp->right = heir;
		}
		free(delNode);
		return head;
	}
	return heir;
}