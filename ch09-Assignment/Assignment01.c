
 /*
	 학번: 202411236

	 이름: 윤우진

	 프로그램 명: Assignment01.c

	 프로그램 내용: 한 줄의 문자열을 입력받아 공백 문자(' ', '\n','\t','\f','\r','\v')
	 의 개수를 세는 프로그램을 작성하시오.

	 날짜: 20251006
 */


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



 /*
	함수명 :Assignment01
	기능(책임) : 문자열을 입력받는다.
	입력받은 문자열에서 공백문자를 찾아 몇개인지 출력해준다.
	반환 : 없음
 */
void Assignment02()
{
	int count = 0;
	char str[1000];
	printf("문자열을 입력하세요: ");
	fgets(str, sizeof(str), stdin);

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == '\v') {
			count++;
		}
	}


	printf("공백 문자 개수: %d\n", count);

}


int main()
{
	Assignment02();
	return 0;
}