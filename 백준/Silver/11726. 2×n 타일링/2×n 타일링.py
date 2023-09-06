n=int(input())

a=[]

a.append(1)
a.append(2)

for i in range(0, n-2):
    a.append(a[i+1]+a[i])

print(a[n-1]%10007)