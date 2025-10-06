/*
	 학번: 202411236

	 이름: 윤우진

	 프로그램 명: Assignment06.c

	 프로그램 내용: 시간 문자열이 유효한 시간인지 확인하는 check_time_str함수를 작성하시오.
					 예를 들어 120000은 12:00:00에 해당하는 유효한 시간문자열이지만 327892는 유효한 시간 문자열이 아니다.
					check_time_str 함수를 이용해서 입력된 문자열이 올바른 시간 문자열인지 검사해서 출력하는 프로그램을 작성하시오.


	 날짜: 20251006
 */


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


 /*
	함수명 : check_time_str()
	기능(책임) : 전달받은 문자열을 2글자씩 나누어 int형으로 바꾸어준 뒤 조건에 맞게 체크를 한다.
	반환 : 조건에 부합하지 않다면 1을 부합하다면 0을 반환한다.
 */
int check_time_str(char str[])
{
	char temp[10];
	temp[0] = str[0];
	temp[1] = str[1];
	int h = atoi(temp);
	if (h >= 25)
	{
		return 1;
	}

	temp[0] = str[2];
	temp[1] = str[3];
	int m = atoi(temp);
	if (m >= 61)
	{
		return 1;
	}

	temp[0] = str[4];
	temp[1] = str[5];
	int s = atoi(temp);
	if (s >= 61)
	{
		return 1;
	}


	return 0;

}

/*
	함수명 : Assignment06
	기능(책임) : 문자열을 입력받아 check_time_str함수를 호출해줌.
	반환 : 없음
*/
void Assignment02()
{
	char str[1000];

	while (1)
	{
		printf("시간(. 입력시 종료) : ");
		scanf("%s", str);
		if (strcmp(str, ".") == 0)
		{
			break;
		}

		else
		{
			int ck = check_time_str(str);
			if (ck == 1)
			{
				printf("잘못 입력했습니다. hhmmss형식으로 입력하세요.\n");
				continue;
			}
			else if (ck == 0)
			{
				printf("%s는 유효한 시간입니다.\n", str);
			}
			else
			{
				printf("error\n");
			}
		}

	}

}


int main()
{
	Assignment02();
	return 0;
}