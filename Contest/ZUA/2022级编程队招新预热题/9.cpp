#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Node {
    string name;
    int score;
};
bool cmp(const Node &a, const Node &b) {
    if (a.score != b.score)
        return a.score > b.score;
    else
        return a.name < b.name;
}
int main() {
    int n;
    cin >> n;
    Node a[205];
    for (int i = 0; i < n; i++)
        cin >> a[i].name >> a[i].score;
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
        cout << a[i].name << " " << a[i].score << '\n';
    return 0;
}