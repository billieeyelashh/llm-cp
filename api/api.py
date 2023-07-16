import openai
import os
import time
import re

openai.api_key = os.getenv("OPENAI_API_KEY")
model = "gpt-4"

#print(openai.Model.list())

prompt = [
    {"role": "system", "content": "Imagine you are a world-class competitive programmer with multiple gold medals in the IOI. You always strive to solve problems in the most optimal way possible."},
    {"role": "user", "content": "Think carefully and step-by-step. Provide your final solution in C++. Keep your explanations short and concise."},
]

code_pattern = re.compile(r'```cpp(.*?)```', re.DOTALL)

rootdir = 'problems/'
code_dir = 'models/Gpt-4/cpp/code'
full_response_dir = 'models/Gpt-4/cpp/full_responses'

count = 0

for subdir, dirs, files in os.walk(rootdir):
    for file in files:
        try:
            print(file)
            file_path = os.path.join(subdir, file)
            with open(file_path, 'r') as f:
                lines = f.readlines()
            prompt.append({"role": "user", "content": ''.join(lines)})
            print(prompt)
            response = openai.ChatCompletion.create(
                model=model,
                messages=prompt,
                temperature=0.7,
                max_tokens=1000,
                presence_penalty=0.3,
            )

            # Full responses directory
            full_response_subdir = os.path.join(full_response_dir, subdir)
            os.makedirs(full_response_subdir, exist_ok=True)
            response_file_path = os.path.join(full_response_subdir, file.rsplit('.', 1)[0] + '.txt')
            with open(response_file_path, 'w', encoding='utf-8') as f:
                f.write(response['choices'][0]['message']['content'])

            # Extract C++ code and write to a file in the 'code' directory
            code_subdir = os.path.join(code_dir, subdir)
            os.makedirs(code_subdir, exist_ok=True)
            cpp_code = re.search(code_pattern, response['choices'][0]['message']['content'])
            if cpp_code:
                code_file_path = os.path.join(code_subdir, file.rsplit('.', 1)[0] + '.cpp')
                with open(code_file_path, 'w', encoding='utf-8') as f:
                    f.write(cpp_code.group(1))

            print(f'Successfully wrote {file} to {full_response_subdir} and {code_subdir} - Total files processed: {count}')
            count += 1

        except UnicodeEncodeError:
            print(f'UnicodeEncodeError encountered while processing {file}')

        except Exception as e:
            print(f'Encountered an error while processing {file}: {e}')

        finally:
            prompt = prompt[:-1]