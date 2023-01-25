#include <bits/stdc++.h>
using namespace std;
class SegmentTree
{
private:
    int n;
    vector<int> st;
    void build(vector<int> &nums)
    {
        for (int i = n; i < n * 2; ++i)
            st[i] = nums[i - n]; // 叶子
        for (int i = n - 1; i >= 1; --i)
            st[i] = st[i << 1] + st[i << 1 | 1];
        // st[i << 1]和st[(i << 1)|1]分别表示左右孩子
    }

public:
    SegmentTree(vector<int> &nums)
    {
        n = nums.size();
        st = vector<int>(2 * n, 0);
        build(nums);
    }
    void update(int i, int val)
    {
        st[i += n] = val; // 转成到st的下标
        for (; i; i >>= 1)
            st[i >> 1] = st[i] + st[i ^ 1]; // st[i^1]表示st[i]的兄弟
    }
    int query(int i, int j)
    {
        int res = 0;
        for (i += n, j += n; i <= j; i >>= 1, j >>= 1)
        {
            if ((i & 1))
                res += st[i++]; // st[i]是右子结点
            if (!(j & 1))
                res += st[j--]; // st[j]是左子结点
        }
        return res;
    }
};
int main()
{
    vector<int> arr({1, 2, 3, 4, 5, 6});
    SegmentTree ST(arr);
    cout << ST.query(0, 5);
}