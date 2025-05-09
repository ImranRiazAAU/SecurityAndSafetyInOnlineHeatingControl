#!/usr/bin/python3

import matplotlib.pyplot as plt
plt.style.use('seaborn-whitegrid')
import pandas as pd
import numpy as np
import sys
import os

path = sys.argv[1]
ROOMS=4
EM_ENV_PATH = "EM_envelop_temp_log.txt"
LM_ENV_PATH = "LM_envelop_temp_log.txt"
EM_FLR_PATH = "EM_floor_temp_log.txt"
LM_FLR_PATH = "LM_floor_temp_log.txt"
files={}
with os.scandir(path) as folder:
    for entry in folder:
        #print(entry.path)
        if entry.name == LM_FLR_PATH:
            files["LM-floor"] = entry.path
       	elif entry.name == EM_FLR_PATH:
       	    files["EM-floor"] = entry.path
        elif entry.name == LM_ENV_PATH:
            files["LM-env"] = entry.path
       	elif entry.name == EM_ENV_PATH:
      	    files["EM-env"] = entry.path
EM_Envelop = pd.read_csv(files["EM-env"], header=None)
LM_Envelop = pd.read_csv(files["LM-env"], header=None)

for i in range(ROOMS):
    index = str(i+1)
    plt.subplot(2, 2, i+1)
    diff = EM_Envelop[[i]] - LM_Envelop[:-1][[i]]
    plt.xlabel('Difference')
    plt.ylabel('Number of occurances')
    plt.hist(diff, label = "EM_Te-LM_Te (Room"+index+")")
    plt.legend()
plt.show()

EM_Floor = pd.read_csv(files["EM-floor"], header=None)
LM_Floor = pd.read_csv(files["LM-floor"], header=None)

for i in range(ROOMS):
    index = str(i+1)
    plt.subplot(2, 2, i+1)
    diff = EM_Floor[[i]] - LM_Floor[:-1][[i]]
    plt.xlabel('Difference')
    plt.ylabel('Number of occurances')
    plt.hist(diff, label = "EM_Th-LM_Th (Room"+index+")")
    plt.legend()
plt.show()
