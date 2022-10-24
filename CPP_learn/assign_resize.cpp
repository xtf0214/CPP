#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define fi first
#define se second
#define all(v) v.begin(), v.end()
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << (char[2][2]){" ", "\n"}[i == v.size() - 1], ++i)
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int main()
{
    vi a, b;
    a.assign(7, 100);
    b.resize(7, 100);
    cout << "a.size = " << a.size() << endl;
    print(a);
    cout << "b.size = " << b.size() << endl;
    print(b);
    cout << endl;

    a.assign(4, 5);
    b.resize(4, 5);
    cout << "a.size = " << a.size() << endl;
    print(a);
    cout << "b.size = " << b.size() << endl;
    print(b);
    cout << endl;

    a.assign(10, 5);
    b.resize(10, 5);
    cout << "a.size = " << a.size() << endl;
    print(a);
    cout << "b.size = " << b.size() << endl;
    print(b);
    cout << endl;
    return 0;
}