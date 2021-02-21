num = int(input().rstrip())
a = list(map(int,input().rstrip().split(" ")))
big = a[0]
small = a[0]

for i in range(num) :
	if a[i] > big :
		big = a[i]

for i in range(num) :
	if a[i] < small :
		small = a[i]

print("%d %d"%(small,big))
