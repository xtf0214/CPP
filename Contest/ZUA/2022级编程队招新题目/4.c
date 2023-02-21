#include <stdio.h>

int main() {
    int y;
    char s[12][8] = {"鼠", "牛", "虎", "兔", "龙", "蛇", "马", "羊", "猴", "鸡", "狗", "猪"};
    scanf("%d", &y);
    int ans = (y - 2020) % 12;
    if (ans < 0)
        ans = (ans + 12) % 12;
    printf("%d是%s年", y, s[ans]);
    return 0;
    
}
