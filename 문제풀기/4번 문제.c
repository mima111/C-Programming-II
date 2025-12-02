#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nation[20];
    int gold;
    int silver;
    int bronze;
} GROUP;

#define FILE_NAME "d-group.bin"

void print_all()
{
    FILE* fp;
    GROUP g;
    int cnt = 0;

    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) { printf("파일 없음\n"); return; }

    printf("\n전체 data\n");
    while (fread(&g, sizeof(GROUP), 1, fp) == 1) {
        printf("%2d : %-10s %2d %2d %2d\n",
            cnt + 1, g.nation, g.gold, g.silver, g.bronze);
        cnt++;
    }
    printf("total block number = %d\n\n", cnt);
    fclose(fp);
}

void append_data()
{
    FILE* fp;
    GROUP g;

    fp = fopen(FILE_NAME, "ab+");
    if (fp == NULL) { printf("파일 열기 실패\n"); return; }

    printf("추가할 데이터 입력 (국가명 금 은 동 순서): ");
    scanf("%s %d %d %d", g.nation, &g.gold, &g.silver, &g.bronze);

    fwrite(&g, sizeof(GROUP), 1, fp);
    fclose(fp);
    printf("추가 완료!\n\n");
}

void print_block()
{
    FILE* fp;
    GROUP g;
    int pos;

    fp = fopen(FILE_NAME, "rb");
    if (fp == NULL) { printf("파일 열기 실패\n"); return; }

    printf("출력할 block 번호 입력: ");
    scanf("%d", &pos);

    fseek(fp, (pos - 1) * sizeof(GROUP), SEEK_SET);
    fread(&g, sizeof(GROUP), 1, fp);
    fclose(fp);

    printf("%d block → %s %d %d %d\n\n",
        pos, g.nation, g.gold, g.silver, g.bronze);
}

void modify_block()
{
    FILE* fp;
    GROUP g;
    int pos;

    fp = fopen(FILE_NAME, "r+b");
    if (fp == NULL) { printf("파일 열기 실패\n"); return; }

    printf("변경할 block 번호 입력: ");
    scanf("%d", &pos);

    printf("변경할 내용 입력 (국가명 금 은 동 순서): ");
    scanf("%s %d %d %d", g.nation, &g.gold, &g.silver, &g.bronze);

    fseek(fp, (pos - 1) * sizeof(GROUP), SEEK_SET);
    fwrite(&g, sizeof(GROUP), 1, fp);
    fclose(fp);

    printf("변경 완료!\n\n");
}

void delete_block() 
{
    FILE* fp, * temp;
    GROUP g;
    int pos, idx = 1;

    fp = fopen(FILE_NAME, "rb");
    if (!fp) { printf("파일 없음\n"); return; }

    printf("삭제할 block 번호 입력: ");
    scanf("%d", &pos);

    temp = fopen("temp.bin", "wb");
    while (fread(&g, sizeof(GROUP), 1, fp) == 1) {
        if (idx != pos)
            fwrite(&g, sizeof(GROUP), 1, temp);
        idx++;
    }
    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.bin", FILE_NAME);
    printf("삭제 완료!\n\n");
}

int main()
{
    int menu;

    while (1) {
        printf("1. 전체 데이터 출력\n");
        printf("2. 데이터 추가\n");
        printf("3. 해당 block 출력\n");
        printf("4. 해당 block의 데이터 변경\n");
        printf("5. 해당 block의 데이터 삭제\n");
        printf("6. 종료\n");
        printf("번호 선택 후 Enter> ");
        scanf("%d", &menu);

        switch (menu) {
        case 1: print_all(); break;
        case 2: append_data(); break;
        case 3: print_block(); break;
        case 4: modify_block(); break;
        case 5: delete_block(); break;
        case 6: return 0;
        default: printf("잘못 입력\n\n");
        }
    }
}
