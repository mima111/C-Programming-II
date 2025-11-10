
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int icmp(const void* a, const void* b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}


int read_dat(const char* path, int** out_arr, int* out_n) {
    FILE* fp = fopen(path, "rb");
    if (!fp) return 0;

    int n;
    if (fread(&n, sizeof(int), 1, fp) != 1 || n < 0) { fclose(fp); return 0; }

    int* a = (int*)malloc(sizeof(int) * n);
    if (!a) { fclose(fp); return 0; }

    if ((int)fread(a, sizeof(int), n, fp) != n) { free(a); fclose(fp); return 0; }
    fclose(fp);

    *out_arr = a;
    *out_n = n;
    return 1;
}


int write_dat(const char* path, const int* arr, int n) {
    FILE* fp = fopen(path, "wb");
    if (!fp) return 0;
    int ok = (fwrite(&n, sizeof(int), 1, fp) == 1) &&
        ((int)fwrite(arr, sizeof(int), n, fp) == n);
    fclose(fp);
    return ok;
}

int main(void) {
    char f1[256], f2[256], fout[256];
    int* a = NULL, * b = NULL, * c = NULL;
    int n1 = 0, n2 = 0;

    printf("첫 번째 파일명? ");
    if (scanf("%255s", f1) != 1) return 1;
    if (!read_dat(f1, &a, &n1)) { puts("읽기 실패"); return 1; }
    printf("정수 %d개를 읽었습니다.\n", n1);

    printf("두 번째 파일명? ");
    if (scanf("%255s", f2) != 1) { free(a); return 1; }
    if (!read_dat(f2, &b, &n2)) { puts("읽기 실패"); free(a); return 1; }
    printf("정수 %d개를 읽었습니다.\n", n2);

    
    int n3 = n1 + n2;
    c = (int*)malloc(sizeof(int) * n3);
    if (!c) { free(a); free(b); return 1; }
    memcpy(c, a, sizeof(int) * n1);
    memcpy(c + n1, b, sizeof(int) * n2);

    
    qsort(c, n3, sizeof(int), icmp);

    
    printf("저장할 파일명? ");
    if (scanf("%255s", fout) != 1) { free(a); free(b); free(c); return 1; }
    if (!write_dat(fout, c, n3)) { puts("저장 실패"); }

    else printf("정수 %d개를 저장했습니다.\n", n3);

    free(a); free(b); free(c);
    return 0;
}