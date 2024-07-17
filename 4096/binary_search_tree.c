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
			if (head != NULL) {
				preorderTraversal(head); printf("\n");
				inorderTraversal(head); printf("\n");
				postorderTraversal(head); printf("\n");
			}
			else {
				printf("출력값이 없습니다.\n");
			}
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
void inorderTraversal(node*cur) {
	if (cur != NULL) {
		inorderTraversal(cur->left);
		printf("%d\t", cur->data);
		inorderTraversal(cur->right);
	}
}

void postorderTraversal(node*cur) {
	if (cur != NULL) {
		postorderTraversal(cur->left);
		postorderTraversal(cur->right);
		printf("%d\t", cur->data);
	}
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
	node* heir = delNode;
	//자식 노드 0개
	if (heir->left == NULL && heir->right == NULL) {
		if (delNode == head) {
			printf("삭제되었습니다.\n");
			free(delNode);
			return NULL;
		}
		else {
			node* temp = backTracking(head, heir);
			if (temp->left == heir) {
				temp->left = NULL;
			}
			else {
				temp->right = NULL;
			}
		}
		printf("삭제되었습니다.\n");
		free(delNode);
		return head;
	}
	//자식 노드 2개
	else if (heir->left != NULL && heir->right != NULL) {
		heir = heir->left;
		while (heir->right) {
			heir = heir->right;
		}
		node* temp = backTracking(head, delNode);

		//자식 노드 X
		if (heir->left == NULL) {
			//붙어 있는 경우
			if (delNode->left == heir) {
				heir->right = delNode->right;
			}
			//안 붙은 경우
			else {
				backTracking(head, heir)->right = NULL;
				heir->left = delNode->left;
				heir->right = delNode->right;
			}
			// delNode가 헤드인 경우
			if (delNode == head) {
				printf("삭제되었습니다.\n");
				free(delNode);
				return heir;
			}
			// 아닌 경우
			else {
				if (delNode->data > temp->data) {
					temp->right = heir;
				}
				else {
					temp->left = heir;
				}
				printf("삭제되었습니다.\n");
				free(delNode);
				return head;
			}
		}
		//자식 노드 0
		else {
			//붙어 있는 경우
			if (delNode->left == heir) {
				heir->right = delNode->right;
			}
			//안 붙은 경우
			else {
				backTracking(head, heir)->right = heir->left;
				heir->left = delNode->left;
				heir->right = delNode->right;
			}

			// delNode가 헤드인 경우
			if (delNode == head) {
				printf("삭제되었습니다.\n");
				free(delNode);
				return heir;
			}
			// 아닌 경우
			else {
				if (delNode->data > temp->data) {
					temp->right = heir;
				}
				else {
					temp->left = heir;
				}
				printf("삭제되었습니다.\n");
				free(delNode);
				return head;
			}
		}
	}
	//자식 노드 1개
	else {
		node* temp = backTracking(head, heir);
		if (heir->left != NULL) {
			heir = heir->left;
		}
		else {
			heir = heir->right;
		}
		if (delNode == head) {
			printf("삭제되었습니다.\n");
			free(delNode);
			return heir;
		}
		else {
			if (temp->left == delNode) {
				temp->left = heir;
			}
			else {
				temp->right = heir;
			}
			printf("삭제되었습니다.\n");
			free(delNode);
			return head;
		}
	}
}
