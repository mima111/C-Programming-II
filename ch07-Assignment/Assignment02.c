/*
	학번: 202411236

	이름: 윤우진

	프로그램 명: Assignment02.c

	프로그램 내용: 등비수열은 앞의 항에 항상 일정한 수(공비)를 곱하여 만들어가는 수열이다.
	크기가 10인 실수형 배열에  대하여 등비수열로 값을 채우려고 한다.
	첫 번째 항의 값과 공비를 입력받아서 배열을 채우고 출력하는 프로그램을 작성하시오.

	날짜: 20251005
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void fng(void);

// 기능명: fngbi
// 내용: 공비,첫 번째항을 물어보고 입력받아 등비수열을 출력하는 함수
// 입력: 첫번째항, 공비
// 출력: 등비수열 출력
// 오류: 없음
void fngbi()
{
	double arr[10];
	double first;
	double r;
	int i;


	printf("첫 번째 항? ");
	scanf("%lf", &first);


	printf("공비? ");
	scanf("%lf", &r);

	arr[0] = first;

	for (i = 1; i < 10; i++)
	{
		arr[i] = arr[i - 1] * r;
	}

	printf("등비수열: ");
	for (i = 0; i < 10; i++)
	{
		printf("%.1lf ", arr[i]);
	}
}

int main()
{
	fngbi();

	return 0;
}