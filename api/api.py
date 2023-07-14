import openai
import os

openai.api_key = os.environ.get("OPENAI_API_KEY")
model = "gpt-3.5-turbo-0613"
prompt = 'You are a world class competitive programmer. You repond only python or cpp code. No text or explanations. Just code.'


rootdir = 'problems/'
for subdir, dirs, files in os.walk(rootdir):
    for file in files:
        print(file)
        file_path = os.path.join(subdir, file)
        with open(file_path, 'r') as f:
            lines = f.readlines()
        prompt += ''.join(lines)
        print(prompt)
        response = openai.Completion.create(
            engine=model,
            prompt=prompt,
            temperature=0.7,
            max_tokens=1000,
            presence_penalty=0.3,
            stop=["\n\n"]
        )
        with open(f'models/gpt-3.5-turbo/{file}', 'w') as f:
            f.write(response['choices'][0]['text'])
            time.sleep(5)
        print(f'Successfully wrote {file}')