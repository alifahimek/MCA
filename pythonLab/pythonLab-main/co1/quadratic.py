import math

import cmath
a=int(input("enter the a"))
b=int(input("enter the b"))
c=int(input("enter the c"))
D=(b**2) -( 4*a*c)

if D>0:
 r1=((-b + math.sqrt(D)))/(2*a)
 r2=((-b - math.sqrt(D)))/(2*a)
elif D==0:
 r1=r2=-b/2*a
else:
 r1=(-b + cmath.sqrt(D))/(2*a)
 r2=(-b - cmath.sqrt(D))/(2*a)

print("the root1 is ",r1)
print("the root2 is ",r2)