#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;

struct datas
{
    int a, b, c;
    datas(int a = 0, int b = 0, int c = 0) : a(a), b(b), c(c) {}
};
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // 提前申请空间 840ms
    // vector<datas> arr(N);
    // for (int i = 0; i < N; i++)
    // {
    //     arr[i].a = i, arr[i].b = i, arr[i].c = i;
    //     //arr[i] = {i, i, i};
    //     //arr[i] = datas(i, i, i);
    // }

    // 临时申请空间 1940ms
    // vector<datas> arr;
    // for (int i = 0; i < N; i++)
    // {
    //     // arr.push_back({i, i, i});
    //     // arr.emplace_back(i, i, i);
    //     arr.push_back(datas(i, i, i));
    // }
    return 0;
}
