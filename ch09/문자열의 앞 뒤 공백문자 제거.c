#include <stdio.h>
#include <string.h>
#include <ctype.h>

// ���ڿ� ���� ���� ���� (Left Trim)
char* ltrim(char* str)
{
	if (str == NULL) return NULL;

	//���� ���� ���ڵ��� �ǳʶٱ�
	while (*str && isspace(*str))
	{
		str++;
	}
	return str;
}

//���ڿ� ���� ���� ���� (Right Trim)
char* rtrim(char* str)
{
	if (str == NULL) return NULL;

	int len = strlen(str);
	if (len == 0) return str;

	//�ڿ������� ���� ���ڸ� NULL�� ����
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

	//���� ������ trim, �״��� ���� trim
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