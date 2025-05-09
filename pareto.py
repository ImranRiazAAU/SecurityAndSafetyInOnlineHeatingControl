#!/bin/python3

import sys
import matplotlib.pyplot as plt
import numpy as np
import csv
import re
import statistics
from functools import cmp_to_key
rownames = ["Distance","comfort","cost"]

def parse_data(filename, rowno):
    global rownames
    data = []
    with open(filename, newline='') as csvfile:
        reader = csv.DictReader(csvfile,fieldnames=rownames)
        for row in reader:
            print(row)
            rn = rownames[rowno]
            data += [float(row[rn])]

    if len(data) == 0:
        return (0,0)
    else:
        return (statistics.mean(data), statistics.stdev(data))

files = sys.argv[2:]
exp = None
labels = set()
settings = {}
norm_settings = {}
bb_cost = 0
bb_comf = 0
for f in files:
    params = f.split('/')[-1].split('.')
    if exp is None:
        exp = params[0]
    if params[0] != exp:
        print(f"Expected all files to be from experiment type {exp} but got {params[0]}")
        exit(-1)
    lbl = ".".join(params[2:])
    labels.add(lbl)
    if params[1] not in settings:
        settings[params[1]] = {}
        of = exp.replace("C0", "C1")
    if lbl not in norm_settings:
        nf = f.replace("C0", "C1").replace(params[1], "R1I5")
        (bb_comf, _) = parse_data(nf, 1)
        (bb_cost, _) = parse_data(nf, 2)

    (comf_mn, _) = parse_data(f, 1)
    (cost_mn, _) = parse_data(f, 2)

    settings[params[1]][lbl] = (comf_mn, cost_mn) 


def compare(item1, item2):
    a = float(re.match(r"A(.*)G", item1).group(1))
    b = float(re.match(r"A(.*)G", item2).group(1))
    if a < b:
        return -1
    elif a > b:
        return 1
    else:
        return 0

# Calling

fig, ax = plt.subplots()
ax.set_ylabel(f"Cost")
ax.set_xlabel("(Dis-)Comfort")
ax.set_title(f"Pareto frontier")

n = 0

def kcmp(item1, item2):
    a = float(re.match(r"R(.*)I", item1).group(1))
    b = float(re.match(r"R(.*)I", item2).group(1))
    if a > b:
        return 1
    elif a < b:
        return -1
    else:
        return 0

skeys = sorted(settings.keys(), key=cmp_to_key(lambda item1, item2: kcmp(item1, item2)))
for k in skeys:
    print(k)
    print(settings[k])
    lbls = [x for x in settings[k].keys()]
    lbls = sorted(lbls, key=cmp_to_key(lambda item1, item2: compare(item1, item2)))

    vals = [settings[k][x] for x in lbls]
    plt.plot([x for (x,y) in vals], [y for (x,y) in vals],label=k)
ax.plot(bb_comf, bb_cost, 'go', label='BB-Controller')
ax.legend()
fig.tight_layout()

plt.show()
