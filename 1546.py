n = int(input().rstrip())
lis = list(map(int,input().rstrip().split(" ")))

big = lis[0]
for i in range(n) :
    if lis[i] > big :
        big = lis[i]

ans = [(i/big) * 100 for i in lis]
print(sum(ans)/len(ans))
