import csv

with open(input("file: "),"r") as file:
  reader = csv.reader(file)
  for row in reader:
    print(row)