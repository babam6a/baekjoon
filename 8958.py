n = int(input().rstrip())
ans = []

for i in range(n) :
    res = input().rstrip()
    score = 0
    cons = 0
    for j in res :
        if j == "O" :
            score += 1 + cons
            cons += 1
        elif j == "X" :
            cons = 0
        else :
            Exception("Wrong input!")
    ans.append(score)

print("\n".join(str(x) for x in ans))
