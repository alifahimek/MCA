# n=int(input("enter a no"))

# def pattern(n):
#     for i in range(n):
#         if i < n//2:
#             for j in range(i+1):
#                 print("* ",end="")
#         else:
#             for j in range(i+1,n+1):
#                 print("* ",end="")
#         print("")
# pattern(n)
#diamond
# n = int(input("Enter a number: "))

# def pattern(n):
#     for i in range(n):
#         if i < n // 2:
#             stars = i + 1
#         else:
#             stars = n - i
#         # Print stars on the left
#         for j in range(stars):
#             print("* ", end="")
#         # Print spaces in the middle
#         spaces = (n - 2 * stars) * 2
#         for j in range(spaces):
#             print("  ", end="")5
#         # Print stars on the right5
#         for j in range(stars):
#             print("* ", end="")
#         print("")

# pattern(n)






n=int(input("enter a no"))

for i in range(1,n+1):
    for j in range(n-i):
        print(" ",end="")
    for k in range(1,2*i):
        print("*",end="")
        
   
    print() 