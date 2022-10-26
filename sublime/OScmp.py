import os

std_exe = r""
test_exe = r""


def compare(n):
    for i in range(1, n + 1):
        print("test" + str(i))
        input_file = "D:\Code\CPP\\test" + str(i) + ".in"
        std = os.popen(std_exe + " < " + input_file)
        test = os.popen(test_exe + " < " + input_file)
        std_out = std.read()
        test_out = test.read()
        print("std_out:\n" + std_out)
        print("test_out:\n" + test_out)
        if std_out != test_out:
            print("Wrong Answer:", input_file)
            # print("std_out:\n" + std_out)
            # print("test_out:\n" + test_out)
            continue


compare(5)