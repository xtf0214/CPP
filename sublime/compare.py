from cyaron import *

std_exe = r"D:\Code\CPP\OJ\PTA\21train3\6A.exe"
test_exe = r"D:\Code\CPP\OJ\PTA\21train3\6B.exe"


def randRegion(a, b):
    i = randint(a, b)  # 数字位数
    l, r = 10**(i - 1), 10**i
    return randrange(l, r)


def makeData(i):
    test_data = IO(file_prefix="test", data_id=i)
    # begin
    test_data.input_writeln(randRegion(1, 20))
    # end
    test_data.output_gen(std_exe)


def cmpProgram(i):
    test_data = IO(file_prefix="test", data_id=i, disable_output=True)
    # begin
    test_data.input_writeln(randRegion(1, 25))
    # end
    input_file = "D:\Code\CPP\\test%d.in" % i
    try:
        Compare.program(test_exe, input=test_data, std_program=std_exe)
    except:
        print("Wrong Answer:", input_file)


for i in range(1, 10 + 1):
    cmpProgram(i)
    # makeData(i)
