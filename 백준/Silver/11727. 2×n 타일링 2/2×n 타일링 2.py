n=int(input())

a=[]

a.append(1)
a.append(3)

for i in range(0, n-2):
    a.append(a[i+1]+2*a[i])

print(a[n-1]%10007)
