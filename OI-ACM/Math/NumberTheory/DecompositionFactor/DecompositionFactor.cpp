#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5;

vector<int> getPrimeFactor(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            int cnt = 0;
            while (n % i == 0)
                n /= i, cnt++;
            res.push_back(i);
        }
    if (n != 1)
        res.push_back(n);
    return res;
}