res = []
for i in range(10) :
    n = int(input().rstrip()) % 42
    if n not in res :
        res.append(n)
print(len(res))
