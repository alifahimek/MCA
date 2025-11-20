a = [1,2,3,4,5,6,7,8,-9,-10,-11,-12]
word ="jkdhsfkjahfkahkiuyhdBFAK"
newlist =[]
def genint():
    for i in a:
        if (0<i):
            print(i,"\t")
def squareOfNum():
    for i in a:
        print(i*i)


def vowels():
    for i in word:
        if ( i=='a' or i=='e' or i=='e' or i=='i' or i=='o' or i=='u' or i=='A' or i=='E' or i=='I' or i=='O' or i=='U' ):
            newlist.append(i)
    print(newlist)


def oedvalue():
    ordvalues=[ord(c) for c in word]
    print(ordvalues)
genint()
squareOfNum()
# oedvalue() 
# vowels()  