/*
	학번: 202411236

	이름: 윤우진

	프로그램 명: Assignment12.c

	프로그램 내용: 기차표 예매 시스템을 작성하려고 한다. 간단한 구현을 위해 좌석은 모두 10개라고 하자.
	예매할 좌석수를 입력받아 빈 자리를 할당한다. 예매할 떄마다 각 좌석의 상태를 출력한다.
	0이면 예매 가능, x는 예매불가를 의미한다. 더 이상 예매할 수 없으면 프로그램을 종료한다.

	날짜: 20251005
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// 기능명: book
// 내용: 예매 시스템
// 입력: 좌석수
// 출력: 예매된 좌석
// 오류: 없음
void book()
{
	int seat[10] = { 0 };
	int input = 0;
	int remain = 10;

	while (seat[9] == 0)
	{
		printf("현재 좌석 : [ ");
		for (int i = 0; i < 10; i++)
		{
			if (seat[i] == 0)
			{
				printf("O ");
			}
			else
			{
				printf("X ");
			}
		}
		printf("]\n");

		printf("예매할 좌석수? ");
		scanf("%d", &input);

		for (int i = 0; i < 10; i++)
		{
			if (seat[i] == 0 && input > 0)
			{
				seat[i] = 1;
				printf("%d ", i + 1);
				input--;
			}
		}
		printf(" 번 좌석을 예매했습니다.\n");
	}
}


int main()
{
	book();
	return 0;
}