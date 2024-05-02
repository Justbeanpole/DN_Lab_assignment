#include <stdio.h>

int main_diamond()
{
	int num = 0;
	printf("원하는 숫자 입력 :");
	scanf_s("%d", &num);
	int i, j, k;
	int a, b, c;
	int l = (num - 1) / 2;
	
	if(num % 2 == 1)
	{
		for (i = 0; i <= l; i++) //위 별
		{
			for (k = i; k <= l-1; k++) //공백 역순
			{
				printf(" ");
			}
			for (j = 0; j < 2*i+1; j++) // *
			{
				printf("*");
			}
			printf("\n");
		}
		for (a = 0; a <= l-1; a++) //아래 *
		{
			for (b = 0; b <= a; b++) // 공백
			{
				printf(" ");
			}
			for (c = 2 * a; c <= num - 3; c++) //* 역순
			{
				printf("*");
			}
			printf("\n");
		}
	}
	else
	{
		for (i = 0; i <= l; i++) //위 별
		{
			for (k = i; k <= l - 1; k++) //공백 역순
			{
				printf(" ");
			}
			for (j = 0; j < 2 * (i+1); j++) // *
			{
				printf("*");
			}
			printf("\n");
		}
		for (a = 0; a <= l - 1; a++) //아래 *
		{
			for (b = 0; b <= a; b++) // 공백
			{
				printf(" ");
			}
			for (c = 2*a; c <= num - 3; c++) //* 역순
			{
				printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}