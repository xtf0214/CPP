import math


st = set()
a = 3
b = 5
def dfs(s):
    if s >= 100:
        return
    st.add(s)
    dfs(s * a)
    dfs(s + b)
dfs(1)
print(st)
for i in st:
    n = 0
    while (i - (a**n)) % b != 0:
        n+=1
    m = i - a ** n
    print(f'{i}={a}**{n}+{m}')