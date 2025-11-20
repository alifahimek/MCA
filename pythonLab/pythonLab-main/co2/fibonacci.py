a=int(input("enter the limit"))

#fibonacci

def fib(a):
    if a <=1:
        return a
    else:
        return fib(a-2)+fib(a-1)

for i in range (a):
 print(fib(i) , end=",") 