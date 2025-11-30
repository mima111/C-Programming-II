#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char hakbun[10];
    char name[20];
    int  dept;
    int  mid;
    int  final;
    int  report;
    int  attend;
    double total;
} STUDENT;

#define FILE_NAME "hakbun.bin"

double get_total(STUDENT s)
{
    return s.mid * 0.3 + s.final * 0.4 + s.report + s.attend;
}

int get_count()
{
    FILE* fp;
    int count;
    fp = fopen(FILE_NAME, "rb");
    if (!fp) return 0;
    fseek(fp, 0, SEEK_END);
    count = ftell(fp) / sizeof(STUDENT);
    fclose(fp);
    return count;
}

void read_all(STUDENT* arr, int n)
{
    FILE* fp = fopen(FILE_NAME, "rb");
    fread(arr, sizeof(STUDENT), n, fp);
    fclose(fp);
}

void write_all(STUDENT* arr, int n)
{
    FILE* fp = fopen(FILE_NAME, "wb");
    fwrite(arr, sizeof(STUDENT), n, fp);
    fclose(fp);
}

void print_header()
{
    printf("NO 학번      이름     학과  중간 기말 리포트 출석 총점\n");
}

void print_one(STUDENT s, int idx)
{
    printf("%2d %-10s %-6s %2d %3d %4d %7d %3d %7.2f\n",
        idx + 1, s.hakbun, s.name, s.dept, s.mid,
        s.final, s.report, s.attend, s.total);
}

void display(int mode) // 1 이름, 2 학번, 3 학과, 4 총점
{
    int n = get_count();
    if (n == 0) { printf("데이터 없음\n"); return; }

    STUDENT* a = malloc(sizeof(STUDENT) * n);
    read_all(a, n);

    for (int i = 1; i < n; i++) {
        STUDENT t = a[i];
        int j = i - 1;
        while (j >= 0) {
            int cond;
            if (mode == 1) cond = strcmp(a[j].name, t.name) > 0;
            else if (mode == 2) cond = strcmp(a[j].hakbun, t.hakbun) > 0;
            else if (mode == 3) cond = a[j].dept > t.dept;
            else cond = a[j].total < t.total;
            if (!cond) break;
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = t;
    }

    print_header();
    for (int i = 0; i < n; i++) print_one(a[i], i);
    free(a);
    printf("\n");
}

void display_all()
{
    int n = get_count();
    STUDENT* a = malloc(sizeof(STUDENT) * n);
    read_all(a, n);
    print_header();
    for (int i = 0; i < n; i++) print_one(a[i], i);
    free(a);
}

void add_data()
{
    STUDENT s;
    printf("학번 이름 학과번호 중간 기말 리포트 출석 입력: ");
    scanf("%s %s %d %d %d %d %d",
        s.hakbun, s.name, &s.dept, &s.mid, &s.final, &s.report, &s.attend);
    s.total = get_total(s);

    FILE* fp = fopen(FILE_NAME, "ab");
    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);
    printf("추가 완료!\n\n");
}

void search()
{
    int sub;
    int n = get_count();
    STUDENT* a = malloc(sizeof(STUDENT) * n);
    read_all(a, n);

    printf("3.1 이름검색  3.2 학번검색  3.3 학과검색  3.4 block 검색 선택> ");
    scanf("%d", &sub);

    if (sub == 1) {
        char key[20];
        printf("이름 입력: "); scanf("%s", key);
        for (int i = 0; i < n; i++)
            if (strcmp(a[i].name, key) == 0) print_one(a[i], i);
    }
    else if (sub == 2) {
        char key[20];
        printf("학번 입력: "); scanf("%s", key);
        for (int i = 0; i < n; i++)
            if (strcmp(a[i].hakbun, key) == 0) print_one(a[i], i);
    }
    else if (sub == 3) {
        int key;
        printf("학과 번호 입력: "); scanf("%d", &key);
        for (int i = 0; i < n; i++)
            if (a[i].dept == key) print_one(a[i], i);
    }
    else {
        int pos;
        printf("block 번호 입력: "); scanf("%d", &pos);
        if (pos >= 1 && pos <= n) print_one(a[pos - 1], pos - 1);
    }
    free(a);
    printf("\n");
}

void modify()
{
    int sub;
    printf("4.1 이름수정 4.2 학번수정 4.3 block 수정 선택> ");
    scanf("%d", &sub);

    int n = get_count();
    STUDENT* a = malloc(sizeof(STUDENT) * n);
    read_all(a, n);

    int idx = -1;

    if (sub == 1) {
        char key[20];
        printf("이름 입력: "); scanf("%s", key);
        for (int i = 0; i < n; i++)
            if (strcmp(a[i].name, key) == 0) idx = i;
    }
    else if (sub == 2) {
        char key[20];
        printf("학번 입력: "); scanf("%s", key);
        for (int i = 0; i < n; i++)
            if (strcmp(a[i].hakbun, key) == 0) idx = i;
    }
    else {
        printf("block 번호 입력: "); scanf("%d", &idx);
        idx -= 1;
    }

    if (idx < 0 || idx >= n) {
        printf("검색 실패\n\n");
        free(a);
        return;
    }

    printf("새로운 정보 (학번 이름 학과 중간 기말 리포트 출석 입력): ");
    scanf("%s %s %d %d %d %d %d",
        a[idx].hakbun, a[idx].name, &a[idx].dept, &a[idx].mid,
        &a[idx].final, &a[idx].report, &a[idx].attend);
    a[idx].total = get_total(a[idx]);

    write_all(a, n);
    free(a);
    printf("수정 완료!\n\n");
}

int main()
{
    int menu, sub;

    while (1) {
        printf("1. 데이터 출력\n");
        printf("2. 데이터 추가\n");
        printf("3. 데이터 검색\n");
        printf("4. 데이터 수정\n");
        printf("5. 종료\n");
        printf("선택> ");
        scanf("%d", &menu);

        switch (menu) {
        case 1:
            printf("1.1 전체  1.2 이름정렬  1.3 학번정렬  1.4 학과정렬  1.5 총점정렬 선택> ");
            scanf("%d", &sub);
            if (sub == 1) display_all();
            else display(sub - 1);
            break;
        case 2: add_data(); break;
        case 3: search(); break;
        case 4: modify(); break;
        case 5: return 0;
        }
    }
}
