#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
template <typename T> using vT = vector<T>;
template <typename T> using vvT = vector<vector<T>>;
#define y first
#define x second
#define all(v) v.begin(), v.end()
#define lowbit(x) x & (-x)
#define print(v) for (int i = 0; i < v.size(); cout << v[i] << " \n"[i++ == v.size() - 1])
const int vec[4][2]{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
const int N = 1e6 + 5, INF = 0x3f3f3f3f, mod = 1e9 + 7;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minimumOperations(TreeNode* root) {
                
    }
};
int main()
{
    Solution res;
    vector<int> nums{};
    return 0;
}