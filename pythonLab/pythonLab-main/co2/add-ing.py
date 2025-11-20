str = input("enter a string")

def add(str):
    if str[-3:0]=="ing":
        return str+"ly"
    else:
        return str+"ing"

print(add(str))
