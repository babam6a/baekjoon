num = int(input().rstrip())

count_0 = [0] * 41
count_1 = [0] * 41
is_calc = [0] * 41

def fibonacci(n,base) :
	if is_calc[base] > 0 :
		return
	if n == 0 :
		count_0[base] += 1
		return 0
	elif n == 1 :
		count_1[base] += 1
		return 1
	else :
		if is_calc[n-1] > 0 :
			count_0[base] += count_0[n-1]
			count_1[base] += count_1[n-1]
		else: 
			fibonacci(n-1,base)

		if is_calc[n-2] > 0 :
			count_0[base] += count_0[n-2]
			count_1[base] += count_1[n-2]
		else :
			fibonacci(n-2,base)


if __name__ == "__main__" :
	for i in range(20) :
		fibonacci(i,i)
		is_calc[i] = 1
	for i in range(num) :
		n = int(input().rstrip())
		fibonacci(n,n)
		is_calc[n] = 1
		print("%d %d"%(count_0[n], count_1[n]))
