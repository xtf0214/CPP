#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Nation
{
    int gold, score, population, id;
    double ave_gold, ave_score;
    int rank[5], best = 1;
    int bestRank()
    {
        for (int i = 2; i <= 4; i++)
            if (rank[i] < rank[best])
                best = i;
        return rank[best] + 1;
    }

} nation[230];
bool cmp0(const Nation &a, const Nation &b) { return a.id < b.id; }
bool cmp1(const Nation &a, const Nation &b)
{
    if (a.gold != b.gold)
        return a.gold > b.gold;
    else
        return a.id < b.id;
}
bool cmp2(const Nation &a, const Nation &b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else
        return a.id < b.id;
}
bool cmp3(const Nation &a, const Nation &b)
{
    if (a.ave_gold != b.ave_gold)
        return a.ave_gold > b.ave_gold;
    else
        return a.id < b.id;
}
bool cmp4(const Nation &a, const Nation &b)
{
    if (a.ave_score != b.ave_score)
        return a.ave_score > b.ave_score;
    else
        return a.id < b.id;
}
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> nation[i].gold >> nation[i].score >> nation[i].population;
        nation[i].ave_gold = (double)nation[i].gold / nation[i].population;
        nation[i].ave_score = (double)nation[i].score / nation[i].population;
        nation[i].id = i;
    }
    sort(nation, nation + n, cmp1);
    for (int i = 0; i < n; i++)
        nation[i].rank[1] = i;

    sort(nation, nation + n, cmp2);
    for (int i = 0; i < n; i++)
        nation[i].rank[2] = i;

    sort(nation, nation + n, cmp3);
    for (int i = 0; i < n; i++)
        nation[i].rank[3] = i;

    sort(nation, nation + n, cmp4);
    for (int i = 0; i < n; i++)
        nation[i].rank[4] = i;

    sort(nation, nation + n, cmp0);

    for (int i = 0, t; i < m; i++)
    {
        cin >> t;
        if (i)
            cout << " ";
        cout << nation[t].bestRank() << ":" << nation[t].best;
    }
    return 0;
}