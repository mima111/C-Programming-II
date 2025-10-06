/*
	학번: 202411236
	
	이름: 윤우진

	프로그램 명: Assignment01.c

	프로그램 내용: 등차수열은 앞의 항에 일정한 수(공차)를 
	더하여 만들어가는 수열이다. 크기가 10인 정수형 
	배열에 대하여 등차수열로 값을 채우려고 한다. 
	첫 번째 항의 값과 공차를 입력받아 배열을 채우고 출력하는 프로그램을 작성하시오.

	날짜: 20251005
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void fng(void);

// 기능명: fng
// 내용: 공차,첫 번째항을 물어보고 입력받아 등차수열을 출력하는 함수
// 입력: 첫번째항, 공차
// 출력: 등차수열 출력
// 오류: 없음
void fng ()
{
	int arr[10];
	int first;
	int diff;
	int i;


	printf("첫 번째 항? ");
	scanf("%d", &first);
	
	
	printf("공차? ");
	scanf("%d", &diff);
	
	for (i = 0; i < 10; i++)
	{
		arr[i] = first + i * diff;
	}

	printf("등차수열: ");
	for (i = 0;	i < 10 ; i++)
	{
		printf("%d ", arr[i]);
	}
}

int main()
{
	fng();
	
	return 0;
}