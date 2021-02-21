num = [x for x in range(1,10000)]
def find(n,l) :
    if n > 10000 :
        return
    new = n
    for i in str(n) :
        new += int(i)
    if new == n :
        return
    if new in l :
        l.remove(new)
    else :
        return
    return find(new,l)

for i in num :
    find(i,num)

print("\n".join(str(x) for x in num))
