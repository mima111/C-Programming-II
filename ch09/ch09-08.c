/*
	학번: 202411236
	이름: 윤우진
	프로그램 명: ch09-08.c
	프로그램 내용: 예제 9-8
	날짜: 20250924
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char in_str[128];
	char out_str[128];
	int hour = 12, min = 30, sec = 45;

	printf("문자열? ");
	get_s(in_str, sizeof(in_str));
	puts(in_str);
	sprintf(out_str, "%02d:%02d:%02d", hour, min, sec);
	puts(out_str);
	return 0;
}