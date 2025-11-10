
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int N;
    char base[256];

    printf("정수의 개수? ");
    if (scanf("%d", &N) != 1 || N <= 0) { puts("잘못된 N"); return 1; }
    printf("파일명? ");
    if (scanf("%255s", base) != 1) return 1;

    int* a = malloc(sizeof(int) * N);
    if (!a) return 1;

    srand((unsigned)time(NULL));
    for (int i = 0; i < N; i++) a[i] = rand() % 1000;  

    
    char txt[300], dat[300];
    snprintf(txt, sizeof(txt), "%s.txt", base);
    snprintf(dat, sizeof(dat), "%s.dat", base);

    FILE* fp = fopen(txt, "w");
    if (!fp) { free(a); return 1; }
    for (int i = 0; i < N; i++) {
        fprintf(fp, "%d", a[i]);
        if (i + 1 < N) fputc(i % 20 == 19 ? '\n' : ' ', fp); 
    }
    fputc('\n', fp);
    fclose(fp);

    
    fp = fopen(dat, "wb");
    if (!fp) { free(a); return 1; }
    fwrite(&N, sizeof(int), 1, fp);
    fwrite(a, sizeof(int), N, fp);
    fclose(fp);

    printf("%s와 %s를 생성했습니다.\n", txt, dat);

    free(a);
    return 0;
}