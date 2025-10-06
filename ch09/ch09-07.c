/*
	학번: 202411236
	이름: 윤우진
	프로그램 명: ch09-07.c
	프로그램 내용: 예제 9-7
	날짜: 20250924
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char phone[] = "02-123-4567";
	char* p = NULL;

	p = strtok(phone, "-");
	printf("area code: %s\n", p);
	p = strtok(NULL, "-");
	printf("prefix: %s\n", p);
	p = strtok(NULL, "-");
	printf("line number: %s\n", p);

	return 0;
}