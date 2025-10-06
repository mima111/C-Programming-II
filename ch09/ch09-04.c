/*
	학번: 202411236
	이름: 윤우진
	프로그램 명: ch09-04.c
	프로그램 내용: 예제 9-4
	날짜: 20250924
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 10

int main(void)
{
	char s1[SIZE] = "apple";
	char s2[SIZE] = "apple";
	char password[SIZE];

	/* 주소를 비교하면 안됨.
	if (s1 == s2)
		printf("same adress\n");
	*/

	if (strcmp(s1, s2) == 0)
		printf("same string\n");

	printf("패스워드? ");
	scanf("%s", password);
	if (strcmp(password, "abcd1234") == 0)
		printf("login succeeded\n");
	else
		printf("login failed\n");

	return 0;
}