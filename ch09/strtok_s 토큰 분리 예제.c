#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "홍길동, 29, 청주시 서원구 | date";
	char* token;
	char* context = NULL;

	printf("원본 문자열: %s\n", str);
	printf("토큰들:\n");

	// 첫 번째 토큰 추출
	token = strtok_s(str, ",|", &context);

	// 모든 토큰 출력
	while (token != NULL)
	{
		printf("토큰: %s\n", token);
		token = strtok_s(NULL, ",", &context);
	}

	return 0;
}