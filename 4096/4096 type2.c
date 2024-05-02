#include <stdio.h>
void cou(int a);

int main_columprint()
{
	
	for (int i = 0; i <= 63; i++) // 1 64 65 128 129 192
	{
		cou(i);
	}
	return 0;
}
void cou(int a)
{
	int num, j, k;
	j = 1 + 64 * a;
	k = (a + 1) * 64;
	for (num = j; num <= k; num++) //64개의 숫자 출력 8의 배수마다 줄바꿈 
	{
		if (num % 8 == 0)
		{
			if (num % 64 == 0)
			{
				printf("%5d|\n", num);
			}
			else
			{
				printf("%5d|\n", num);
			}
		}
		else
		{
			printf("%5d", num);
		}
	}
}