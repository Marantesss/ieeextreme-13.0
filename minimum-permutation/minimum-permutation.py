n, m = input().split()
n = int(n)
m = int(m)

listA=input().split()
listA=list(map(int, listA))
listS=input().split()
listS=list(map(int, listS))
listS.sort()

y=0
while len(listS)>0 :
    if listA[y] > listS[0]:
        listA.insert(y, listS[0])
        listS.pop(0)    
        y=0
    #print(listS)
    y+=1

for x in listA :
    print(x)