import csv

mydict = [{"first":"harry","last":"potter"},{"first" :"ron","last":"weasly"},
          {"first":"hermione","last":""
          "Granger"}]

with open("new.csv","w")as file:
    writer=csv.DictWriter(file,fieldnames=["first","last"])
    writer.writeheader()
    writer.writerows(mydict)

with open("new.csv","r") as csvfile:
    file = csv.DictReader(csvfile)
    for row in file:
        print(row)