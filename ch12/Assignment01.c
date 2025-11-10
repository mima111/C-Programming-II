#include <stdio.h>
#include <stdlib.h>

void print_file_with_line_numbers(const char* filename) {
    FILE* file = fopen(filename, "r"); 
    if (file == NULL) {
        printf("파일 '%s'을(를) 열 수 없습니다.\n", filename);
        return;
    }

    char line[1024];  
    int line_number = 1;

    
    while (fgets(line, sizeof(line), file)) {
        printf("%d: %s", line_number, line);
        line_number++;
    }

    fclose(file); 
}

int main() {
    char filename[256];  

    printf("파일명? ");
    scanf("%s", filename); 

    print_file_with_line_numbers(filename); 

    return 0;
}