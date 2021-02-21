n = int(input().rstrip())
ans = []

for i in range(n) :
	x1,y1,r1,x2,y2,r2 = map(int,input().rstrip().split(" "))
	d = ((x2 - x1)**2 + (y2 - y1)**2) ** 0.5
	if (d == 0 and r1 == r2) :
		ans.append("-1")
	elif (d > r1 + r2) or (d < abs(r1 - r2)) :
		ans.append("0")
	elif (d == r1 + r2) or (d == abs(r1 - r2)) :
		ans.append("1")
	elif (d < r1 + r2) :
		ans.append("2")

print("\n".join(ans))
