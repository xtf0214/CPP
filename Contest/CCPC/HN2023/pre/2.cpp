#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define print(v) for (auto it = v.begin(); it != v.end(); cout << *it << " \n"[next(it++) == v.end()])
#define dbg(x) cerr << "\033[0;31m" << #x << " = " << x << ";\033[0m"
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;


int main() {
    int n;
    // int out[]{5,3,4};
    int i=0;
    cin >> n;
    int l = 1, r = n + 1;
    while(r - l > 1) {
        int m = (l + r) / 2;
        // m = out[i++];
        cout << m << endl;
        cout.flush();
        string in;
        cin >> in;
        if(in == "<")
            r = m;
        else l = m;
        // dbg(l);
        // dbg(r) << endl;
    }
    cout << "! " << l << endl;
    cout.flush();
    return 0;
}