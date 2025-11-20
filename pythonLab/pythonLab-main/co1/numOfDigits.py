n = int(input("Input number: "))
count = 0

while n != 0:
    n //= 10
    count += 1

print("Number of digits:", count)
