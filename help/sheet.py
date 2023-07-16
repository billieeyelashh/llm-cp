import pandas as pd 
import os 

#read the csv file 
df = pd.read_csv('problems.csv')
print(df)

# in the failure mode columm there are three types of failure modes: 'ACCEPTED', 'WRONG ANSWER', 'COMPILE ERROR' every other item in this list should be 'WRONG ANSWER'

#save to csv
df.to_csv('problems.csv', index=False)

# Get count of ACCepted and compile error
print(df['failure-mode'].value_counts())

# I want to add all the problems again in the problems columns. The failure-mode, prompt, and programming language columns should be empty.


import pandas as pd
import numpy as np

# Assuming 'df' is your DataFrame
df_copy = df.copy()

# Select necessary columns and create a new DataFrame
new_rows = df_copy[['problems', 'category', 'model', 'prompt-type']].copy()

# For 'failure-mode', 'programming-lang', 'prompt', fill them with NaN
new_rows['failure-mode'] = np.nan
new_rows['programming-lang'] = np.nan
new_rows['prompt'] = np.nan

# Append the new rows to the original DataFrame
df_copy = df_copy.append(new_rows, ignore_index=True)

# Show the updated DataFrame
print(df_copy)

#save to csv
df_copy.to_csv('problems.csv', index=False)





