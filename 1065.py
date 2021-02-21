n = int(input().rstrip())
num = [str(x) for x in range(1,n+1)]
count = 0

def is_han(n) :
    if len(n) <= 2 :
        return True
    diff = int(n[0]) - int(n[1])
    for i in range(1,len(n)-1) :
        if int(n[i]) - int(n[i+1]) != diff :
            return False
    return True

for i in num :
    if is_han(i) :
        count += 1

print(count)
