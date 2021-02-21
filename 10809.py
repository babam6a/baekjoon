string = input().rstrip()
ans = [-1] * 26
alpha = "abcdefghijklmnopqrstuvwxyz"

for i in range(len(string)) :
    index = alpha.index(string[i])
    if ans[index] == -1 :
        ans[index] = i

print(" ".join(str(x) for x in ans))
