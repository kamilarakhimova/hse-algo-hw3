import os
import csv
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib import rcParams
rcParams['figure.figsize'] = 15, 5
rcParams['font.size'] = '12'

files = []
for file in os.listdir(r'TablesForGraphs'):
    files.append(file)

folder = "Graphs/"

for name in files:
    x = []
    y1 = []
    y2 = []
    y3 = []
      
    with open(name,'r') as csvfile:
        lines = csv.reader(csvfile, delimiter=';')
        for row in lines:
            if (len(row) != 0):
              x.append(int(row[0]))
              y1.append(int(row[1]))
              y2.append(int(row[2]))
              y3.append(int(row[3]))
    
    plt.plot(x, y1, color = 'red', label = "Complete graph")
    plt.plot(x, y2, color = 'blue', label = "Connected graph")
    plt.plot(x, y3, color = 'green', label = "Sparse graph")
    
    plt.xlabel('Количество вершин', fontweight="bold")
    plt.ylabel('Время, нс', fontweight="bold")
    plt.title(name[:-4:], fontsize = 20, fontweight="bold")
    plt.grid()
    plt.legend(bbox_to_anchor=(1, 0.6))
    plt.savefig(name[:-3:] + 'png')
