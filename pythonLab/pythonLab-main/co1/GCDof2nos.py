a=int(input("enter first no    "))
b=int(input("enter scnd no  "))

while b>0:
   temp = a
   a=b
   b = temp%b
print(a)