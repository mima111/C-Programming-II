/*
    학번: 202411236
    이름: 윤우진
    프로그램 명: Assignment06.c

    프로그램 내용:
    정수형 배열에 대하여 배열의 원소 중 최댓값과 최솟값을 찾는 get_min_max 함수를 정의하시오.
    크기가 10인 int 배열에 대해서 원하는 값으로 초기값을 채운 다음
    get_min_max 함수로 최댓값과 최솟값을 찾아서 출력하시오.

    날짜: 20251006
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void get_min_max(int* arr, int size, int* min, int* max);

int main()
{
    int arr[10] = { 23, 45, 62, 12, 99, 83, 23, 50, 72, 37};
    int min, max;
    int size = 10;
    int i;
    
    get_min_max(arr, size, &min, &max);
    printf("배열: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n최댓값: %d\n", max);
    printf("최솟값: %d\n", min);
    

    return 0;
}

// 기능명: get_min_max
// 내용: 최댓값, 최솟값 구하고 출력
// 입력: 배열, 크기, 최댓값, 최솟값
// 출력: 최댓값 최솟값
void get_min_max(int* arr, int size, int* min, int* max)
{
    
    *min = *arr;
    *max = *arr;

    
    for (int i = 1; i < size; i++)
    {
        if (*(arr + i) < *min)
        {
            *min = *(arr + i);
        }

        if (*(arr + i) > *max)
        {
            *max = *(arr + i);
        }
    }
}