import os
import pandas as pd

rootdir = 'problems/'

# Iterate through all the files in the root directory. Save each problem in the "problems" column. The "category" column is the name of the folder where the problem is located.
problems = []
categories = []

for subdir, dirs, files in os.walk(rootdir):
    for file in files:
        problems.append(file)
        categories.append(subdir.rsplit('/', 1)[1])

# Create DataFrame after all files have been processed
df = pd.DataFrame({'problems': problems, 'category': categories})

# Save DataFrame to a CSV file
df.to_csv('problems.csv', index=False)

#save to excel
df.to_excel('problems.xlsx', index=False)

  

