str = input("enter a string")
def charfreq(str,x):
    count =0
    for i in range(len(str)):
        if str[i]==x:
            count+=1
    
    return count

frequency={x:charfreq(str,x)for x in str}

print(frequency)