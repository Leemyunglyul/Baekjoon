a, b = map(int, input().split())
x=1
y=1
for i in range(a, a+b-1):
    x*=i+1
for i in range(1, b-1):
    y*=i+1
z=x//y
print(z%1000000000)