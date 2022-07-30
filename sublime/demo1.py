from cyaron import *
from scipy import rand

std_exe = r"D:\Code\CPP\Match\memgxin\1\gg.cpp"
test_exe = r"D:\Code\CPP\Match\memgxin\1\g.cpp"


def makeData(n):
    for i in range(1, n + 1):
        test_data = IO(file_prefix="test", data_id=i, disable_output=True)
        n = 8
        for i in range(n):
            l = randint(1, n)
            r = randint(l, n)
            if i % 2 == 0:
                d = randint(1, n)
                test_data.input_writeln(0, l, r, d)
            else:
                test_data.input_writeln(1, l, r)


def cmpProgram(n):
    for i in range(1, n + 1):
        input_file = "D:\Code\CPP\\test" + str(i) + ".in"
        try:
            Compare.program(test_exe, input=input_file, std_program=std_exe)
        except:
            print("Wrong Answer:", input_file)


makeData(5)
cmpProgram(5)