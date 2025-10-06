
 /*
	 학번: 202411236

	 이름: 윤우진

	 프로그램 명: Assignment02.c

	 프로그램 내용: 1번 프로그램의 아이디와 패스워들를 항상 소문자로 저장하려고 한다. LOGIN 구조체를 매개변수로
	 전달받아 구조체에 저장된 아이디와 패스워드를 모두 소문자로 만드는 make_lower 함수와 아이디와 패스워드를
	 출력하는 print_login 함수를 정의하시오.

	 날짜: 20251006
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

struct LOGIN
{
	char id[800];
	char password[800];
};


struct LOGIN user;
struct LOGIN temp;


/*
	함수명 : make_lower()
	기능(책임) : 아이디와 패스워드를 소문자로 변환
	반환 : 없음
 */
void make_lower()
{
	for (int i = 0; temp.id[i] != NULL; i++)
	{
		user.id[i] = tolower(temp.id[i]);
	}
	for (int i = 0; temp.password[i] != NULL; i++)
	{
		user.password[i] = tolower(temp.password[i]);
	}

/*
	함수명 : Assignment02
	기능(책임) : 아이디와 패스워드를 입력받아 저장하고 출력
	반환 : 없음
 */
void Assignment02()
{

	printf("ID: ");
	scanf("%s", &temp.id);
	printf("PW: ");
	scanf("%s", &temp.password);

	make_lower();

	//======================
	printf("\nID : %s\n", user.id);
	printf("PW : ");
	for (int i = 0; user.password[i] != '\0'; i++)
	{
		printf("*");
	} printf("\n");

}

int main()
{
	Assignment02();
	return 0;
}