from cyaron import *

std_exe = "D:\Code\CPP\Match\Codeforces\Round132\std.exe"
test_exe = "D:\Code\CPP\Match\Codeforces\Round132\B.exe"


def makeData(n):
    for i in range(1, n + 1):
        test_data = IO(file_prefix="test", data_id=i, disable_output=True)
        n = randint(1, int(1e5))
        m = randint(1, int(1e5))
        high = Vector.random(n, [(1, int(4e6))], 1)
        test_data.input_writeln(n, m)
        test_data.input_writeln(high)
        for i in range(m):
            u = randint(1, n)
            v = randint(1, n)
            while u == v:
                v = randint(1, n)
            test_data.input_writeln(u, v)


def cmpProgram(n):
    for i in range(1, n + 1):
        input_file = "D:\Code\CPP\\test" + str(i) + ".in"
        try:
            Compare.program(test_exe, input=input_file, std_program=std_exe)
        except:
            print("Wrong Answer:", input_file)


makeData(5)
# cmpProgram(5)