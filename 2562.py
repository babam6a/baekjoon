a = []

for i in range(9) :
	a.append(int(input().rstrip()))
big = a[0]
index = 0
for i in range(9) :
	if a[i] > big :
		big = a[i]
		index = i

print("%d\n%d"%(big,index+1))
