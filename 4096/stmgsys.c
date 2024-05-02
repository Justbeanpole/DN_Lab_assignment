#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void clear();


typedef struct student
{
	char num[200];
	unsigned char name[100];
	char kscore[100];
	char mscore[100];
	char escore[100];
} st;

st a[10];

int aa()
{
	int i = 0;
	int s = 1;
	
	while (s)
	{
		char input[10];
		printf("****************************************************\n");
		printf("* 1.�Է� 2.��� 3.�˻� 4.���� 5.���� 6.�ε� 7.���� *\n");
		printf("****************************************************\n");
		printf("���� �׸��� ��ȣ�� �Է�: ");
		scanf_s("%[^\n]%*c", &input, sizeof(input));
		printf("\n");

		if (strlen(input) == 1 && isdigit(input[0]))
		{
			int in;
			in = atoi(input);
			
			switch (in)
			{
			case 1: //�Է�
			{
				while (1)
				{
					printf("�й�: ");
					scanf_s("%[^\n]%*c", &a[i].num, sizeof(a[i].num)); //���ۿ� ��� ���̴� ���Ͱ� ó���Ǽ� �׳� �Ѿ������ ���� �߻�

					//���� ��� �˻�
					int len = 0;
					if (strlen(a[i].num) != 8)
					{
						printf("\n8�ڸ� ���ڸ� �Է��ϼ���.\n\n");
					}
					else
					{
						for (len = 0; len < 8;)
						{
							if (!isdigit(a[i].num[len])) //���ڸ�
							{
								printf("\n���ڸ� �Է����ּ���.\n\n");
								break;
							}
							else
							{
								len++;
							}
						}
					}

					//�ߺ��˻�
					for (int n = 0; n < i; n++)
					{
						if (!strcmp(a[i].num, a[n].num)) //strcmp�� ������ 0���
						{
							printf("\n���� �й��� �ֽ��ϴ�.\n\n");
							len = 0;
							break;
						}
					}

					//�й� �ݺ��� Ż��
					if (len == 8)
					{
						break;
					}
				}
				printf("\n");

				while (1)
				{
					printf("�̸�: ");
					scanf_s("%[^\n]%*c", &a[i].name, sizeof(a[i].name));

					int w = 0;
					int correct = 0;
					w = strlen(a[i].name);
					for (int e = 0; e < w; e++) // �����߻�
					{	
						if (isdigit(a[i].name[e]) || ispunct(a[i].name[e]) || isspace(a[i].name[e])) //���ڸ� ����, Ư������
						{
							printf("\n���� �Ǵ� Ư�����ڰ� ���ԵǾ��ֽ��ϴ�.\n\n");
							break;
						}
						else
						{
							correct++;
						}
					}
					if (correct == w)
					{
						break;
					}
				}
				printf("\n");
				while (1)
				{
					printf("���� ����: ");
					scanf_s("%[^\n]%*c", &a[i].kscore, sizeof(a[i].kscore));
					int anw = 0;
					if (strlen(a[i].kscore) <= 3 && atoi(a[i].kscore) <= 100)
					{
						
						int nm = 0;
						while (a[i].kscore[nm])
						{
							if (isdigit(a[i].kscore[nm]))
							{
								nm++;
								anw++;
							}
							else
							{
								printf("\n���ڸ� �Է����ּ���.\n\n");
								break;
							}
						}
						
					}
					else
					{
						printf("\n3�ڸ� �̻� �Է� �Ұ��մϴ�.\n\n");
					}
					if (strlen(a[i].kscore) == anw)
					{
						break;
					}
					
				}
				printf("\n");
				while (1)
				{
					printf("���� ����: ");
					scanf_s("%[^\n]%*c", &a[i].mscore, sizeof(a[i].mscore));
					int anw = 0;
					int nm = 0;
					if (strlen(a[i].mscore) <= 3 && atoi(a[i].mscore) <= 100)
					{
						while (a[i].mscore[nm])
						{
							if (isdigit(a[i].mscore[nm]))
							{
								nm++;
								anw++;
							}
							else
							{
								printf("\n���ڸ� �Է����ּ���.\n\n");
								break;
							}
						}
					}
					else
					{
						printf("\n3�ڸ� �̻��� ���ڴ� �Է� �Ұ��մϴ�.\n\n");
					}
					if (anw == strlen(a[i].mscore))
					{
						break;
					}
				}
				printf("\n");
				while (1)
				{
					printf("���� ����: ");
					scanf_s("%[^\n]%*c", &a[i].escore, sizeof(a[i].escore));
					int anw = 0;
					int nm = 0;
					if (strlen(a[i].escore) <= 3 && atoi(a[i].escore) <= 100)
					{
						while (a[i].escore[nm])
						{
							if (isdigit(a[i].escore[nm]))
							{
								nm++;
								anw++;
							}
							else
							{
								printf("\n���ڸ� �Է����ּ���.\n\n");
								break;
							}
						}
					}
					else
					{
						printf("\n3�ڸ� �̻��� ���ڴ� �Է� �Ұ��մϴ�.\n\n");
					}
					if (anw == strlen(a[i].escore))
					{
						break;
					}
				}
				printf("\n");
				i++;
				break;
			}
			case 2: //���
			{
				st b;
				if (i == 0)
				{
					printf("��°��� �����ϴ�.\n\n");
				}
				for (int k = 0; k < i - 1;)
				{
					for (int u = 0; u < i - k; u++)
					{
						if ((atoi(a[u].kscore) + atoi(a[u].mscore) + atoi(a[u].escore) < atoi(a[u + 1].kscore) + atoi(a[u + 1].mscore) + atoi(a[u + 1].escore)))
						{
							b = a[u];
							a[u] = a[u + 1];
							a[u + 1] = b;
						}
						else
						{
							continue;
						}
					}
					k++;
				}
				for (int p = 0; p < i; p++)
				{
					int total = atoi(a[p].kscore) + atoi(a[p].mscore) + atoi(a[p].escore);
					printf("�й�: %8s | �̸�: %8s | ��������: %3s | ��������: %3s | ��������: %3s | ��������: %3d | �������: %3d\n\n",
						a[p].num, a[p].name, a[p].kscore, a[p].mscore, a[p].escore, total, total / 3);
				}

				break;
			}
			case 3: //�˻�
			{
				char search[20];
				printf("�˻��� �л��� �й��� �Է��ϼ���: ");
				scanf_s("%[^\n]%*c", &search, sizeof(search));
				printf("\n");
				int y = 0;
				for (int n = 0; n < i; n++)
				{
					if (!strcmp(search, a[n].num))
					{
						int total = atoi(a[n].kscore) + atoi(a[n].mscore) + atoi(a[n].escore);
						printf("�й�: %s | �̸�: %s | ��������: %s | ��������: %s | ��������: %s | ��������: %d | �������: %d\n\n",
							a[n].num, a[n].name, a[n].kscore, a[n].mscore, a[n].escore, total, total / 3);
						y = 1;
						break;
					}
				}
				if (y != 1)
				{
					printf("�ش� �л��� ã�� ���߽��ϴ�.\n\n");
					break;
				}
				break;
			}
			case 4: //����
			{
				char del[20];
				printf("������ �л��� �й��� �Է��ϼ���: ");
				scanf_s("%[^\n]%*c", &del, sizeof(del));
				printf("\n");
				int y = 0;
				for (int n = 0; n < i; n++)
				{
					if (!strcmp(del, a[n].num))
					{
						for (int k = n; k < i; k++)
						{
							a[k] = a[k + 1]; //�� ĭ�� ������ �����
						}
						y = 1;
						i--;
						printf("�����Ǿ����ϴ�.\n\n");
						break;
					}
				}
				if (y != 1)
				{
					printf("�ش� �л��� ã�� ���߽��ϴ�.\n\n");
					break;
				}
				break;
			}
			case 5: //����
			{
				FILE* fp = fopen("save.txt", "w");
				if (fp == NULL)
				{
					printf("������ �����ϴ�.");
				}
				for (int r = 0; r < i; r++)
				{
					fprintf(fp, "%s %s %s %s %s \n", a[r].num, a[r].name, a[r].kscore, a[r].mscore, a[r].escore);
				}
				fclose(fp);
				printf("����Ǿ����ϴ�.\n\n");
				break;
			}
			case 6: //�ε�
			{
				FILE* fp = fopen("save.txt", "r");
				if (fp == NULL)
				{
					printf("������ �����ϴ�.");
				}
				int n = 0;
				while (!feof(fp))
				{
					fscanf_s(fp, "%s %s %s %s %s", &a[n].num, 20, &a[n].name, 20, &a[n].kscore,20, &a[n].mscore,20, &a[n].escore,20);
					i = n;
					n++;
				}
				printf("�ε�Ǿ����ϴ�.\n\n");
				fclose(fp);
				break;
			}
			case 7: //����
			{
				printf("�ý����� �����մϴ�.\n\n");
				s = 0;
				break;
			}
			default: //�����ȣ ����ó��
			{
				printf("1~7������ ���ڸ� �Է����ּ���.\n\n");
			}
			}
		}
		else
		{
			printf("\n���ڰ� �ƴ� �ٸ� ���� �Է��߽��ϴ�.\n\n");
			
		}

		
		
	}
	return 0;
}

void printst()
{
	while (1)
	{
		int i = 1;
		st a;
		if (i == 0)
		{
			printf("����� ������ �������� �ʽ��ϴ�.\n\n");
			break;
		}
		else
		{
			for (int n = 0; n < i; n++)
			{
				//printf("�й�: %s | �̸�: %s | ��������: %d | ��������: %d | ��������: %d | ��������: %d | �������: %d\n\n",
					//a[n].num, a[n].name, a[n].kscore, a[n].mscore, a[n].escore, (a[n].kscore + a[n].mscore + a[n].escore), (a[n].kscore + a[n].mscore + a[n].escore) / 3);
			}
			break;
		}
	}
	
}
void savest()
{
	int i = 0;
	for (int n = 0; n < i; n++)
	{
		//fprintf(fp, "%s %s %d %d %d \n", a[n].num, a[n].name, a[n].kscore, a[n].mscore, a[n].escore);
	}
}
void clear()
{
	while (getchar() != '\n');
}

