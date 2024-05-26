#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
#pragma ide diagnostic ignored "hicpp-signed-bitwise"
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC optimize("no-stack-protector,fast-math")

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;
typedef vector<pdd> vpdd;
typedef vector<vd> vvd;
#define yn(ans) printf("%s\n", (ans) ? "Yes" : "No");
#define YN(ans) printf("%s\n", (ans) ? "YES" : "NO");
template <class T> bool chmax(T &a, T b) {
    if (a >= b)
        return false;
    a = b;
    return true;
}
template <class T> bool chmin(T &a, T b) {
    if (a <= b)
        return false;
    a = b;
    return true;
}
#define FOR(i, s, e, t) for ((i) = (s); (i) < (e); (i) += (t))
#define REP(i, e) for (int i = 0; i < (e); ++i)
#define REP1(i, s, e) for (int i = (s); i < (e); ++i)
#define RREP(i, e) for (int i = (e); i >= 0; --i)
#define RREP1(i, e, s) for (int i = (e); i >= (s); --i)
#define all(v) v.begin(), v.end()
#define pb push_back
#define qb pop_back
#define pf push_front
#define qf pop_front
#define maxe max_element
#define mine min_element
ll inf = 1e18;
#define DEBUG                                                                                                          \
    printf("%d\n", __LINE__);                                                                                          \
    fflush(stdout);
template <class T> void print(vector<T> &v, bool withSize = false) {
    if (withSize)
        cout << v.size() << endl;
    REP(i, v.size()) cout << v[i] << " ";
    cout << endl;
}
mt19937_64 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());

int __FAST_IO__ = []() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();

// O(nloglogn) prime generation, f: sum of gcd(i, j) for all 1 <= j <= i
vector<bool> is_prime;
vector<int> prime, sub;
void init_prime(int n) {
    is_prime.resize(n + 1, true);
    sub.resize(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            prime.push_back(i);
            sub[i] = i;
        }
        for (int j = 0; prime[j] * i <= n && prime[j] <= sub[i] && j < prime.size(); ++j) {
            is_prime[prime[j] * i] = false;
            sub[prime[j] * i] = prime[j];
            if (i % prime[j] == 0)
                break;
        }
    }
}

#define TESTS                                                                                                          \
    int t;                                                                                                             \
    cin >> t;                                                                                                          \
    while (t--)
#define TEST
int main() {
    int mx = 1e5;
    init_prime(mx);
    vi dp(mx + 1, 0);
    dp[1] = 1;
    for (int i = (2); i < (mx + 1); ++i) {
        int b = sub[i], c = 0, j = i;
        while (j % b == 0)
            j /= b, c++;
        dp[i] = dp[j] * (c + 1);
    }
    int mxb = *max_element(all(dp));
    TEST {
        int N, Q;
        cin >> N >> Q;
        vi v(N);
        vvi q(mxb + 1);
        for (int i = 0; i < (N); ++i) {
            cin >> v[i];
            q[dp[v[i]]].pb(i);
        }
        for (int i = 0; i < (Q); ++i) {
            int l, r;
            cin >> l >> r;
            --l, --r;
            ll ans = 0;
            REP1(j, 1, mxb + 1) {
                if (q[j].empty())
                    continue;
                auto itl = lower_bound(all(q[j]), l);
                if (itl == q[j].end() || *itl > r)
                    continue;
                auto itr = upper_bound(all(q[j]), r);
                int d = itr - itl;
                ans += 1ll * d * (d - 1) / 2;
            }
            printf("%lld\n", ans);
        }
    }

    return 0;
}
