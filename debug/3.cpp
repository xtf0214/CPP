#include <iostream>

using namespace std;

//滑动窗口来写  i j 双循环计算窗口数值  比较计算最大值

//加一次比较一次 每次更换i 基础值改变 重新开始加法  （不改变？ 不改变还是连续最大子数列么？）
int cacl1(int *arr, int len)
{
    int Thisnum, maxnum = -100000;
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {
            if (i == j) //第一个时候更新基础值
            {
                Thisnum = arr[i];
            }
            else
            {
                Thisnum += arr[j];
            }
            if (maxnum < Thisnum)
            {
                maxnum = Thisnum;
            }
        }
    }
    return maxnum;
}
//使用折半  求连续子数列和
//递归分治   每一次的返回值就是他们 周围最大的子序列和

//原理：// 基于折半访问子序列
// 1.可以访问到所有
// 2.每次返回都是最大序列和 参与比较！
//为什么折半 总是比线性复杂度低呢 ： 因为 我们不再访问线性个 而是 /2/ 2/2/2对应的下标
//我们只是想得到  子序列和的比较  （约束越多 复杂度越低！）
//访问情况不一样 复杂度不一样
// 基于折半访问子序列  返回最大序列和
//从最深处返回 理解： 最深处返回最大值参与竞争  再返回最大值 。。。。
//运用同一条规则： 中心下标 左边最大和 右边最大和  加起来  若是每一个都这样自然得出
//左边最大和 基于 左边中心 左边最大  右边最大  合起来最大  若是每次都返回 下标和最大那么每次比较的都是最大和！
// int max3(int x,int y,int z)
// {
//     if((x>=y)&&(x>=z))
//     {
//         return x;
//     }
//     else if((x<=y)&&(y>=z))
//     {
//         return y;
//     }

//    return z;
// }

int max3(int i, int j, int k)
{
    if (i >= j && i >= k)
        return i;
    return max3(j, k, i);
}
int cacl2(int arr[], int l, int r)
{
    if (r - l == 0)
        return arr[l];
    int m = (l + r) / 2; //折半开始
    int lmax = arr[m], l_sum = 0, rmax = arr[m + 1], r_sum = 0;

    //从中到左  最大子序列和
    for (int i = m; i >= 0; i--)
    {
        l_sum += arr[i];
        lmax = l_sum > lmax ? l_sum : lmax;
    }
    //从中到右  最大子序列和
    for (int i = m + 1; i <= r; i++)
    {
        r_sum += arr[i];
        rmax = r_sum > rmax ? r_sum : rmax;
    }
    //
    // return max3(lmax+rmax,cacl2(arr,l,m),cacl2(arr,m+1,r));//左边最大连续右边最大连续加起来  与 新的中心坐标最大子序列和比较

    return max3(lmax + rmax, cacl2(arr, l, m), cacl2(arr, m + 1, r)); //返回三者最大值
} //左边最大子序列和  右边最大子序列和
///能够访问到每一个连续子序列 错！应该是 能够访问到每一个连续子序列 的最大和 且 拿出来比较
//基于序列特点直接输出 真6 以尾部的前i -1 个元素和 特点决定整个序列
//序列尾部 前i-1和负数 那么最大为arr[i] 毋庸置疑
//不然 加上arr[i]
// for 遍历 得到每一个序列的最大
//如果前面有问题（负数）直接舍弃前面  如果没有舍弃说明前面没问题(正的) 基于连续 我们不可能舍弃求和中的负数 虽然有负数但是求和为正数呀可以为后面做准备
//从前到后一直在算计 太秀了！

int cacl3(int *arr, int r)
{
    int max = arr[0], prepare = arr[0]; //一个用于储存最大  一个用于得到i下标元素结尾的最大序列和
    for (int i = 1; i <= r; i++)
    {
        if (prepare <= 0)
        {
            prepare = arr[i];
        }
        else
        {
            prepare += arr[i];
        }
        if (max < prepare)
        {
            max = prepare;
        }
    }
    return max;
}
int main()
{
    int arr[101], n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // int ret1 = cacl1(arr,n);
    int ret2 = cacl2(arr, 0, n - 1);
    // int ret3 = cacl3(arr,n-1);
    // cout <<ret1 <<endl;
    cout << ret2 << endl;
    // cout << ret3 <<endl;
    return 0;
}