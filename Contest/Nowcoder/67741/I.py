import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from tqdm import tqdm
from random import randint
import os, re, sys

plt.rcParams['font.sans-serif'] = ['SimHei']
plt.rcParams['axes.unicode_minus'] = False

n = int(1e5)

def bit_noob():
    # 生成
    circle = []
    for _ in range(n):
        x, y = randint(-99, 99), randint(-99, 99)
        while True:
            r = randint(1, 100)
            if x + r <= 100 and -100 <= x - r and -100 <= y - r and y + r <= 100:
                break
        circle.append((x, y, r))
    return circle

def buaa_noob():
    circle = []
    for _ in range(n):
        while True:
            x, y = randint(-99, 99), randint(-99, 99)
            r = randint(1, 100)
            if x + r <= 100 and -100 <= x - r and -100 <= y - r and y + r <= 100:
                break
        circle.append((x, y, r))
    return circle

# buaa_noob()
# plt.show() 


for circle, label in [(bit_noob(), 'bit_noob'), (buaa_noob(), 'buaa_noob')]:
    s_r = 0
    s_xy = 0
    r_area = [0] * 101
    xy_area = [0] * 201
    for x, y, r in circle:
        r_area[r] += 1
        xy_area[abs(x) + abs(y)] += 1
        s_r += r
        s_xy += abs(x) + abs(y)
    print(s_r / n, s_xy / n)
    for i in range(101):
        r_area[i] /= n
    for i in range(201):
        xy_area[i] /= n
    plt.plot(xy_area[1:], label=label)

plt.legend()
plt.show()