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

rowno = int(sys.argv[1])
files = sys.argv[2:]
exp = None
labels = set()
settings = {}
norm_settings = {}

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
        (mn, _) = parse_data(nf, rowno)
        norm_settings[lbl] = mn
    (mn, st) = parse_data(f, rowno)
    n = norm_settings[lbl]
    settings[params[1]][lbl] = (mn/n, st/n) 


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
lbls = [x for x in labels]
lbls = sorted(lbls, key=cmp_to_key(lambda item1, item2: compare(item1, item2)))
width = 0.35  # the width of the bars

fig, ax = plt.subplots()
x = np.arange(len(lbls))
ax.set_ylabel(f"{rownames[rowno]} relative to BB")
ax.set_xlabel("focus on comfort")
ax.set_title(f"{exp} ({rownames[rowno]})")
ax.set_xticks(x)
ax.set_xticklabels([float(re.match(r"A(.*)G", x).group(1)) for x in lbls])
plt.xticks(rotation=90)

n = 0
w = width / len(settings.keys())

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
    # ax.bar(x_pos, CTEs, yerr=error, align='center', alpha=0.5, ecolor='black', capsize=10)
    x_pos = x + (w*n*2) - width
    vals = [settings[k][x] for x in lbls]
    rect = ax.bar(x_pos, [x for (x,y) in vals], width, yerr=[y for (x,y) in vals], label=k,ecolor='black', capsize=2)
    ax.bar_label(rect, padding=3,rotation=90,fmt='%0.2f')
    n += 1

ax.legend()
fig.tight_layout()

plt.show()
