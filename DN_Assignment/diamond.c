#include <stdio.h>

int main_diamond()
{
	int num = 0;
	printf("���ϴ� ���� �Է� :");
	scanf_s("%d", &num);
	int i, j, k;
	int a, b, c;
	int l = (num - 1) / 2;
	
	if(num % 2 == 1)
	{
		for (i = 0; i <= l; i++) //�� ��
		{
			for (k = i; k <= l-1; k++) //���� ����
			{
				printf(" ");
			}
			for (j = 0; j < 2*i+1; j++) // *
			{
				printf("*");
			}
			printf("\n");
		}
		for (a = 0; a <= l-1; a++) //�Ʒ� *
		{
			for (b = 0; b <= a; b++) // ����
			{
				printf(" ");
			}
			for (c = 2 * a; c <= num - 3; c++) //* ����
			{
				printf("*");
			}
			printf("\n");
		}
	}
	else
	{
		for (i = 0; i <= l; i++) //�� ��
		{
			for (k = i; k <= l - 1; k++) //���� ����
			{
				printf(" ");
			}
			for (j = 0; j < 2 * (i+1); j++) // *
			{
				printf("*");
			}
			printf("\n");
		}
		for (a = 0; a <= l - 1; a++) //�Ʒ� *
		{
			for (b = 0; b <= a; b++) // ����
			{
				printf(" ");
			}
			for (c = 2*a; c <= num - 3; c++) //* ����
			{
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}