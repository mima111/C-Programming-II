/*
	학번: 202411236
	이름: 윤우진
	프로그램 명: Assignment05.c

	프로그램 내용:
	등차수열은 앞의 항에 항상 일정한 수(공차)를 더하여 만들어가는 수열이다.
	배열과 배열의 크기, 공차를 매개변수로 받아서 등차수열로 배열을 채우는 arith_seq 함수를 정의하시오.
	첫 번째 항의 값은 배열의 0번 원소에 넣어서 전달한다.
	arith_seq 함수를 이용해서 입력받은 첫 번째 항과 공차로 크기가 10인 정수형 배열에 대하여
	등차수열을 구하고 출력하는 프로그램을 작성하시오.

	날짜: 20251006
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void arith_seq(int arr[], int size, int diff, int first);

int main()
{
	int arr[10];
	int size = 10;
	int first = 0;
	int diff = 0;

	printf("첫 번째 항? ");
	scanf("%d", &first);

	printf("공차? ");
	scanf("%d", &diff);

	
	arith_seq(arr, size, diff, first);

	return 0;
}

// 기능명: arith_seq
// 내용: 배열을 등차수열로 채우고 출력
// 입력: 배열, 크기, 공차, 첫 항
// 출력: 등차수열 출력
void arith_seq(int arr[], int size, int diff, int first)
{
	arr[0] = first;

	
	for (int i = 1; i < size; i++)
	{
		arr[i] = arr[i - 1] + diff;
	}

	
	printf("등차수열: ");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}