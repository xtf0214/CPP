s, a, b = input().split(',')
p1 = s.find(a)
p2 = s.rfind(b)
if p1 != -1 and p2 != -1:
    print(p2 - (p1 + len(a)))
else:
    print(-1)
