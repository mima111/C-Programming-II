#include <stdio.h>
#include <ctype.h>

int main(void) {
    char fname[256];
    int cnt[26] = { 0 };
    FILE* fp;
    int ch;

    printf("파일명? ");
    if (scanf("%255s", fname) != 1) {
        fprintf(stderr, "파일명 입력 오류\n");
        return 1;
    }

    fp = fopen(fname, "r");
    if (!fp) {
        fprintf(stderr, "파일을 열 수 없습니다: %s\n", fname);
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha((unsigned char)ch)) {
            ch = tolower((unsigned char)ch);
            cnt[ch - 'a']++;
        }
    }
    fclose(fp);

    
    int printed = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) {
            printf("%c:%d  ", 'a' + i, cnt[i]);
            printed++;
            if (printed % 10 == 0) puts("");
        }
    }
    if (printed % 10 != 0) puts(""); 

    return 0;
}