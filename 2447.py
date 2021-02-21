def make_star(n) :
	if n == 3 :
		return ["***","* *","***"]
	else :	
		if n %3 != 0 :
			raise Exception("Not power of 3!")
		n = n // 3
		a = make_star(n)
		new_pattern = [0] * 3 * n
		for i in range(n) :
			new_pattern[i] = a[i] * 3
			new_pattern[n + i] = a[i] + " " * n + a[i]
			new_pattern[2*n + i] = a[i] * 3
	
		return new_pattern

if __name__ == "__main__" :
	num = int(input().rstrip())
	ans = make_star(num)
	print("\n".join(ans))
	
