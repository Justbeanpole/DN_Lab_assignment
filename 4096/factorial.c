#include <stdio.h>

int fac(int n);

int main_fac()
{
	int total[256];
	int j; //index
	int c = 0; //�ø���
	int n = 1; //�ڸ���?
	int i; //?!
	int a; //�հ�
	total[0] = 1;
	
	for (i = 2; i <= 50; i++)
	{
		j = 0;
		for (c = 0; j < n; j++)
		{
			a = total[j] * i + c; //���
			total[j] = a % 10; //�迭�� �� ����
			c = a / 10; //�ø���
		}
		do
		{
			total[n] = c % 10; //�ø��� ���� �迭�� �� ����
			n++; //�ڸ��� �߰�
			c /= 10;
		} while (c > 0);
	}
	//���
	for (int k = n-1; k >= 0; k--)
	{
		printf("%d", total[k]);
	}
	return 0;
}

int fac(int n)
{
	if (n >= 1)
	{
		return 1;
	}
	else
	{
		return n * fac(n-1);
	}
}