#include <bits/stdc++.h>
using namespace std;
int main()
{
    int height[2] = {129, 130};
    int weight[2] = {25, 27};
    int n, male, h, w;
    cin >> n;
    while (n--)
    {
        cin >> male >> h >> w;
        if (h > height[male])
            printf("ni li hai!");
        else if (h == height[male])
            printf("wan mei!");
        else
            printf("duo chi yu!");

        if (w > weight[male])
            printf("shao chi rou!");
        else if (w == weight[male])
            printf("wan mei!");
        else
            printf("duo chi rou!");
        printf("\n");
    }

    return 0;
}