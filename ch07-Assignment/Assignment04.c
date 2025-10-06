/*
	학번: 202411236

	이름: 윤우진

	프로그램 명: Assignment04.c

	프로그램 내용: 특정 값으로 초기화된 정수형 배열에 대하여 배열의 원소 중 최댓값을 가진 원소와 
	최솟값을 가진 원소를 찾아서 인덱스와 값을 함께 출력하는 프로그램을 작성하시오. \
	배열의 초기값은 마음대로 정하시오.

	날짜: 20251005
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void findms(void);


int main()
{
	findms();
	return 0;
}

// 기능명: findms
// 내용: 배열의 최댓값과 최솟값을 찾아서 인덱스와 값을 출력하는 함수
// 입력: 없음
// 출력: 인덱스와 인덱스 안의 값
// 오류: 없음
void findms()
{
	int arr[10] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37 };
	int max = arr[0];
	int min = arr[0];
	int index_max = 0;
	int index_min = 0;
	int i;
	printf("배열: ");

	for(i = 0; i < 10 ; i++)
	printf("%d ", arr[i]);

	for (i = 1; i < 10; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			index_min = i;
		}

		if (arr[i] > max)
		{
			max = arr[i];
			index_max = i;
		}
	}

	printf("\n최댓값: 인덱스=%d, 값=%d\n", index_max, max);
	printf("최솟값: 인덱스=%d, 값=%d", index_min, min);
	return 0;
}

