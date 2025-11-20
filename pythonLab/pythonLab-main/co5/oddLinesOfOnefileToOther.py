newfile=open("co5\one.txt","w")


file1=open("co5\demo.txt","r")
file2=open("co5\one.txt","a")

count=0

for line in file1:
    count += 1
    if count %2!=0:
        file2.write(line)