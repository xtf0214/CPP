#include <stdio.h>
#include <string.h>
int main() {
    char s[1001];
    char res[100];
    int j = 0;
    gets(s);
    // strlen(s)-2，表示从倒数第二个字符开始遍历
    for (int i = strlen(s) - 2; i >= 0; i--) {
        if (s[i] == ' ')
            break;
        res[j++] = s[i]; // j记录的就是res的长度
    }
    if (j == 0 || ('A' <= res[j - 1] && res[j - 1] <= 'Z'))
        printf("Error");
    else {
        for (int i = j - 1; i >= 0; i--)
            printf("%c", res[i]);
    }
    return 0;
}