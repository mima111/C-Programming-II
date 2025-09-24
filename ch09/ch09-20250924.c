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

	printf("���ڵ� ���� : �̸� | �й� | �а� | �г�\n");
	printf("�Է��� �����Ϸ��� 'exit'�� �Է��ϼ���.\n");

	while (1)
	{
		if (input(&students[count]) == 0)
			break;
		count++;

		if (count >= MAX)
		{
			printf("�ִ� ���ڵ� ���� �����߽��ϴ�.\n");
			break;
		}

	}

	printrecord(students, count);
	return 0;
}

int input(Student* s)
{
	char buffer[200];
	printf("�Է� >> ");
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
	printf("\n--- �л� ���ڵ� ---\n");
	if (s == NULL || count <= 0)
	{
		printf("����� ���ڵ尡 �����ϴ�.\n");
		return;
	}
	for (int i = 0; i < count; i++)
	{
		printf("����: %d, �̸�: %s, �й� : %s, �а� : %s, �г� : %d\n",
			i, s[i].name, s[i].id, s[i].dept, s[i].year);
	}
}