n, a, b = input("").split()
n = int(n)
a = int(a)
b = int(b)

def verify():
    if a*2<=n:
        return True
    return False
    
def sequence():
    if a*2 == n:
        return 0
    if a+a+1 == n:
        return 1
    #poe aqui o codigo do troco

if not verify():
    print("NO")
    quit()
else:
    print("YES")

if sequence()==0:
    a=str(a)
    print(a + " " + a)



