#include <bits/stdc++.h>
using namespace std;
struct A
{
    int a, b, x, y, z;
    bool operator<(const A &t) const
    {
        if (a != t.a)
            return a < t.a;
        else
            return b < t.b;
    }
} aa[3];

int main()
{
    int n;
    string s;
    int a, b, x, y, z;
    vector<A> song, jv, liu;
    for (int i = 0; i < 3; i++)
    {
        scanf("%d", &n);
        while (n--)
        {
            cin >> s;
            scanf("%d %d %d %d", &b, &x, &y, &z);
            string ss = s.substr(0, s.size() - 1);
            if (ss == "song")
            {
                song.push_back({s[s.size() - 1] - '0', b, x, y, z});
                aa[0].x += x, aa[0].y += y, aa[0].z += z;
            }
            else if (ss == "jv")
            {
                jv.push_back({s[s.size() - 1] - '0', b, x, y, z});
                aa[1].x += x, aa[1].y += y, aa[1].z += z;
            }
            else if (ss == "liu")
            {
                liu.push_back({s[s.size() - 1] - '0', b, x, y, z});
                aa[2].x += x, aa[2].y += y, aa[2].z += z;
            }
        }
    }
    sort(song.begin(), song.end());
    sort(jv.begin(), jv.end());
    sort(liu.begin(), liu.end());

    printf("%d %d %d %d\n", song.size(), aa[0].x, aa[0].y, aa[0].z);
    for (auto i : song)
        printf("song%d %d %d %d %d\n", i.a, i.b, i.x, i.y, i.z);

    printf("%d %d %d %d\n", jv.size(), aa[1].x, aa[1].y, aa[1].z);
    for (auto i : jv)
        printf("jv%d %d %d %d %d\n", i.a, i.b, i.x, i.y, i.z);

    printf("%d %d %d %d\n", liu.size(), aa[2].x, aa[2].y, aa[2].z);
    for (auto i : liu)
        printf("liu%d %d %d %d %d\n", i.a, i.b, i.x, i.y, i.z);

    return 0;
}