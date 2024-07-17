#include <stdio.h>

void recfac(int i, int);
int total[256] = { 1 };
int n = 1;
int j, c = 0;
int a;

int main_recusion()
{
	recfac(1, 50);
	return 0;
}

void recfac(int i, int m)
{
	if (i > m)
	{
		for (int k = n-1; k >= 0; k--)
		{
			printf("%d", total[k]);
		}
	}
	else
	{
		j = 0;
		for (c = 0; j < n; j++)
		{
			a = i * total[j] + c;
			total[j] = a % 10;
			c = a / 10;
		}
		while (c)
		{
			total[n] = c % 10;
			n++;
			c /= 10;
		}
		recfac(i + 1, m);
	}
}