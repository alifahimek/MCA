import datetime

crntyear = datetime.datetime.now().year
year = int(input("enter a year after 2025\n"))
if(year>crntyear):
    for i in range (crntyear,year+1):
        
            if(i % 4 == 0 and i % 100 != 0 or i % 400 == 0):
               
             print(i)
       