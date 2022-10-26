from cyaron import *

std_exe = r"D:\Code\CPP\Debug\2.exe"
test_exe = r"D:\Code\CPP\Debug\5.exe"


def makeData(i):
    test_data = IO(file_prefix="test", disable_output=True)
    test_data.input_writeln(i)

l=1
r=int(1e10)
while r-l>1:
    m=(l+r)/2
    input_io = IO()
    input_io.input_writeln(m)
    try:
        Compare.program(test_exe, input=input_io, std_program=std_exe) 
        l=m
    except:
        r=m
        print("error")