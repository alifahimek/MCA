import pandas as pd

columns = ["Maxpulse"]

file = pd.read_csv("some.csv",usecols=columns)
print(file)