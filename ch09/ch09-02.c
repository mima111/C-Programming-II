/*
	학번: 202411236
	이름: 윤우진
	프로그램 명: ch09-02.c
	프로그램 내용: 예제 9-2
	날짜: 20250924
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char s1[] = "hello";
	char s2[] = "";
	int len = 0;

	printf("s1의 길이: %d\n", strlen(s1));
	printf("s2의 길이: %d\n", strlen(s2));
	printf("s2의 길이: %d\n", strlen("bye bye"));

	printf("s1의 크기 : %d\n", sizeof(s1));
	len = strlen(s1);
	if (len > 0)
		s1[len - 1] = '\0';
	printf("s1 = %s\n", s1);

	return 0;
}