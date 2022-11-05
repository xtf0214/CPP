# https://github.com/luogu-dev/cyaron/wiki

from cyaron import *
import os

std_exe = r"D:\Code\CPP\OJ\Luogu\Problem\P4155A.exe"
test_exe = r"D:\Code\CPP\OJ\Luogu\Problem\P4155.exe"


def randRegion(a, b):
    i = randint(a, b)  # 数字位数
    l, r = 10**(i - 1), 10**i
    return randrange(l, r)


def randPair(a, b):
    l = randint(a, b)
    r = randint(l, b)
    return l, r


def makeData(i):
    test_data = IO(file_prefix="test", data_id=i)
    setData(i, test_data)
    test_data.output_gen(std_exe)


def osCompare(i):
    input_file = "D:\Code\CPP\\test%d.in" % i
    std = os.popen(std_exe + " < " + input_file)
    test = os.popen(test_exe + " < " + input_file)
    std_out = std.read()
    test_out = test.read()
    if std_out != test_out:
        print("Wrong Answer:", input_file)
        print("std_out:\n" + std_out)
        print("test_out:\n" + test_out)
        print()


def cmpProgram(i):
    test_data = IO(file_prefix="test", data_id=i, disable_output=True)
    setData(i, test_data)
    input_file = "D:\Code\CPP\\test%d.in" % i
    try:
        Compare.program(test_exe, input=test_data, std_program=std_exe)
    except:
        print("Wrong Answer:", input_file)


# def setData(i, test_data: IO):
#     # k=randRegion(1, 8)
#     # print("input: ",k)
#     # test_data.input_writeln(randRegion(1, 8))
#     k = randint(1, 10)
#     x = randint(1, 1 << k)
#     y = randint(1, 1 << k)
#     test_data.input_writeln(k, x, y)

# def setData(i, test_data: IO):
#     n = randint(1, 1e5)
#     m = randint(1, 2e6)
#     test_data.input_writeln(n, m)
#     for i in range(n):
#         test_data.input_write(randint(1e8, 1e9))
#     for i in range(m):
#         test_data.input_writeln(randPair(1, n))
#     test_data.input_writeln()


def setData(i, test_data: IO):
    n = randint(1, 2e5)
    m = randint(1, 1e9)
    test_data.input_writeln(n, m)
    for i in range(n):
        test_data.input_writeln(randPair(1, m))
    test_data.input_writeln()


for i in range(1, 10 + 1):
    print(i)
    makeData(i)
    # cmpProgram(i)
    # osCompare(i)
