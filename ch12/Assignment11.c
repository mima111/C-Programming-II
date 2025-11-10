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

    
    printf("연락처 파일명? ");
    if (scanf("%255s", fname) != 1) {
        fprintf(stderr, "파일명 입력 오류\n");
        return 1;
    }

    fp = fopen(fname, "r");
    if (!fp) {
        fprintf(stderr, "파일을 열 수 없습니다: %s\n", fname);
        return 1;
    }

    
    size_t cap = 8;          
    size_t n = 0;           
    CONTACT* book = (CONTACT*)malloc(sizeof(CONTACT) * cap);
    if (!book) { fclose(fp); return 1; }

   
 
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        
        if (line[0] == '#' || line[0] == '\n') continue;

        CONTACT tmp;
        if (sscanf(line, "%63s %63s", tmp.name, tmp.phone) == 2) {
            if (n == cap) { 
                cap *= 2;
                CONTACT* nb = (CONTACT*)realloc(book, sizeof(CONTACT) * cap);
                if (!nb) { free(book); fclose(fp); return 1; }
                book = nb;
            }
            book[n++] = tmp;
        }
    }
    fclose(fp);

    printf("%zu개의 연락처를 로딩했습니다.\n", n);

    
    while (1) {
        char query[NAME_LEN];
        printf("이름(. 입력 시 종료)? ");
        if (scanf("%63s", query) != 1) break;
        if (strcmp(query, ".") == 0) break;

        
        size_t i;
        int found = 0;
        for (i = 0; i < n; i++) {
            if (strcmp(query, book[i].name) == 0) {
                printf("%s의 전화번호 %s로 전화를 겁니다....\n",
                    book[i].name, book[i].phone);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("연락처를 찾을 수 없습니다.\n");
        }
    }

    free(book);
    return 0;
}