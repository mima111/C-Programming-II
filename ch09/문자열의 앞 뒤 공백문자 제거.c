/*
	학번: 202411236
	이름: 윤우진
	프로그램 명: 문자열의 앞 뒤 공백문자 제거.c
	프로그램 내용: 9월24일 수업중 문제 풀때 문자열의 앞 뒤 공백문자 제거 공부겸 작성.
	날짜: 20250924
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 문자열 앞쪽 공백 제거 (Left Trim)
char* ltrim(char* str)
{
	if (str == NULL) return NULL;

	//앞쪽 공백 문자들을 건너뛰기
	while (*str && isspace(*str))
	{
		str++;
	}
	return str;
}

//문자열 뒤쪽 공백 제거 (Right Trim)
char* rtrim(char* str)
{
	if (str == NULL) return NULL;

	int len = strlen(str);
	if (len == 0) return str;

	//뒤에서부터 공백 문자를 NULL로 변경
	char* end = str + len - 1;
	while (end >= str && isspace(*end))
	{
		*end = '\0';
		end--;
	}
	return str;
}

char* trim(char* str)
{
	if (str == NULL) return NULL;

	//먼저 오른쪽 trim, 그다음 왼쪽 trim
	rtrim(str);
	return ltrim(str);
}

int main()
{
	char temp1[] = "  hello world  ";
	char temp2[] = "\t\n  C Programming  \r\n ";

	printf("1: '%s'\n", ltrim(temp1));
	printf("2: '%s'\n", rtrim(temp1));
	printf("2: '%s'\n", trim(temp2));
}