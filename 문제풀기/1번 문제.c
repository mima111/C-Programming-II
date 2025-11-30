#include <stdio.h>
#include <windows.h>
#include <time.h>

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() {
    int sh, sm, ss;        // 시작 시각 (start hour, minute, second)
    int ch, cm, cs;        // 현재 시각
    int dh, dm, ds;        // 경과 시간 (difference)

    // 시작 시간 저장
    time_t start_t = time(NULL);
    struct tm* start = localtime(&start_t);

    sh = start->tm_hour;
    sm = start->tm_min;
    ss = start->tm_sec;

    while (1) {
        time_t now_t = time(NULL);
        struct tm* now = localtime(&now_t);

        ch = now->tm_hour;
        cm = now->tm_min;
        cs = now->tm_sec;

        // 경과 시간 계산 (초 단위 → 다시 시·분·초 변환)
        int elapsed = (ch * 3600 + cm * 60 + cs) - (sh * 3600 + sm * 60 + ss);
        if (elapsed < 0) elapsed += 24 * 3600;  // 자정 넘어가는 경우

        dh = elapsed / 3600;
        dm = (elapsed % 3600) / 60;
        ds = elapsed % 60;

        // 현재 시각 출력
        gotoxy(0, 0);
        printf("현재 시간 : %2d시 %2d분 %2d초   \n", ch, cm, cs);

        // 경과 시간 출력
        gotoxy(0, 1);
        printf("경과 시간 : %2d시 %2d분 %2d초   \n", dh, dm, ds);

        Sleep(1000);  // 1초마다 갱신
    }

    return 0;
}
