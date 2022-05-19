### 郑轻2022新生热身赛题解

#### 1.Hello World

python大法好（逃

```python
print("Hello World")
```

#### 2.区间互质数

> 题目描述：求$[1,n]$中与$n$互质的数的个数

* 算法1：欧拉函数

```cpp
int euler_phi(int n)
{
    int m = int(sqrt(n + 0.5));
    int ans = n;
    for (int i = 2; i <= m; i++)
        if (n % i == 0)
        {
            ans = ans / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        ans = ans / n * (n - 1);
    return ans;
}
```

* 算法2：容斥原理
  $|A_1\cup A_2\cup\cdots\cup A_n|=\sum\limits_{1\le i\le n}|A_i|-\sum\limits_{1\le i\le j\le n}|A_i\cap A_j| +\sum\limits_{1\le i\le j\le k\le n}|A_i\cap A_j\cap A_k|-\cdots+(-1)^{n+1}|A_1\cap A_2\cap\cdots\cap A_n|$
  考虑逆问题：求$[1,n]$中**不**与$n$互质的数的个数
  设$n$中所有素因子$\{p_i\}(i=1,2,\cdots,m)$
  对于$p_i$,在$[1,n]$中有$\lfloor \dfrac{n}{p_i}\rfloor$个数被$n$整除
  若直接计算$\sum\limits_{1\le i\le m} \lfloor\dfrac{n}{p_i}\rfloor$,有些数会被统计多次(同时被多个素因子整除)
  因此需要考虑容斥原理对结果进行处理
  逆问题正确答案为
  $ans=\sum\limits_{1\le i\le m} \lfloor\dfrac{n}{p_i}\rfloor - \sum\limits_{1\le i\le j\le m}\lfloor\dfrac{n}{p_i\cdot p_j}\rfloor +\sum\limits_{1\le i\le j\le k\le m}\lfloor\dfrac{n}{p_i\cdot p_j\cdot p_k}\rfloor+(-1)^{m+1}\lfloor\dfrac{n}{p_i\cdot p_j\cdot p_k\cdots p_s}\rfloor$
  即原问题答案为$n-ans$
  不难发现,对于上述公式的项数为$C_s^1+C_s^2+\cdots+C_s^m=2^m-1$,即有$2^m-1$种从$\{p_i\}$取出若干个参与计算状态
  而对于$i\in[1,2^m-1]$,其二进制展开的$m$个二进制数组合成$2^m-1$种状态
  则二进制展开的第$j\in[1,m]$位可以表示是否将$p_j$加入计算

```cpp
#include <iostream>
#include <vector>
using namespace std;
int solve(int n)
{
    // 获取m的素因子
    int x = n;
    vector<int> p;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
        {
            p.push_back(i);
            while (x % i == 0)
                x /= i;
        }
    if (x > 1)
        p.push_back(x);

    int m = p.size();
    int ans = 0;
    for (int i = 1; i < (1 << m); i++) // 1<<m == 2^m
    {
        int cnt = 0;
        int mul = 1;
        for (int j = 0; j < m; j++)
            // 获取第j位状态
            if (i & (1 << j))
            {
                cnt++;
                mul *= p[j];
            }
        // mul*(-1)^(cnt+1)
        if (cnt % 2 == 0)
            mul = -mul;
        ans += n / mul;
    }
    return n - ans;
}
int main()
{
    int n;
    cin >> n;
    cout << solve(n);
    return 0;
}
```

#### 3.竞选

定义m个班委类,其中包含若干个学生成员
输入n个学生的目标班委,票数时,把该学生的id,票数加入到目标班委
再对各个班委名单里进行排序,排在首位的即为竞选结果

```cpp
#include <bits/stdc++.h>
using namespace std;
struct Stu
{
    int num, t;
    Stu(int num, int t) : num(num), t(t) {}
};
bool cmp(const Stu &a, const Stu &b)
{
    if (a.t != b.t) return a.t > b.t;
    else return a.num < b.num;
}
struct Banwei
{
    vector<Stu> stu;
    void Sort() { sort(stu.begin(), stu.end(), cmp); }
};
int main()
{
    int n, m, k, c, t;
    cin >> n >> m;
    Banwei a[m + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> c >> t;
        a[c].stu.push_back(Stu(i, t));
    }
    for (int i = 1; i <= m; i++)
    {
        a[i].Sort();
        cout << a[i].stu[0].num << " ";
    }
    return 0;
}
```

#### 4.Cassels 方程

直接计算判断左右是否相等

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, z;
    long long l, r;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        l = x * x + y * y + z * z;
        r = 3 * x * y * z;
        if (l == r)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
```

#### 5.未成年人之友

根据题意列出判断条件逐个判断

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int age, hour, minute;
    string week;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> age >> week;
        scanf("%d:%d", &hour, &minute);
        if (age >= 18)
            cout << "Yes" << endl;
        else
        {
            if (week == "Fri" || week == "Sat" || week == "Sun")
            {
                if (hour == 20)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
            else
                cout << "No" << endl;
        }
    }
    return 0;
}
```

#### 6.计算天数

2月份天数与年份挂钩,剩下的直接累加

```cpp
#include <bits/stdc++.h>
using namespace std;
int Month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main()
{
    int y, m, d, s = 0;
    scanf("%d/%d/%d", &y, &m, &d);
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
        Month[2]++;
    for (int i = 1; i < m; i++)
        s += Month[i];
    s += d;
    cout << s;
    return 0;
}
```

#### 8.计算阶乘和

迭代计算$n!$

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s = 0, n, k = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        k *= i;
        s += k;
    }
    cout << s;
    return 0;
}
```
