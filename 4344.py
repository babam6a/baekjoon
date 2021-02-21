n = int(input().rstrip())
ans = []

for i in range(n) :
    res = list(map(int,input().rstrip().split(" ")))
    num = res[0]
    avg = sum(res[1:num+1])/num
    count = 0
    for j in range(1,num+1) :
        if res[j] > avg :
            count += 1
    ans.append("%.3f%%"%((count/num)*100))

print("\n".join(ans))
