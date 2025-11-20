x = int(input("enter first word"))
y = int(input("enter scnd word"))
z = int(input("enter scnd word"))

if(x>y and x>z ):
    print(x,"is largest")
elif(y>x and y>z):
    print(y,"is largest")
else:
    print(z," is largest")