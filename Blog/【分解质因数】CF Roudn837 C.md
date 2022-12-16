> 题目链接：[C. Hossam and Trainees](https://codeforces.com/contest/1771/problem/C)
>
> ### 题目描述
>
> 给定一个长度为 $n(n\le 10^5)$ 的数组 $a(1\le a_i\le 10^9)$  
>
> 问是否存在一对 $(i,j)\ i≠j$ 满足 $\gcd(a_i,a_j)>1$

考虑对每个数进行分解质因数，如果存在相同的因数，则满足情况

下面介绍分解质因数的两个算法

朴素法：最简单的算法即为从 $[1,\sqrt{N}]$ 进行遍历，复杂度为 $O(\sqrt{n})$

```cpp
vector<int> breakdown(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            res.push_back(i);
        }
    if (n != 1) // 说明再经过操作之后 N 留下了一个素数
        res.push_back(n);
    return res;
}
```

朴素法优化：预处理 $[1,\sqrt{N}]$ 中的全部的质数，然后枚举这些质数，**如果数字 $n$ 不能被这些数整除的话，那么他就是一个大于 $N$ 的质数**。

根据素数计数函数 $\pi(n)=\Theta(\dfrac{n}{\log n})$ ，总复杂度为 $O(\dfrac{\sqrt{n}}{\log \sqrt{n}})$

```cpp
void euler(int n) {
    isPrime.assign(n, 1);
    isPrime[1] = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i])
            primes.push_back(i);
        for (int j = 0; j < primes.size() && 1LL * i * primes[j] < n; j++) {
            isPrime[i * primes[j]] = 0;
            if (i % primes[j] == 0)
                break;
        }
    }
}
vector<int> breakdown(int n) {
    vector<int> res;
    for (int p : primes) {
        if (p * p > n)
            break;
        if (n % p == 0) {
            res.push_back(p);
            while (n % p == 0)
                n /= p;
        }
    }
    if (n != 1)
        res.push_back(n);
    return res;
}
```

完整代码：  

```cpp
vector<int> primes, isPrime;
void euler(int n) {
    isPrime.assign(n, 1);
    isPrime[1] = 0;
    for (int i = 2; i < n; i++) {
        if (isPrime[i])
            primes.push_back(i);
        for (int j = 0; j < primes.size() && 1LL * i * primes[j] < n; j++) {
            isPrime[i * primes[j]] = 0;
            if (i % primes[j] == 0)
                break;
        }
    }
}
bool solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int num = a[i];
        for (int p : primes) {
            if (p * p > num)
                break;
            if (num % p == 0) {
                while (num % p == 0)
                    num /= p;
                mp[p]++;
                if (mp[p] >= 2)
                    return true;
            }
        }
        if (num > 1)
            mp[num]++;
        if (mp[num] >= 2)
            return true;
    }
    return false;
}
```