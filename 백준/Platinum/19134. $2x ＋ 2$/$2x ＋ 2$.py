def calc(n):
    if n<4:
        return n
    elif n<10:
        return ((n+1)//2+1)
    else:
        return calc((n//2-3)//2)+(n+1)//2+1
        
print(calc(int(input())))