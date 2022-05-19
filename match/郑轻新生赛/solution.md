### 1.~~另一个爱和希望的故事~~爬楼梯

```cpp
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
bool broken[100005];
int ans[100005];
int T, n, k;
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        memset(broken, 0, sizeof(broken));
        memset(ans, 0, sizeof(ans));
        ans[0] = 1;
        for (int j = 0, t; j < k; j++)
        {
            cin >> t;
            broken[j] = true;
        }
        for (int i = 1; i <= n; i++)
            if (!broken[i])
            {
                if (i == 1)
                    ans[i] = ans[i - 1] % MOD;
                else
                    ans[i] = (ans[i - 1] + ans[i - 2]) % MOD;
            }
        cout << ans[n] << endl;
    }
    return 0;
}
```

### 2.BanGosu!

```cpp
#include<bits/stdc++.h>
using namespace std;
int n, r, score, combo;
double Ox[1000005], Oy[1000005], Cx, Cy;
int main()
{
    cin >> n >> r;
    for (int i = 0; i < n; i++)
        scanf("%lf %lf", &Ox[i], &Oy[i]);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &Cx, &Cy);
        double d = sqrt((Ox[i] - Cx) * (Ox[i] - Cx) + (Oy[i] - Cy) * (Oy[i] - Cy));
        if (d >= r)
            combo = 0;
        else
        {
            combo++;
            int k = combo / 100; //取百位上的数
            if (k >= 4)
                k = 4; 
            if (d < 0.2 * r)
                score += 300 + k * 3; //score = 300(1+k%) = 300 + 3 * k
            else if (0.2 * r <= d && d < 0.5 * r)
                score += 200 + k * 2;
            else if (0.5 * r <= d && d < r)
                score += 100 + k;
        }
    }
    cout << score;
    return 0;
}
```

### 3.奇怪的引擎

$W(t)=\dfrac{t\sqrt{t^3}}{5}−\cos(t)+114514$

$W(t)=\int P(t)\mathrm{d}t \Rightarrow P(t)=W'(t)=\dfrac{1}{2}\sqrt{t^3}+\sin(t)$

* 二分法

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  double y;
  double f(double x) { return 0.5 * sqrt(x * x * x) + sin(x); }
  int main()
  {
      int T;
      cin >> T;
      while (T--)
      {
          cin >> y;
          double l, r, mid;
          mid = (l + r) / 2;
          while (r - l > 1e-6)
          {
              if (f(mid) - y > 0)
                  l = mid;
              else
                  r = mid;
          }
          printf("%.6lf\n", mid);
      }
  }
  ```
* 牛顿迭代法

  ```cpp
  #include <bits/stdc++.h>
  using namespace std;
  double y;
  double f(double x) { return 0.5 * sqrt(x * x * x) + sin(x) - y; }
  double df(double x) { return 0.75 * sqrt(x) + cos(x); }
  int main()
  {
      int T;
      cin >> T;
      while (T--)
      {
          cin >> y;
          int k = 0;
          double x1 = 1e12, x0;
          do
          {
              x0 = x1;
              x1 = x0 - f(x0) / df(x0);
          } while (abs(x0 - x1) > 1e-6);
          printf("%.6lf\n", x1);
      }
  }
  ```

### 4.Diana压缩算法

```cpp
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    int n, rank = 0;
    char s[9] = "00000000";
    cin >> n >> a;
    for (int i = 0; i < a.size(); i += 3)
    {
        int res = 0;
        for (int j = 2; j >= 0; j--)
            res = res * 2 + a[i + j] - '0';
        if (s[res] == '0')
        {
            s[res] = 'a' + rank;
            rank++;
        }
        cout << s[res];
    }
    return 0;
}
```

### 7-5 子矩形
