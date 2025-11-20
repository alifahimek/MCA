s=(input("enter a string"))
# slist=list(s)
# n=len(s)

# for i in slist:
#     t=slist[0]
#     slist[0]=slist[n-1]
#     slist[n-1]=t

# print("reversed str is",s)

print(s[-1] + s[1:len(s)-1] + s[0] )