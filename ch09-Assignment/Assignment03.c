
 /*
     학번: 202411236

     이름: 윤우진

     프로그램 명: Assignment03.c

     프로그램 내용: 입력받은 문자열의 소문자는 대문자로, 대문자는 소문자로 변환하는 프로그램을 작성하시오.


     날짜: 20251006
 */


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

 /*
    함수명 : Assignment03
    기능(책임) : 문자열을 입력받고 대소문자 변환을 한다.
    반환 : 없음
 */
void Assignment03()
{
    char str[1000];
    printf("문자열? ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (islower(str[i])) {
            str[i] = toupper(str[i]);
        }
        else if (isupper(str[i])) {
            str[i] = tolower(str[i]);
        }

    }

    printf("변환 후: %s", str);

}


int main()
{
    Assignment03();
    return 0;
}