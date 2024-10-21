def fibo(n):
    if n<=1:return [n,1]
    return [fibo(n-1)[0]+fibo(n-2)[0],fibo(n-1)[1]+fibo(n-2)[1]]

print(fibo(5))