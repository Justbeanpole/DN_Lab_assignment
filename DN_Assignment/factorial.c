#include <stdio.h>

int fac(int n);

int main_fac()
{
	int total[256];
	int j; //index
	int c = 0; //올림수
	int n = 1; //자릿수?
	int i; //?!
	int a; //합곱
	total[0] = 1;
	
	for (i = 2; i <= 50; i++)
	{
		j = 0;
		for (c = 0; j < n; j++)
		{
			a = total[j] * i + c; //계산
			total[j] = a % 10; //배열에 값 저장
			c = a / 10; //올림수
		}
		do
		{
			total[n] = c % 10; //올림수 다음 배열에 값 저장
			n++; //자릿수 추가
			c /= 10;
		} while (c > 0);
	}
	//출력
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