#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct
{
	char name[50];
	char id[20];
	char dept[50];
	int year;
} Student;

int input(Student* s);
void printrecord(Student* s, int count);

int main()
{
	Student students[MAX];
	int count = 0;

	printf("레코드 형식 : 이름 | 학번 | 학과 | 학년\n");
	printf("입력을 종료하려면 'exit'을 입력하세요.\n");

	while (1)
	{
		if (input(&students[count]) == 0)
			break;
		count++;

		if (count >= MAX)
		{
			printf("최대 레코드 수에 도달했습니다.\n");
			break;
		}

	}

	printrecord(students, count);
	return 0;
}

int input(Student* s)
{
	char buffer[200];
	printf("입력 >> ");
	fgets(buffer, sizeof(buffer), stdin);
	buffer[strcspn(buffer, "\n")] = '\0';

	if (strcmp(buffer, "exit") == 0) 
		return 0;

	char* token = strtok(buffer, "|");
	if (!token) 
		return 0;
	strcpy(s->name, token);

	token = strtok(NULL, "|");
	if (!token) 
		return 0;
	strcpy(s->id, token);

	token = strtok(NULL, "|");
	if (!token) 
		return 0;
	strcpy(s->dept, token);

	token = strtok(NULL, "|");
	if (!token) 
		return 0;
	s->year = atoi(token);

	return 1;
}

void printrecord(Student* s, int count)
{
	printf("\n--- 학생 레코드 ---\n");
	if (s == NULL || count <= 0)
	{
		printf("출력할 레코드가 없습니다.\n");
		return;
	}
	for (int i = 0; i < count; i++)
	{
		printf("순번: %d, 이름: %s, 학번 : %s, 학과 : %s, 학년 : %d\n",
			i, s[i].name, s[i].id, s[i].dept, s[i].year);
	}
}