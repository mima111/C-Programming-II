/*
	학번: 202411236
	이름: 윤우진
	프로그램 명: ch09-09.c
	프로그램 내용: 예제 9-9
	날짜: 20251005
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main()
{
	char str[64] = "";
	char* p = str;

	strcpy(p, "test string");

	if (islower(p[0]))
		p[0] = toupper(p[0]);
	p = strchr(p, ' ');

	if (islower(p[1]))
		p[1] = toupper(p[1]);
	puts(str);
	return 0;
}