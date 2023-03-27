#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
bool check() {
    int x, y;
    string s;
    cin >> x >> s;
    if (s == "and") { // x and y are siblings
        cin >> y >> s >> s;
        return mp[x] / 2 == mp[y] / 2;
    } else {
        cin >> s >> s;
        if (s == "root") { // x is the root
            return mp[x] == 1;
        } else if (s == "parent") { // x is the parent of y
            cin >> s >> y;
            return mp[x] == mp[y] / 2;
        } else if (s == "child") { // x is a child of y
            cin >> s >> y;
            return mp[y] == mp[x] / 2;
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> heap;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        heap.push_back(x);
        push_heap(heap.begin(), heap.end(), greater<int>());
    }
    for (int i = 0; i < n; i++)
        mp[heap[i]] = i + 1;
    while (m--)
        puts(check() ? "T" : "F");
    return 0;
}