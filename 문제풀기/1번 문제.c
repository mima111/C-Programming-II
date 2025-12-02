#include <stdio.h>
#include <windows.h>
#include <time.h>

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() {
    int sh, sm, ss;        
    int ch, cm, cs;        
    int dh, dm, ds;        

    
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

        
        int elapsed = (ch * 3600 + cm * 60 + cs) - (sh * 3600 + sm * 60 + ss);
        if (elapsed < 0) elapsed += 24 * 3600;  

        dh = elapsed / 3600;
        dm = (elapsed % 3600) / 60;
        ds = elapsed % 60;

       
        gotoxy(0, 0);
        printf("현재 시간 : %2d시 %2d분 %2d초   \n", ch, cm, cs);

       
        gotoxy(0, 1);
        printf("경과 시간 : %2d시 %2d분 %2d초   \n", dh, dm, ds);

        Sleep(1000);  
    }

    return 0;
}
