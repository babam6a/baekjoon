def switch(n) :
    ans = [0] * 10
	
    for i in n :
        if i == '0' :
            ans[0] += 1
        elif i == '1' :
            ans[1] += 1
        elif i == '2' :
            ans[2] += 1
        elif i == '3' :
            ans[3] += 1
        elif i == '4' :
            ans[4] += 1
        elif i == '5' :
            ans[5] += 1
        elif i == '6' :
            ans[6] += 1
        elif i == '7' :
            ans[7] += 1
        elif i == '8' :
            ans[8] += 1
        elif i == '9' :
            ans[9] += 1
        else :
            Exception("Something bad happened..")
    return ans

res = 1
for i in range(3) :
    res *= int(input().rstrip())
ans = switch(str(res))
print("\n".join(map(str,ans)))
