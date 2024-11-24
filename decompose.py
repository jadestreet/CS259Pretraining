import pandas as pd
from concurrent.futures import ThreadPoolExecutor, as_completed
import os

code_path = '/home/jade/HF/0scripts/259/259_2k.csv'
file_decomposition_output_directory = '/home/jade/HF/0scripts/259/code'
thread_num = 40
data = pd.read_csv(code_path)

if not os.path.exists(file_decomposition_output_directory):
    os.makedirs(file_decomposition_output_directory)
    
def process_file(row):
    '''    
    repo_name = row['repo_name']
    
    code = row['code']

    full_file_path = os.path.join(file_decomposition_output_directory, os.path.basename(file_path))
    '''
    code = row['code']
    file_path = row['path']
    file_name = row['unique_id'] + os.path.basename(file_path)
    full_file_path = os.path.join(file_decomposition_output_directory, file_name)
    
    with open(full_file_path, 'w') as code_file:
        code_file.write(code)

with ThreadPoolExecutor(max_workers=thread_num) as executor:
    futures = [executor.submit(process_file, row) for _, row in data.iterrows()]
    for future in as_completed(futures):
        pass