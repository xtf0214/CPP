import matplotlib.pyplot as plt
import math


def extgcd(a, b):
    if b == 0:
        return (1, 0, a)
    else:
        x, y, gcd = extgcd(b, a % b)
        return (y, x - a // b * y, gcd)


def minmax(a, b, c, n):
    s, t, gcd = extgcd(a, b)
    print(f'{a}x+{b}y={c}')
    print(f'(s, t) = ({s}, {t})')
    if c < 0:
        return -1
    elif c == 0 and gcd == 0:
        return (0, n)
    elif c == 0:
        return (0, 0)
    elif gcd == 0 or c % gcd != 0:
        return -1
    x0 = s * (c // gcd)
    y0 = t * (c // gcd)
    print(f'(x0, y0) = ({x0}, {y0})')
    k_min = math.ceil(-x0 / (b // gcd))
    k_max = math.floor(y0 / (a // gcd))
    if k_min > k_max:
        return -1
    print(f'k in [{k_min, k_max}]')
    x_min = 1e8
    x_max = -1
    x = []
    y = []
    for k in range(k_min, k_max + 1):
        x_k = x0 + k * (b // gcd)
        y_k = y0 - k * (a // gcd)
        if x_k + y_k <= n:
            x.append(x_k)
            y.append(y_k)
            x_min = min(x_min, x_k)
            x_max = max(x_max, x_k)
    print(f'x in [{x_min, x_max}]')
    plt.plot(x, y, '-o')
    plt.show()
    return (x_min, x_max)


minmax(2, 1, 10, 10)