
 /*
	 학번: 202411236

	 이름: 윤우진

	 프로그램 명: Assignment015.c

	 프로그램 내용: 

	 날짜: 20251006
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


typedef struct
{
	int x;
	int y;
}POINT;


POINT point[] =
{
	{7, 4},
	{12, 93},
	{22,31},
	{1, 20},
	{34, 53},
	{41, 2},
	{32, 9},
	{21, 31},
	{8, 2},
	{3, 5}
};

/*
	함수명 : swap_point
	기능(책임) : 배열을 정렬해줌. 기준은 point[x].x로 x값을 기준으로 한다.
	반환 : 없음
 */
void swap_point(POINT arr[], int size)
{
	

	for (int i = 0; i < size - 1; i++)
	{

		for (int j = 0; j < size - 1; j++)
		{

			if (arr[j].x > arr[j + 1].x)
			{
				POINT temp = arr[j];
				arr[j] = arr[j + 1];    
				arr[j + 1] = temp;

			}
		}

	}
}

/*
 * 함수명 : Assignment15
 * 기능(책임) : 배열을 정렬전, 정렬후를 출력해줌
 * 반환 : 없음
 */
void Assignment15()
{
	printf("<<정렬 전>>\n");
	int size;
	size = sizeof(point) / sizeof(point[0]);

	for (int i = 0; i < size; i++)
	{
		printf("(%d, %d)", point[i].x, point[i].y);
	} printf("\n");

	swap_point(point, size);

	printf("<<정렬 후>>\n");
	for (int i = 0; i < size; i++)
	{
		printf("(%d, %d)", point[i].x, point[i].y);
	} printf("\n");


}

int main()
{
	Assignment15();

	return 0;
}