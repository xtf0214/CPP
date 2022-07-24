def load_file(filename):
    with open(filename, "r", encoding="utf-8") as f:
        for i, line in enumerate(f):
            yield line.strip('\n')


def WeightGraph(filename):
    start = True
    for line in load_file(filename):
        if start:
            start = False
            continue
        u, v, w = line.split(' ')
        print('{}---|{}|{}'.format(u, w, v))


def UndirectedGraph(filename):
    start = True
    for line in load_file(filename):
        if start:
            start = False
            continue
        u, v = line.split(' ')
        print('{}---{}'.format(u, v))


def DirectedGraph(filename):
    start = True
    for line in load_file(filename):
        if start:
            start = False
            continue
        u, v = line.split(' ')
        # print('{}--->{}'.format(13 - int(u), 13 - int(v)))
        # print('{}--->{}'.format(u, v))
        print('{}--->{}'.format(v, u))


def Tree(filename):
    start = True
    for line in load_file(filename):
        if start:
            start = False
            continue
        arr = line.split(" ")
        if arr[1] == 0:
            continue
        u = arr[0]
        for v in arr[2:]:
            print("{}---{}".format(u, v))


filename = r'D:\Code\CPP\OI-ACM\Graph\1.in'
print("```mermaid\nflowchart LR")
WeightGraph(filename)
print("```")