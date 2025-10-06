/*
	학번: 202411236

	이름: 윤우진

	프로그램 명: Assignment07.c

	프로그램 내용: 정수형 배열의 모든 원소를 득정 값으로 챙우는 fill_array 함수를 작성하시오.
	fill_array(arr, 10, 1);은 크기가 10인 arr 배열의 모든 원고에 1을 대입하라는 의미이다. 
	크기가 20인 배열을 선언해서 입력받은 값으로 배열 전체를 채우고 출력하는 프로그램을 작성하시오.

	날짜: 20251005
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void fill_array(int arr[], int size, int value);

int main()
{
	int arr[20];
	fill_array(arr,20,0);

	return 0;
}

// 기능명: fill_array
// 내용: 배열의 원소를 특정 값으로 채우고 출력하는 함수
// 입력: 배열의 값
// 출력: 배열 안에 있는 값
// 오류: 없음
void fill_array(int arr[], int size, int value)
{
	int i;
	printf("배열의 원소에 저장할 값? ");
	scanf("%d", &value);

	for (int i = 0; i < size; i++)
	{
		arr[i] = value;
	}
	
	for (i = 0; i < size; i++)
	{
		printf("%d ",value);
	}
	
}