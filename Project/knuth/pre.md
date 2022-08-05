## knuth数计算

#### 高精度运算空间

`using typebit = unsigned int;`

`using typelen = unsigned long long;`

`typebit num[MAX];`

`sizeof(typebit) = 4 byte`

#### 可承载运算

 $[0,2^k]$

$k\log_{10}2\le\mathrm{MAX}$

$k=\lfloor\mathrm{MAX\cdot\log_210}\rfloor$

| 内存空间 | 数组长度（十进制位数）   | k              | 运算范围 | 计算结果空间 |
| ------- | ------------------------ | ------------- | -------- | -------- |
| 4KB      | num[1024]            | 3,401    | 2↑2↑11  | 1KB |
| 4MB      | num[1024\*1024]       | 3,483,294 | 2↑2↑21  | 1MB |
| 4GB      | num[1024\*1024\*1024] | 3,566,893,131 | 2↑2↑31  | 1GB |

#### 计算单元

1. 最有效

一次运算 `a *= 0x10000000`

$\mathrm{0x10000000}=2^{28}=268,435,456$

$2^{28}\times 9<2^{32}-1$

2. 最方便

一次运算 `a *= 0x1000`

$\mathrm{0x1000}=2^{16}=65,536$

#### 计算次数

1. 计算 a↑b

```cpp
BigNum s(1);
for (int i = 0; i < b; i++)
    s *= a;
```

```cpp
BigNum s(1);
void PowerCalc(int k, int b)
{
    if (k == b)	return;
    s *= a;
    calc(k + 1);
}
PowerCalc(0, b);
```

2. 计算a↑b↑c

```cpp
BigNum s(1);
for (int i = 0; i < b; i++)
    for (int i = 0; i < b; i++)
        for (int i = 0; i < b; i++)
            for (int i = 0; i < b; i++)
            	// c层循环
				s *= a;
```

```cpp
BigNum s(1);
void iterPowerCalc(int k, int b, int c)
{
    if (k == c)
        return void(s *= a);
    for (int i = 0; i < b; i++)
        iterPowerCalc(k + 1, b, c);
}
iterPowerCalc(0, b, c);
```

计算2↑2↑31

