#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char phone[20];
    int  year;
} PERSON;


void make_data(void)
{
    FILE* fp;
    PERSON data[5] = {
        {"Kim",   "017-763-1243", 1987},
        {"Lee",   "019-299-8734", 1988},
        {"Park1", "010-8023-3324", 1987},
        {"Han",   "019-8765-2764", 1989},
        {"Park2", "010-2208-9983", 1987}
    };

    fp = fopen("person.bin", "wb");
    if (fp == NULL) {
        perror("person.bin");
        return;
    }

    fwrite(data, sizeof(PERSON), 5, fp);
    fclose(fp);
    printf("📌 person.bin 파일 생성 완료\n\n");
}


void sort_data(void)
{
    FILE* fp;
    PERSON* d, temp;
    int total_block;
    int i, j;

    fp = fopen("person.bin", "rb");
    if (fp == NULL) {
        perror("person.bin");
        return;
    }

    fseek(fp, 0, SEEK_END);
    total_block = ftell(fp) / sizeof(PERSON);
    rewind(fp);

    d = (PERSON*)malloc(total_block * sizeof(PERSON));
    if (d == NULL) {
        printf("메모리 할당 실패\n");
        fclose(fp);
        return;
    }

    fread(d, sizeof(PERSON), total_block, fp);
    fclose(fp);

   
    for (j = 0; j < total_block; j++) {
        temp = d[j];
        i = j;
        while (i > 0 && strcmp(d[i - 1].name, temp.name) > 0) {
            d[i] = d[i - 1];
            i--;
        }
        d[i] = temp;
    }

    
    printf("📌 [이름으로 정렬하여 출력한 결과]\n");
    printf("%-10s %-15s %4s\n", "이름", "휴대번호", "생년");
    for (i = 0; i < total_block; i++) {
        printf("%-10s %-15s %4d\n", d[i].name, d[i].phone, d[i].year);
    }

    free(d);
}


int main(void)
{
    make_data();   
    sort_data();   
    return 0;
}
