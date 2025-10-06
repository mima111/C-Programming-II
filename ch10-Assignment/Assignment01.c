
 /*
	 학번: 202411236

	 이름: 윤우진

	 프로그램 명: Assignment01.c

	 프로그램 내용: 인터넷 사이트에 로그인할 때 사용된 아이디와 패스워드를 관리하기 
					한 LOGIN 구조체를 정의하시오.
					아이디와 패스워드는 각각 최대 20글자까지 입력할 수 있다.
					LOIGIN 구조체 변수를 선언한 다음 아이디와 패스워드를 입력받아 저장하고 
					출력하는 프로그램을 작성하시오.
					패스워드를 출력할 때는 패스워드의 내용은 보이지 안ㅇㅎ도록 패스워드 글자 수만큼
					*을 대신 출력하시오.

	 날짜: 20251006
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


struct LOGIN
{
	char id[800];
	char password[800];
};


/*
	함수명 : void Assignment01
	기능(책임) : 아이디와 패스워드를 입력받아 저장하고 출력
	패스워드는 글자 수를 구하여 *로 출력
	반환 : 없음
 */
void Assignment02()
{
	struct LOGIN user;
	printf("ID: ");
	scanf("%s", user.id);
	printf("PW: ");
	scanf("%s", user.password);

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