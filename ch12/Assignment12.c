
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 64
#define PHONE_LEN 64

typedef struct {
    char name[NAME_LEN];
    char phone[PHONE_LEN];
} CONTACT;

int main(void) {
    char fname[256];
    FILE* fp;
    size_t cap = 8, n = 0;
    CONTACT* book = malloc(sizeof(CONTACT) * cap);
    if (!book) return 1;

    printf("연락처 파일명? ");
    if (scanf("%255s", fname) != 1) return 1;


    fp = fopen(fname, "r");
    if (!fp) { printf("파일을 열 수 없습니다: %s\n", fname); free(book); return 1; }
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        CONTACT tmp;
        if (sscanf(line, "%63s %63s", tmp.name, tmp.phone) == 2) {
            if (n == cap) { cap *= 2; CONTACT* nb = realloc(book, sizeof(CONTACT) * cap); if (!nb) { free(book); fclose(fp); return 1; } book = nb; }
            book[n++] = tmp;
        }
    }
    fclose(fp);
    printf("%zu개의 연락처를 로딩했습니다.\n", n);

  
    while (1) {
        char q[NAME_LEN];
        printf("이름(. 입력 시 종료)? ");
        if (scanf("%63s", q) != 1) break;
        if (strcmp(q, ".") == 0) break;

        int idx = -1;
        for (size_t i = 0; i < n; i++) if (strcmp(q, book[i].name) == 0) { idx = (int)i; break; }

        if (idx != -1) {
            printf("%s의 전화번호 %s로 전화를 겁니다....\n", book[idx].name, book[idx].phone);
        }
        else {
            printf("연락처를 찾을 수 없습니다. 연락처를 등록하시겠습니까?(y/n)? ");
            char yn[8]; scanf("%7s", yn);
            if (yn[0] == 'y' || yn[0] == 'Y') {
                CONTACT tmp; strncpy(tmp.name, q, NAME_LEN);
                printf("전화번호? "); scanf("%63s", tmp.phone);
                if (n == cap) { cap *= 2; CONTACT* nb = realloc(book, sizeof(CONTACT) * cap); if (!nb) { free(book); return 1; } book = nb; }
                book[n++] = tmp;
            }
        }
    }

    
    fp = fopen(fname, "w");
    if (!fp) { printf("저장 실패\n"); free(book); return 1; }
    for (size_t i = 0; i < n; i++) fprintf(fp, "%s %s\n", book[i].name, book[i].phone);
    fclose(fp);
    printf("%s에 %zu개의 연락처를 저장했습니다.\n", fname, n);

    free(book);
    return 0;
}