
/* 파일명: Assignment17.c

    내용: 입력받은 노래 제목을 최대 20개 저장하고 관리하는 프로그램을 작성하시오.
    노래 제목의 길이는 최대 40글자라고 가정한다. 간단한 메뉴로 노래 제목을 추가하는 기능,
    노래 제목을 수정하는 기능, 노래 목록을 출력하는 기능을 제공한다.
    
    작성자: 윤우진
    
    날짜: 20251006
 */


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char songs[20][41] = { "" }; 

/*
    함수명 : add_song
    기능(책임) : 노래 제목을 추가
    반환 : 없음
 */
void add_song(int* count)
{
    if (*count >= 20)
    {
        printf("더 이상 노래를 추가할 수 없습니다.\n");
        return;
    }
    else
    {
        char tempname[41];
        printf("노래 제목 ? ");
        getchar(); 
        fgets(tempname, sizeof(tempname), stdin);

     
        tempname[strcspn(tempname, "\n")] = '\0';

        strcpy(songs[*count], tempname);
        (*count)++;
    }
}

/*
    함수명 : edit_song
    기능(책임) : 등록된 노래 제목을 수정
    반환 : 없음
 */
void edit_song(int count)
{
    if (count == 0)
    {
        printf("등록된 노래가 없습니다.\n");
        return;
    }

    char tempname[41];
    printf("찾을 노래 제목? ");
    getchar(); 
    fgets(tempname, sizeof(tempname), stdin);
    tempname[strcspn(tempname, "\n")] = '\0';

    for (int i = 0; i < count; i++)
    {
        if (strcmp(songs[i], tempname) == 0)
        {
            printf("수정할 제목? ");
            fgets(tempname, sizeof(tempname), stdin);
            tempname[strcspn(tempname, "\n")] = '\0';
            strcpy(songs[i], tempname);
            printf("수정 완료!\n");
            return;
        }
    }
    printf("찾는 노래가 없습니다.\n");
}

/*
    함수명 : list_songs
    기능(책임) : 등록된 노래 제목을 모두 출력
    반환 : 없음
 */
void list_songs(int count)
{
    if (count == 0)
    {
        printf("등록된 노래가 없습니다.\n");
        return;
    }
    else
    {
        printf("<< 노래 목록 >>\n");
        for (int i = 0; i < count; i++)
        {
            printf("%d. %s\n", i + 1, songs[i]);
        }
    }
}

/*
    함수명 : void Assignment17
    기능(책임) : 메뉴를 출력해주고 사용자의 선택에 따라 노래 추가, 수정, 목록 출력 기능을 처리
    반환 : 없음
 */
void Assignment02()
{
    int mc;
    int count = 0;
    while (1)
    {
        printf("\n노래 수 : %d\n", count);
        printf("[ 0.종료 1.추가 2.수정 3.목록 ] 선택? ");
        scanf("%d", &mc);

        switch (mc)
        {
        case 0:
            printf("프로그램 종료\n");
            return;

        case 1:
            add_song(&count);
            continue;

        case 2:
            edit_song(count);
            continue;

        case 3:
            list_songs(count);
            continue;

        default:
            printf("잘못된 선택입니다.\n");
            continue;
        }
    }
}

int main()
{
    Assignment02();
    return 0;
}