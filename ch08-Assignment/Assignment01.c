/*
	학번: 202411236

	이름: 윤우진

	프로그램 명: Assignment01.c

	프로그램 내용: 크기가 3인 double 형 배열의 모든 원소의 주소를 출력하는 프로그램을 작성하시오.
                   단 주소 구하기 연산자를 사용하지 마시오

	날짜: 20251005
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


// 기능명: doublepoint
// 내용: 크기가 3인 double 형 배열의 모든 원소의 인덱스와 
// 그 인덱스에 맞는 주소를 출력해주는 함수
// 입력: 첫번째항, 공차
// 출력: 등차수열 출력
// 오류: 없음
void doublepoint()
{
	double arr[3];
	double* p = arr;

	for (int i = 0; i < 3; i++)
	{
		printf("x[%i]의 주소 : %x\n", i, p + i);
	}

}


int main()
{
	doublepoint();
	return 0;
}