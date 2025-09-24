/*
	학번: 202411236
	이름: 윤우진
	프로그램 명: ch09-01.c
	프로그램 내용: 예제 9-1
	날짜: 20250924
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[10] = { 'a', 'b', 'c' };
	char str2[10] = "abc";
	char str3[] = "abc";
	char str4[10] = "very long string";
	int size = sizeof(str1) / sizeof(str1[0]);
	int i;

	printf("str = ");
	for (i = 0; i < size; i++)
		printf("%c", str1[i]);
	printf("\n");

	printf("str2 = %s\n", str2);
	printf("str3 = ");
	printf(str3);
	printf("\n");

	printf("str4 = %s\n", str4);

	return 0;
}
