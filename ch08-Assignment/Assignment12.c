/*
	학번: 202411236
	이름: 윤우진
	프로그램 명: Assignment12.c

	프로그램 내용:
	정수형 배열과 키 값을 매개변수로 전달받아 배열에서 키 값을 모두 찾아 인덱스를 배열에 저장해서
	리턴하는 find_all_in_array 함수를 작성하시오. 이 함수는 찾은 항목의 개수를 리턴한다.
	예를 들어 배열에서 12를 2개 찾았으면 2를 리턴하고 찾은 항목의 인덱스는 매개변수인 인덱스 배열에 저장한다.
	항목을 찾을 수 없으면 0을 리턴한다.

	날짜: 20251006
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 기능명: find_all_in_array
// 내용: 인덱스를 찾고 출력
// 입력: 찾을 항목
// 출력: 찾은 항목과 그 항목의 인덱스
int find_all_in_array(int arr[], int key, int size)
{
    int count = 0;
    int save[10] = { 0 }; 

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            save[count] = i; 
            count++;
        }
    }

    printf("찾은 항목은 모두 %d개입니다.\n", count);

    if (count > 0)
    {
        printf("찾은 항목의 인덱스: ");
        for (int i = 0; i < count; i++)
        {
            printf("%d ", save[i]);
        }
        printf("\n");
    }

    return count; 
}
// 기능명: Assignment12
// 내용: 값을 찾음
// 입력: 찾을 값
// 출력: 없음
void Assignment12()
{
    int arr[10] = { 12, 45, 62, 12, 99, 83, 23, 12, 72, 37 };
    int size = 10;
    int key;

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("찾을 값? ");
    scanf("%d", &key);

    find_all_in_array(arr, key, size);
}

int main()
{
    Assignment12();
    return 0;
}