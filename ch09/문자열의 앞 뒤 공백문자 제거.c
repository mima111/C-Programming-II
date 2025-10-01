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