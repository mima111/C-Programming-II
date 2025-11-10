#include <stdio.h>
#include <string.h>

#define MAX 10
#define LEN 30

typedef struct {
    char id[LEN];
    char pw[LEN];
} LOGIN;

int main() {
    LOGIN user[MAX];
    FILE* fp;
    int count = 0;
    char input_id[LEN], input_pw[LEN];
    int found = 0;

    fp = fopen("password.txt", "r");
    if (fp == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }


    while (fscanf(fp, "%s %s", user[count].id, user[count].pw) != EOF && count < MAX) {
        count++;
    }
    fclose(fp);


    printf("ID? ");
    scanf("%s", input_id);

    
    for (int i = 0; i < count; i++) {
        if (strcmp(input_id, user[i].id) == 0) {
            found = 1;

           
            printf("Password? ");
            scanf("%s", input_pw);

            if (strcmp(input_pw, user[i].pw) == 0) {
                printf("로그인 성공\n");
            }
            else {
                printf("로그인 실패\n");
            }
            break;
        }
    }

    if (!found) {
        printf("아이디를 찾을 수 없습니다.\n");
    }

    return 0;
}