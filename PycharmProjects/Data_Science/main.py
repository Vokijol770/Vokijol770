import pandas

data = pandas.read_csv('polomki.csv', index_col='Магазин')

print(data)