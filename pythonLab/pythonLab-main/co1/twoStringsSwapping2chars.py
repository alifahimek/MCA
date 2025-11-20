s=(input("enter a string"))
l=(input("enter a string"))
firstlist=list(s)
scndlist=list(l)

print(s[0] + l[1] + s[2:] + l[0]+ s[1] + l[2:])