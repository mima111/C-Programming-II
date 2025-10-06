/*
	학번: 202411236
	이름: 윤우진
	프로그램 명: ch09-05.c
	프로그램 내용: 예제 9-5
	날짜: 20250924
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char sentence[100] = "";
	char word[20];

	do {
		printf("단어? ");
		scanf("%s", word);
		strcat(sentence, word);
		strcat(sentence, " ");
	} while (strcmp(word, ".") != 0);

	printf("%s\n", sentence);

	return 0;
}