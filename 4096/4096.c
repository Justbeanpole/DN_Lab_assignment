#include <stdio.h>
void count(a);

int main_abcsdf(void)
{
	for (int b = 0; b <= 12; b++)
	{
		int c = 1 + 512 * b; //���� �� ���� ����
		count(c);
		printf("\n");
	}
	
	return 0;
}
void count(a)
{
	int num, i, j, k, l, h;
	for (l = 0; l <= 7; l++) //�� ����
	{
		for (i = 0; i <= 7; i++) //8��¥�� �� ���� 6��
		{
			j = a + 64 * i + (l * 8); //�ʱⰪ
			k = j + 7; //���� ���� ����
			for (num = j; num <= k; num++) //���� ���� ���� 1~8, 65~72 ---
			{
				if (num <= 4096) //4096���� ���
				{
					if (num % 8 == 0) //8�� ���� ĭ��
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
