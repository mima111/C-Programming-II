/*
	학번: 202411236

	이름: 윤우진

	프로그램 명: Assignment02.c

	프로그램 내용: 배열 원소를 가리키는 포인터와 포인터 연산을 이용해서 실수형 배열의 모든 원소를 출력하는 프로그램을
	작성하시오. 실수형 배열은 크기가10이거 값은 마음대로 지정해서 사용한다.


	날짜: 20251006
*/

#include <stdio.h>
int arith_seq();

int main()
{
    arith_seq();
    return 0;
}

// 기능명: popo
// 내용: 포인터 값 출력 
// 입력: 없음
// 출력: 포인터 값 출력
// 오류: 없음
int arith_seq() 
{
   
    float arr[10] = { 0.1, 2.0, 3.4, 5.2, 4.5, 7.8, 9.7, 1.4, 6.6, 7.2 };

    
    float* ptr = arr;

    
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", *(ptr + i)); 
    }

    printf("\n");

    return 0;
}