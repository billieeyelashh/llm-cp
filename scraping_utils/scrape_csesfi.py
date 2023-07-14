import os
import requests
from bs4 import BeautifulSoup
import time

count = 0
folder_name = 'problems'
if not os.path.exists(folder_name):
    os.makedirs(folder_name)


url = 'https://cses.fi/problemset/task/1068'
for i in range(0,6000):
    time.sleep(0.1)
    page = requests.get(url)
    soup = BeautifulSoup(page.content, 'html.parser')
    content = soup.find('div', class_='content')
    if content:
        title = soup.find('title')
        problem_statement = content.text
        if title and problem_statement:
            title_text = f'{title.text.replace("CSES - ", "").replace(" ", "_")}'
            count += 1
            print(count)
            problem_statement_lines = problem_statement.split('\n')[3:]
            formatted_problem_statement_lines = ['Problem Statement:', '']
            for line in problem_statement_lines:
                line = line.strip()
                if line.startswith('Time limit:') or line.startswith('Memory limit:'):
                    continue
                if line in ['Input', 'Output', 'Constraints', 'Example']:
                    formatted_problem_statement_lines.append('')
                    line += ':'
                if line:
                    formatted_problem_statement_lines.append(line)
            formatted_problem_statement = '\n'.join(formatted_problem_statement_lines)
            file_path = os.path.join(folder_name, f'{title_text}.txt')
            with open(file_path, 'w') as f:
                f.write(formatted_problem_statement)
            print(f'Successfully downloaded problem {i}')
        else:
            if not title:
                print(f'Could not find title for problem {i}')
            if not problem_statement:
                print(f'Could not find problem statement for problem {i}')
    else:
        print(f'Could not find content for problem {i}')
    url = url[:-4] + str(i+1)
