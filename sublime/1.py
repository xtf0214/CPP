import os
import random
import sys

A = "D:\Code\CPP\sublime\A"  #A文件位置
B = "D:\Code\CPP\sublime\B"  #B文件位置
spath = "D:\Code\CPP\sublime\input.txt"  #生成数据文件
brk = 500  #最多对拍次数


def init():  #初始化编译文件
    os.system("g++ " + A + ".cpp -o " + A + ".exe -std=c++11")
    os.system("g++ " + B + ".cpp -o " + B + ".exe -std=c++11")


def rand(l, r):
    return str(random.randint(l, r))


def crand(s):
    if s == "":
        print("随机字符长度不能为空")
        sys.exit(0)
    else:
        s = str(s)
        len1 = len(str(s))
        return s[int(rand(0, len1 - 1))]


def get():  #随机函数
    p = open("D:\input.txt", "w")
    s = ""
    s += rand(1, 4) + " " + rand(1, 4)
    p.write(s)
    return s


init()  #c++别忘了初始化
cnt = 0  #初始化对拍次数
while True:
    cnt += 1
    sample = get()
    a = os.popen(A + ".exe < " + spath)
    b = os.popen(B + ".exe < " + spath)
    ansA = a.read()
    ansB = b.read()
    if ansA != ansB:
        print("sample" + str(cnt) + ":Wrong!\n" + sample + '\n')
        print("ansA:\n" + ansA)
        print("ansB:\n" + ansB)
        break
    else:
        if cnt != brk:
            print("sample" + str(cnt) + ":Right!")
        else:
            print(str(brk) + "组数据未有错误，停止对拍")
            break
input()