import os
import re
import shutil
import time


python_code_pattern = re.compile(r'```python(.*?)```', re.DOTALL)


root_dir = 'models/Gpt-3.5-turbo/full_responses/gpt-3.5-turbo/problems'
# Ensure /code directory exists


if not os.path.exists('code'):
    os.makedirs('code')

# Get the current folder path
current_dir = os.getcwd()

for subdir, dirs, files in os.walk(root_dir):
    print(f'Visiting directory: {subdir}')
    print(f'Files: {files}')
    for file in files:
        if file.endswith(".txt"):
            print(file)
            # Read file content
            with open(os.path.join(subdir, file), 'r') as f:
                content = f.read()

            # Extract python code
            matches = python_code_pattern.findall(content)
            if matches:
                # Concatenate all the python code blocks
                python_code = '\n'.join(matches)
                
                # Determine the new file path
                rel_dir = os.path.relpath(subdir, root_dir)
                new_dir = os.path.join(current_dir, 'code', rel_dir)
                
                # Ensure the directory exists
                if not os.path.exists(new_dir):
                    os.makedirs(new_dir)
                
                problem = file.rsplit('.', 1)[0]
                new_file_path = os.path.join(new_dir, f"{problem}.py")
                
                # Write the python code to a new .py file
                with open(new_file_path, 'w') as f:
                    f.write(python_code)
                    print('Writing:', new_file_path)
                
                print(python_code)

print('Extraction completed.')