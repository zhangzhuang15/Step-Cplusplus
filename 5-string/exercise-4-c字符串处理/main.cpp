#include <stdio.h>
#include <string.h>

int main() {

    // strtok    ✅修改原字符串    
    printf("strok to seperate the string\n");
    char text[] = "2022-01-19";
    char* s = text;
    char* separate = strtok(s, "-");
    for (int i = 1; separate != NULL; i++) {
        printf("%d. %s\n", i, separate);
        separate = strtok(NULL, "-");
    }
    printf("origin string: %s\n", s); //  s 已经被修改了!!!!
    printf("------ end line ------\n\n");

}