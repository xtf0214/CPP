n = int(input())
a = [0] * n
day = list(range(0, n)) + list(range(n - 2, 0, -1))
ans = [0] * n
for _ in range(2):
    for i in day:
        for j in range(len(a)):
            a[j] += 1
            ans[j] = max(ans[j], a[j])
        a[i] = 0

for i in ans:
    print(i)
