#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <time.h>

int get_year_prefix(char gender_code) {
    // 1,2 : 1900년대
    // 3,4 : 2000년대
    if (gender_code == '1' || gender_code == '2') return 1900;
    if (gender_code == '3' || gender_code == '4') return 2000;
    return 1900; // 기본값
}

const char* zodiac(int year) {
    char* animals[] = {
        "원숭이", "닭", "개", "돼지", "쥐", "소",
        "호랑이", "토끼", "용", "뱀", "말", "양"
    };
    return animals[year % 12];
}

int main() {
    char jumin[20];
    int yy, mm, dd;
    char gender_code;
    char gender[10];
    const char* ddi;

    printf("주민등록번호 13자리를 '-' 없이 입력하고 Enter\n");
    printf("주민번호: ");
    scanf("%s", jumin);

    // 입력 검사
    if (strlen(jumin) != 13) {
        printf("잘못된 입력입니다. 13자리를 입력하세요.\n");
        return 0;
    }

    // 생년월일 추출
    gender_code = jumin[6];
    int prefix = get_year_prefix(gender_code);

    yy = prefix + ((jumin[0] - '0') * 10 + (jumin[1] - '0'));
    mm = (jumin[2] - '0') * 10 + (jumin[3] - '0');
    dd = (jumin[4] - '0') * 10 + (jumin[5] - '0');

    // 성별 판별
    if (gender_code == '1' || gender_code == '3') strcpy(gender, "남");
    else if (gender_code == '2' || gender_code == '4') strcpy(gender, "여");
    else strcpy(gender, "알수없음");

    // 띠 계산
    ddi = zodiac(yy);

    // ──────────────────────────────────────
    //            만 나이 계산
    // ──────────────────────────────────────
    time_t now = time(NULL);
    struct tm* t = localtime(&now);

    int age = t->tm_year + 1900 - yy;

    if ((t->tm_mon + 1 < mm) ||
        (t->tm_mon + 1 == mm && t->tm_mday < dd)) {
        age -= 1;
    }

    // ──────────────────────────────────────
    //               출력
    // ──────────────────────────────────────
    printf("\n생년월일과 성별, 띠, 만 나이 계산\n\n");

    // 주민등록번호 출력 (앞 6자리 + '-' + 뒤 7자리는 '*')
    printf("주민 등록번호: %.6s-*******\n", jumin);

    printf("생년 월일   : %4d년 %d월 %d일\n", yy, mm, dd);
    printf("성별        : %s\n", gender);
    printf("띠          : %s\n", ddi);
    printf("만 나이     : %d\n", age);

    return 0;
}
