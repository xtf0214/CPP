#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#include <DEBUG.h>

int main() {
    int a = 1;
    double pi = acos(-1);
    char c = 'c';
    vector<int> v{1, 2, 3};
    vector<vector<int>> matrix{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    map<int, int> cnt{{1, 2}, {2, 4}};
    set<int> st{1, 2, 3, 4};
    Log(a, pi, c, v);
    Log(matrix);
    Log(cnt);
    Log(st);
    return 0;
}