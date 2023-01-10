#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define x first
#define v second
#define lowbit(x) x & (-x)
#define all(v) v.begin(), v.end()
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << (char[2][2]){" ", "\n"}[i++ == v.size() - 1])
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

template <typename T>
struct BIT
{
    int size;
    vector<T> dat;
    BIT(int n = 0) : size(n), dat(vector<T>(n + 1, 0)) {}
    void add(int i, T val)
    {
        for (; i <= size; i += lowbit(i))
            dat[i] += val;
    }
    T getSum(int i)
    {
        T sum = 0;
        for (; i; i -= lowbit(i))
            sum += dat[i];
        return sum;
    }
    T query(int l, int r) { return getSum(r) - getSum(l - 1); }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<pii> a;
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].v;
    sort(all(a));
    return 0;
}