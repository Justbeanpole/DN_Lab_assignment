#include <stdio.h>
void count(a);

int main_abcsdf(void)
{
	for (int b = 0; b <= 12; b++)
	{
		int c = 1 + 512 * b; //다음 줄 시작 숫자
		count(c);
		printf("\n");
	}
	
	return 0;
}
void count(a)
{
	int num, i, j, k, l, h;
	for (l = 0; l <= 7; l++) //줄 개수
	{
		for (i = 0; i <= 7; i++) //8개짜리 한 묶음 6개
		{
			j = a + 64 * i + (l * 8); //초기값
			k = j + 7; //가로 숫자 개수
			for (num = j; num <= k; num++) //가로 숫자 생성 1~8, 65~72 ---
			{
				if (num <= 4096) //4096까지 출력
				{
					if (num % 8 == 0) //8개 마다 칸막
					{
						printf("%4d |", num);
					}
					else
					{
						printf("%4d ", num);
					}
				}
				else
				{
					continue;
				}
			}
		}
		printf("\n");
	}
}
