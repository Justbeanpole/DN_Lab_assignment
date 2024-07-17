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
		printf("* 1.입력 2.출력 3.검색 4.삭제 5.저장 6.로드 7.종료 *\n");
		printf("****************************************************\n");
		printf("실행 항목의 번호를 입력 : ");
		scanf_s("%[^\n]%*c", &input, sizeof(input));
		printf("\n");

		if (strlen(input) == 1 && isdigit(input[0]))
		{
			int in;
			in = atoi(input);
			
			switch (in)
			{
			case 1: //입력
			{
				while (1)
				{
					printf("학번: ");
					scanf_s("%[^\n]%*c", &a[i].num, sizeof(a[i].num)); //버퍼에 대기 중이던 엔터가 처리되서 그냥 넘어가버림

					//길이 요소 검사
					int len = 0;
					if (strlen(a[i].num) != 8)
					{
						printf("\n8자리 숫자를 입력하세요.\n\n");
					}
					else
					{
						for (len = 0; len < 8;)
						{
							if (!isdigit(a[i].num[len])) //숫자만
							{
								printf("\n숫자를 입력해주세요.\n\n");
								break;
							}
							else
							{
								len++;
							}
						}
					}

					//중복검사
					for (int n = 0; n < i; n++)
					{
						if (!strcmp(a[i].num, a[n].num)) //strcmp는 같으면 0출력
						{
							printf("\n같은 학번이 있습니다.\n\n");
							len = 0;
							break;
						}
					}

					//학번 반복문 탈출
					if (len == 8)
					{
						break;
					}
				}
				printf("\n");

				while (1)
				{
					printf("이름: ");
					scanf_s("%[^\n]%*c", &a[i].name, sizeof(a[i].name));

					int w = 0;
					int correct = 0;
					w = strlen(a[i].name);
					for (int e = 0; e < w; e++) // 문제발생
					{	
						if (isdigit(a[i].name[e]) || ispunct(a[i].name[e]) || isspace(a[i].name[e])) //글자만 숫자, 특수문자
						{
							printf("\n숫자 또는 특수문자가 포함되어 있습니다.\n\n");
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
					printf("국어 점수: ");
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
								printf("\n숫자만 입력해주세요.\n\n");
								break;
							}
						}
						
					}
					else
					{
						printf("\n3자리 이상 입력 불가합니다.\n\n");
					}
					if (strlen(a[i].kscore) == anw)
					{
						break;
					}
					
				}
				printf("\n");
				while (1)
				{
					printf("수학 점수: ");
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
								printf("\n숫자만 입력해주세요.\n\n");
								break;
							}
						}
					}
					else
					{
						printf("\n3자리 이상 입력 불가합니다.\n\n");
					}
					if (anw == strlen(a[i].mscore))
					{
						break;
					}
				}
				printf("\n");
				while (1)
				{
					printf("영어 점수: ");
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
								printf("\n숫자만 입력해주세요..\n\n");
								break;
							}
						}
					}
					else
					{
						printf("\n3자리 이상의 숫자는 입력 불가합니다.\n\n");
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
			case 2: //출력
			{
				st b;
				if (i == 0)
				{
					printf("출력 값이 없습니다.\n\n");
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
					printf("학번: % 8s | 이름 : % 8s | 국어점수 : % 3s | 수학점수 : % 3s | 영어점수 : % 3s | 총합점수 : % 3d | 평균점수 : % 3d\n\n",
						a[p].num, a[p].name, a[p].kscore, a[p].mscore, a[p].escore, total, total / 3);
				}

				break;
			}
			case 3: //검색
			{
				char search[20];
				printf("검색할 학생의 학번을 입력하세요: ");
				scanf_s("%[^\n]%*c", &search, sizeof(search));
				printf("\n");
				int y = 0;
				for (int n = 0; n < i; n++)
				{
					if (!strcmp(search, a[n].num))
					{
						int total = atoi(a[n].kscore) + atoi(a[n].mscore) + atoi(a[n].escore);
						printf("학번: %s | 이름: %s | 국어점수: %s | 수학점수: %s | 영어점수: %s | 총합점수: %d | 평균점수: %d\n\n",
							a[n].num, a[n].name, a[n].kscore, a[n].mscore, a[n].escore, total, total / 3);
						y = 1;
						break;
					}
				}
				if (y != 1)
				{
					printf("해당 학생을 찾지 못했습니다.\n\n");
					break;
				}
				break;
			}
			case 4: //삭제
			{
				char del[20];
				printf("삭제할 학생의 학번을 입력하세요: ");
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
						printf("삭제되었습니다.\n\n");
						break;
					}
				}
				if (y != 1)
				{
					printf("해당 학생을 찾지 못했습니다.\n\n");
					break;
				}
				break;
			}
			case 5: //저장
			{
				FILE* fp = fopen("save.txt", "w");
				if (fp == NULL)
				{
					printf("파일이 없습니다.");
				}
				for (int r = 0; r < i; r++)
				{
					fprintf(fp, "%s %s %s %s %s \n", a[r].num, a[r].name, a[r].kscore, a[r].mscore, a[r].escore);
				}
				fclose(fp);
				printf("저장되었습니다.\n\n");
				break;
			}
			case 6: //로드
			{
				FILE* fp = fopen("save.txt", "r");
				if (fp == NULL)
				{
					printf("파일이 없습니다.");
				}
				int n = 0;
				while (!feof(fp))
				{
					fscanf_s(fp, "%s %s %s %s %s", &a[n].num, 20, &a[n].name, 20, &a[n].kscore,20, &a[n].mscore,20, &a[n].escore,20);
					i = n;
					n++;
				}
				printf("로드되었습니다.\n\n");
				fclose(fp);
				break;
			}
			case 7: //종료
			{
				printf("시스템을 종료합니다.\n\n");
				s = 0;
				break;
			}
			default: //실행번호 예외처리
			{
				printf("1~7까지의 숫자를 입력해주세요.\n\n");
			}
			}
		}
		else
		{
			printf("\n숫자가 아닌 다른 것을 입력했습니다.\n\n");
			
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

