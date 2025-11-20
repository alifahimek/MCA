class Account:
    def __init__(self,name,acc_no,bal):
        self.name=name
        self.acc_no=acc_no
       
        self.bal=bal


    def deposit(self,amount):
            self.bal+=amount
            print(f"Deposited {amount} sucessfully")
        

    def withdraw(self,amount):
            if self.bal<amount:
                print("insuffucient balance")
            else:
                self.bal-=amount
                print(f"{amount} withdrawn")

    def display(self):
            print(f"name:{self.name}\n account no:{self.acc_no}\nbalance:{self.bal}")





accountnno=int(input("enter account number  "))
name=input("enter name  ")

member=Account(name,accountnno,0)

while True:
 member.display()
 transaction=int(input("1.deposit\n2.withdraw\n3.to end\ntype:"))

 if transaction==1:
   member.deposit(int(input("enter the amount to depost")))
 elif transaction==2:
    member.withdraw(int(input("ener the amount to withdraw")))
 elif transaction==3:
      exit()
      