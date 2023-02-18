## 7-1 找朋友 (5 分)

#### 思路

读入n，然后与19比较大小即可，唯一需要注意n=19也要输出合适。

时间复杂度 $O(n)$

#### 代码

```cpp
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    if (n > 19)
        printf("不合适");
    else
        printf("合适");
    return 0;
}
```

## 7-2 统计字符个数 (5 分)

#### 思路

读入字符串，逐个遍历判断，对每个字符进行计数加一，最后输出即可，需要注意本题不考虑字母大小写，大小写字母都应该被统计。

时间复杂度 $O(n)$

#### 代码

```cpp
#include <stdio.h>
#include <string.h>

int main() {
    char s[105];
    int cnt[128] = {0};
    scanf("%s", s);
    for (int i = 0, len = strlen(s); i < len; i++)
        cnt[s[i]]++;
    printf("z:%d\n", cnt['z'] + cnt['Z']);
    printf("u:%d\n", cnt['u'] + cnt['U']);
    printf("a:%d", cnt['a'] + cnt['A']);
    return 0;
}
```

## 7-3 最后一个单词 (10 分)

#### 思路

由于包含空格，`scanf`遇到空格会结束读入，所以读入字符串必须使用`gets()`函数。

使用for循环从倒数第二个字符(跳过那个`.`)开始读入，遇到空格结束读入。

根据题意考虑到有两种情况不符合题意，需要输出`Error`。

- 存在单词，但是首字母大写，例如`Abc.`
- 不存在单词类似于这种输入`.`，只有一个点。

最后如果符合要求，需要倒叙输出结果，因为读进来的单词是反的。

此题细节较多，需要仔细考虑。

时间复杂度 $O(n)$

#### 代码

```cpp
#include <stdio.h>
#include <string.h>
int main() {
    char s[1005];
    char res[100];
    int j = 0;
    gets(s);
    // strlen(s)-2，表示从倒数第二个字符开始遍历
    for (int i = strlen(s) - 2; i >= 0; i--) {
        if (s[i] == ' ')
            break;
        res[j++] = s[i]; // j记录的就是res的长度
    }
    if (j == 0 || ('A' <= res[j - 1] && res[j - 1] <= 'Z'))
        printf("Error");
    else {
        for (int i = j - 1; i >= 0; i--)
            printf("%c", res[i]);
    }
    return 0;
}
```

## **7-4 解开密码锁 (10 分)**

#### 思路

根据题意构造一个杨辉三角，然后输出第 n 行的结果就可以了。

我们用一个二维数组存储这个杨辉三角，如下。

| i\j  | 0    | 1    | 2    | 3    | 4    |
| ---- | ---- | ---- | ---- | ---- | ---- |
| 0    | 1    | 0    | 0    | 0    | 0    |
| 1    | 1    | 1    | 0    | 0    | 0    |
| 2    | 1    | 2    | 1    | 0    | 0    |
| 3    | 1    | 3    | 3    | 1    | 0    |
| 4    | 1    | 4    | 6    | 4    | 1    |

对于这个图，关系为：$G[i][j]=G[i-1][j-1]+G[i-1][j]$，说人话就是某个位置的值等于它头上的元素与头上左边元素之和，同时还应该注意，当列为 0 或者对角线位置元素值为 1。

根据这个想法，我们就可以求出 0~n 每一行杨辉三角值。

时间复杂度 $O(n^2)$

#### 代码

```cpp
#include <stdio.h>
int C[35][35];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++)
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
    for (int i = 0; i <= n; i++)
        printf("%d ", C[n][i]);
    return 0;
}
```

## **7-5 二进制转十进制 (15 分)**

#### 思路

以字符串形式读入二进制文本，然后转换成十进制即可，如果不懂二进制转十进制原理建议去查一下。

位运算 `1<<x` == $2^x$

时间复杂度 $O(n)$

#### 代码

```cpp
#include <stdio.h>
#include <string.h>
int main() {
    char bin[30];
    int ans = 0;
    scanf("%s", bin);
    for (int i = strlen(bin) - 1, k = 0; i >= 0; i--, k++)
        ans += (int)(bin[i] - '0') << k;
    printf("%d", ans);
    return 0;
}
```

## 7-6 主对角线、副对角线之和 (15 分)

#### 思路

主对角线和就是从左上到右下元素之和，副对角线和就是从右上到左下元素之和。

注意：如果n为奇数，最中心的元素会被重复计算两次，需要减掉一次。

时间复杂度 $O(n)$

#### 代码

```cpp
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int a[n][n], ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        ans += a[i][i] + a[i][n - 1 - i];
    if (n % 2 == 0)
        printf("%d", ans);
    else
        printf("%d", ans - a[n / 2][n / 2]);
    return 0;
}
```

## 7-7 不变初心数 (20 分)

#### 思路

算法思想很简单按照题目要求来即可，但是细节对大一来说会比较多。

我们定义函数`count(int x)`用来求数字x的每一位数字相加之和。

```cpp
int count(int x) {
    int res = 0;
    for (; x; x /= 10)
        res += x % 10;
    return res;
}
```

当我们读入x之后，用count计算x*i各位数之和，然后每次求出都判断是否与上一次相等，不相等，停止循环，将same标记为0，避免循环结束后输出结果，同时对于符合要求的结果，same始终会为1，此时在内层循环结束后我们输出其不忘初心数的初心。

#### 代码

```cpp
#include <stdio.h>
int count(int x) {
    int res = 0;
    for (; x; x /= 10)
        res += x % 10;
    return res;
}
int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        int ans = count(x);
        int same = 1;
        for (int i = 2; i <= 9; i++)
            if (count(x * i) != ans) {
                same = 0;
                break;
            }
        if (same)
            printf("%d\n", ans);
        else
            printf("NO\n");
    }
    return 0;
}
```

## 7-8 最长公共前缀 (20 分)

#### 思路

一共由n个字符串，我们遍历第一个字符串的每个字母`s[0][j]`，如果第2个到第n个字符串的对应下标处的字符`s[i][j]`与`s[0][j]`相等，我们就加入到结果`ans`字符数组中，遇到不相等的字符或者字符串`s[i]`长度大于`s[0]`时结束循环，并输出前面已经记录的结果，如果结果字符串长度为0那么输出Error。

时间复杂度约为 $O(nm)$，$m$ 为字符串的最小长度

#### 代码

```cpp
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    char s[n][205];
    char ans[205];
    int cnt = 0;
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);
    int finish = 0;
    for (int i = 0; !finish; i++) {
        finish = 0;
        for (int j = 1; j < n; j++)
            if (i >= strlen(s[j]) || s[j][i] != s[0][i]) {
                finish = 1;
                break;
            }
        if (!finish)
            ans[cnt++] = s[0][i];
    }
    if (cnt == 0)
        printf("Error");
    else
        printf("%s", ans);
    return 0;
}
```

## **7-9 成绩排序 (25 分)**

#### 思路

我们这里使用c++语言的`std::sort()`函数进行排序，需要头文件`<algorithm>`

该函数有三个参数：起始地址，终止地址（左闭右开），比较器（排序方式）。

比如对长度n的数组进行排序，可以写作`sort(a, a + n)`

比较器可以是一个bool型函数，如果数据需要按照升序排序，则返回`a.data < b.data`

时间复杂度 $O(n\log n)$

#### 代码

```cpp
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
```

## 7-10 扫雷游戏 (30 分)

#### 思路

这是一个BFS（广度优先遍历）的搜索题。

首先使用二维数组`G[i][j]`，`ths[i][j]`，`vis[i][j]`表示地图显示的数字，是否是雷，是否已经打开。

对于每一次点击的坐标，首先判断是否点击到雷。如果不是雷，则把坐标放在搜索队列里，如果是雷，则直接输出"You lose"并结束程序

获取队列的第一个坐标，并从队列中删除。计算该坐标周围8个格子中雷的个数，如果没有雷，则把这8个格子放在搜索队列里，不断执行这个过程直到队列为空。

最后判断，如果所有不是雷的个子都被打开，那么输出"You win"

#### 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> G;
vector<vector<bool>> ths, vis;
int way[8][2]{{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}};
int n, m, k, l;
void printGraph() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << G[i][j] << ' ';
        cout << '\n';
    }
}
int main() {
    cin >> n >> m >> k >> l;
    G.assign(n, vector<int>(m, -1));
    ths.assign(n, vector<bool>(m));
    vis.assign(n, vector<bool>(m));
    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        ths[y][x] = true;
    }
    for (int i = 0; i < l; i++) {
        int y, x;
        cin >> y >> x;        
        if (vis[y][x])
            continue;
        if (ths[y][x]) {
            cout << "You lose";
            return 0;
        }
        queue<pair<int, int>> q;
        q.push({y, x});
        vis[y][x] = 1;
        while (!q.empty()) {
            auto [cy, cx] = q.front();
            q.pop();
            int cnt = 0;
            for (auto &[ty, tx] : way) {
                int ny = cy + ty, nx = cx + tx;
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || vis[ny][nx])
                    continue;
                if (ths[ny][nx])
                    cnt++;
            }
            G[cy][cx] = cnt;
            if (cnt == 0)
                for (auto &[ty, tx] : way) {
                    int ny = cy + ty, nx = cx + tx;
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n || vis[ny][nx])
                        continue;
                    vis[ny][nx] = true;
                    q.push({ny, nx});
                }
        }
        printGraph();
        if (i != l - 1)
            cout << '\n';
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (G[i][j] == -1 && ths[i][j] == 0)
                return 0;
    cout << "You win";
    return 0;
}
```

## **7-11 至多删三个字符 (50 分)**

#### 思路

**动态规划，如果你没有学过，建议先把前面所有题目研究明白之后以后有机会再看这道题，这道题目不做要求**

状态定义：$f(i,j)$ 表示前 $i$ 个字符去除 $j$ 个字符所形成的的不同的子串

状态转移方程：$f(i,j)=f(i-1,j)+f(i-1,j-1)|(j>0)$

考虑样例`ababcc`，去除字串 `ba` 和 `ab` 得到的结果是一样的 `abcc` ，但是 $f(4,2)=f(3,2)+f(3,1)$ 重复计数了一次，所以需要去重。

可以发现，对于 $f(i,j)$ ， $s[i]$ 前面 $j$ 个字符 $s[i-j,i-1]$ 如果存在 $s[k]=s[i]$ ， 会造成子段 $s[k,i-1]$ 与 子段 $s[k+1,i]$ 重复，会分别用 $f(i-1,j-1)$ 和 $f(i-1,j)$ 计数两次。要满足 $f(i,j)$ ，就还需要从 $s[1,k-1]$ 这段里面删掉 $(j-(i-k))$ 个字符，即 $f(i,j)-=f(k-1,j-(i-k))$

时间复杂度 $O(n)$

#### 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;
ll f[N][4];
int main() {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 3; j++) {
            f[i][j] = f[i - 1][j] + f[i - 1][j - 1] * (j > 0);
            // 搜索区间s[i-j,i-1]长度为j的字串是否和s[i]相同
            for (int k = i - 1; k >= max(1, i - j); k--)
                if (s[k] == s[i]) {
                    f[i][j] -= f[k - 1][j - (i - k)];
                    break;
                }
        }
    }
    ll ans = 0;
    for (int j = 0; j <= 3; j++)
        ans += f[n][j];
    cout << ans;
    return 0;
}
```

## **7-12 猜字母 (10 分)**

#### 思路

本题只需要利用 ascii 计算

时间复杂度：$O(1)$

#### 代码

```cpp
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("%c%c", n - 1 + 'A', n - 1 + 'a');
    return 0;
}
```

## **7-13 求素数个数 (10 分)**

#### 思路

对于一个数 $x$ 的因数，是成对出现在区间 $[1,\sqrt{x}]$ 与 $[\sqrt{x},x]$ 之中的，如果在区间 $[2,\sqrt{x}]$ 中没有 $x$ 的因数，那么可以判定 $x$ 为质数。

时间复杂度 $\Theta (\sum \sqrt{i})$   $O(n^{\frac{3}{2}})$

#### 代码

```cpp
#include <stdio.h>

int isPrime(int x) {
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return 0;
    return x != 0 && x != 1;
}
int main() {
    int n, cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
        if (isPrime(i))
            cnt++;
    printf("%d", cnt);
    return 0;
}
```

