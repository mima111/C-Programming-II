
 /*
	 학번: 202411236

	 이름: 윤우진

	 프로그램 명: Assignment14.c

	 프로그램 내용: 인터넷 사이트에 회원 가입을 하려는 사용자로부터 아이디를 입력받아 유요한 아이디인지 검사하는 프로그램을 작성하시오.
 					아이디는 영문자로 시작해야 하고, 영문자와 숫자로만 구성되며 최소 8자가 되어야 한다.

	 날짜: 20251006
 */


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

 /*
	함수명 : check
	기능(책임) : 전달받은 스트링값을 조건에 맞는지 확인하고 조건에 맞게 반환을 해준다.
	반환 : 조건에 부합:0 그렇지 않음:1
 */

int check(char str[])
{

	if (isalpha(str[0]) == 0)
	{
		printf("ID는 영문자로 시작해야 합니다.\n");
		return 1;
	}

	if (strlen(str) < 8)
	{
		printf("ID는 8자 이상이여야 합니다.\n");
		return 1;
	}

	for (int i = 0; i < strlen(str); i++) {
		if (!isalnum(str[i])) {
			printf("ID는 영문자와 숫자로만 구성되어야 합니다.\n");
			return 1;
		}
	}

	return 0;
}

/*
	함수명 : Assignment14
	기능(책임) : 아이디를 입력받고 조건을 체크해주는 함수를 호출해준다.
	반환 : 없음
*/
void Assignment02()
{
	char str[1000];

	while (1)
	{
		printf("ID? ");
		scanf("%s", str);

		int ck = check(str);
		if (ck == 1)
		{
			continue;
		}
		else if (ck == 0)
		{
			printf("%s는 ID로 사용할 수 있습니다.\n", str);
			continue;
		}
		else
		{
			printf("error\n");
			continue;
		}

	}


}


int main()
{
	Assignment02();
	return 0;
}