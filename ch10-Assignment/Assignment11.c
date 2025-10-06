
 /*
	 학번: 202411236

	 이름: 윤우진

	 프로그램 명: Assignment11.c

	 프로그램 내용:PRODUCT 구조체를 이용해서 최대5개의 제품 정보를 입력받아 저장하고 출력하는 프로그램을
	 작성하시오, 제품명으로 "."가 입력되거나 5개의 제품 정보를 모두 입력하면, 지금까지 입력된 제품 정보를 출력하고 
	 종료한다.

	 날짜: 20251006
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct PRODUCT
{
	char name[100];
	int price;
	int stock;
}product;

/*
	함수명 : Assignment11()
	기능(책임) : 제품을 입력받고 남은 수량과 총 가격을 구해서 출력해줌. 0을 입력하면
	반복문을 종료하여 총 주문 내역을 출력해줌
	반환 : 없음
 */
void Assignment11()
{

	product p[3] =
	{
		{"아메리카노", 4000, 10},
		{"카페라떼", 4500, 10},
		{"플랫화이트", 5000, 10}
	};



	char order[100];
	int count;

	while (1)
	{

		printf("주문할 제품명? ");
		scanf("%s", order);

		if (strcmp(order, ".") == 0)
		{
			break;
		}

		int num = 0;


		if (strcmp(order, "아메리카노") == 0)
		{
			num = 0;
		}
		else if (strcmp(order, "카페라떼") == 0)
		{
			num = 1;
		}
		else if (strcmp(order, "플랫화이트") == 0)
		{
			num = 2;
		}
		else
		{
			printf("없는 메뉴\n");
			continue;
		}


		printf("주문할 수량? ");
		scanf("%d", &count);
		if ((p[num].stock - count) < 0)
		{
			printf("재고 부족\n");
			continue;
		}
		else
		{
			p[num].stock -= count;
		}



		printf("결제 금액: %d  %s 재고 : %d\n", (count * p[num].price), order, p[num].stock);
		}


		for (int i = 0; i < 3; i++)
		{
			printf("%s %d원 재고:%d\n", p[i].name, p[i].price, p[i].stock);

		}
	}

int main()
{
	Assignment11();
	return 0;
}