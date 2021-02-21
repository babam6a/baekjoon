num = int(input().rstrip().rjust(2,'0'))
old_num = num
count = 0
while True :
	a = num // 10
	b = num % 10
	new = b * 10 + ((a + b) % 10)
	count += 1
	if old_num == new :
		break
	else :
		num = new

print(count)
