
/*
	학번: 202411236
	이름: 윤우진
	프로그램 명: Assignment11.c

	프로그램 내용:
	직사각형 넓이와 둘레를 구하는 get_rect_info 함수를 작성하시오.
	직사각형의 가로, 세로의 길이를 입력받은 다음 get_rect_info 함수를 이용해서 직사각형의 넓이와 둘레를
	구해서 출력하는 프로그램을 작성하시오.

	날짜: 20251006
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 기능명: get_rect_info
// 내용: 넓이, 둘레 구하는 함수
// 입력: 가로, 세로
// 출력: 없음
void get_rect_info(int w, int h, int* parea, int* pperi)
{
	*parea = (w) * (h);
	*pperi = 2 * ((w)+(h));
}

// 기능명: Assignment11
// 내용: 넓이, 둘레 를 구하고 출력하는 함수
// 입력: 가로,세로
// 출력: 넓이,둘레
void Assignment11()
{
	int area;
	int peri;

	int w, h;

	printf("가로? ");
	scanf("%d", &w);
	printf("세로? ");
	scanf("%d", &h);

	get_rect_info(w, h, &area, &peri);
	printf("넓이: %d, ", area);
	printf("둘레: %d\n", peri);
}

int main()
{
	Assignment11();

	return 0;
}