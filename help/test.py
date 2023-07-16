import openai
import os
import time

#openai.api_key = os.environ.get("OPENAI_API_KEY")

# list openai models 
answer = (openai.Model.list())

#  grep out the models out of the lsit
models = []
for i in range(len(answer['data'])):
    models.append(answer['data'][i]['id'])

# print the models
print(models)
