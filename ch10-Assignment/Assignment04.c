
 /*
	 학번: 202411236

	 이름: 윤우진

	 프로그램 명: Assignment04.c

	 프로그램 내용: 연월일을 나타내는 DATA 구조체와 DATE 구조체를 매개변수로 전달받아
	 날짜를 "2022/1/1" 처럼 출력하는 print_date 함수를 정의하시오. DATE 구조체와 print_date 함수를 이용해서
	 입력받은 날짜를 출력하는 프로그램을 작성하시오.

	 날짜: 20251006
 */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

struct DATE
{
	int y;
	int m;
	int d;
};

/*
	함수명 : print_date
	기능(책임) : 연, 월, 일을 입력받아 DATE 구조체에 저장하고 "연/월/일" 형식으로 출력
	반환 : 없음
 */
void print_date()
{
	struct DATE date;

	printf("연? : ");
	scanf("%d", &date.y);
	printf("월? : ");
	scanf("%d", &date.m);
	printf("일? : ");
	scanf("%d", &date.d);

	printf("%d/%d/%d", date.y, date.m, date.d);
}

int main()
{
	print_date();
	return 0;
}