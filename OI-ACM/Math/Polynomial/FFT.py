import numpy as np
import math


def FFT(P: list, inv=1):
    n = len(P)
    if n == 1:
        return P
    w = [np.exp(inv * 2 * np.pi * k / n * 1j) for k in range(n)]
    Pe = P[::2]
    Po = P[1::2]
    Ye = FFT(Pe, inv)
    Yo = FFT(Po, inv)
    Y = [0] * n
    for i in range(n // 2):
        Y[i] = Ye[i] + w[i] * Yo[i]
        Y[i + n // 2] = Ye[i] - w[i] * Yo[i]
    return Y


def IFFT(P: list):
    n = len(P)
    Y = FFT(P, -1)
    return [x / n for x in Y]


def multiply(A, B):
    n = len(A) + len(B) - 1
    nn = 2 << int(math.log2(n - 1))
    C = [0j] * nn
    for i in range(len(A)):
        C[i] += A[i]
    for i in range(len(B)):
        C[i] += B[i] * 1j
    C = [x * x for x in FFT(C)]
    S = IFFT(C)
    return [int(x.imag / 2 + 0.49) for x in S[:n]]


def multiply2(A, B):
    n = len(A) + len(B) - 1
    nn = 2 << int(math.log2(n - 1))
    f = FFT([x + 0j for x in A] + [0j] * (nn - len(A)))
    g = FFT([x + 0j for x in B] + [0j] * (nn - len(B)))
    h = [x * y for x, y in zip(f, g)]
    S = IFFT(h)
    return [int(x.real + 0.49) for x in S[:n]]


# 4x^3+3x^2+2x+1
A = [1, 2, 3, 4]
B = [4, 3, 2, 1]
C = multiply(A, B)
print(C)
# [4, 11, 20, 30, 20, 11, 4]
