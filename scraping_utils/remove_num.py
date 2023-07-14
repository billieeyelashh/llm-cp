# remove the numbers fomr the problem names at the start. If  the problem name is '1. Weird_Algorithm', it will be changed to 'Weird_Algorithm' If there is no nubmer in front just ignore it.abs

import os
import re

folder_name = 'problems'
for file_name in os.listdir(folder_name):
    file_path = os.path.join(folder_name, file_name)
    with open(file_path, 'r') as f:
        lines = f.readlines()
    lines[0] = re.sub(r'^\d+\.\s', '', lines[0])
    with open(file_path, 'w') as f:
        f.writelines(lines)