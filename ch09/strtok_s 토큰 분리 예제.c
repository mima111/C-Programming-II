#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "ȫ�浿, 29, û�ֽ� ������ | date";
	char* token;
	char* context = NULL;

	printf("���� ���ڿ�: %s\n", str);
	printf("��ū��:\n");

	// ù ��° ��ū ����
	token = strtok_s(str, ",|", &context);

	// ��� ��ū ���
	while (token != NULL)
	{
		printf("��ū: %s\n", token);
		token = strtok_s(NULL, ",", &context);
	}

	return 0;
}