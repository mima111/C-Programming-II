
 /*
	 학번: 202411236

	 이름: 윤우진

	 프로그램 명: Assignment03.c

	 프로그램 내용: LOGIN 구조체 배열을 이용해서 로그인 과정을 프로그램으로 작성하시오.
	 아이디를 입력받아 LOGIN 구조체 배열에서 아이디를 찾은 다음 입력받은 패스워드와 등록된 
	 패스워드를 비교해서 같으면 "로그인 성공" 이라고 출력한다. LOGIN 구조체 배열은 크기가
	 5인 배열로 선언하고 적당한 값으로 초기화해서 사용한다.

	 날짜: 20251006
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct LOGIN
{
	char id[800];
	char password[800];
};
struct LOGIN user;

/*
	함수명 : check
	기능(책임) : 아이디와 패스워드를 비교하여 로그인 성공/실패 출력
	반환 : 없음
 */
void check()
{
	if (strcmp(user.id, "guest") == 0 && strcmp(user.password, "idontknow") == 0)
	{
		printf("로그인 성공!\n");
	}
	else
	{
		printf("로그인 실패!\n");
	}
}

/*
	함수명 : Assignment03
	기능(책임) : 아이디와 패스워드를 입력받아 저장하고 check 호출
	반환 : 없음
 */
void Assignment03()
{

	printf("ID: ");
	scanf("%s", &user.id);
	printf("PW: ");
	scanf("%s", &user.password);

	check();
}

int main()
{
	Assignment03();
	return 0;
}