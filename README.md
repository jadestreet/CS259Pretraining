# Overview
This repo is used for UCLA CS259 course project pretraining. The exact components are as follows:
## Code (folder)
In this folder, there are 2,000 executable c files.  
All the files are extracted from https://huggingface.co/datasets/codeparrot/github-code. This dataset collects files from the GitHub.  
To use the files, feel free to clone a copy to your PC.  
```bash
git clone https://github.com/jadestreet/CS259Pretraining.git
```
## 259_2k.csv
This csv file records some attributes of these c files, including:  
'unique_id' (unique identifier), 'repo_name', 'path',  
'effective_code_length', 'loop_count', 'computation_count', (Some simple metric of static code)
'execution_time', 'execution_time_cycles', 'instruction_count', 'cpi', (Time & instruction metric)  
'I1mr', 'ILmr', 'Dr', 'Dw', 'D1mr', 'D1mw', 'DLmr', 'DLmw', 'instruction_cache_miss_rate',
'data_cache_miss_rate', (profiling metric using cachegrind)  
'cpu_fre', 'total_memory', 'code'
## decompose.py
The script to decompose code from 259_2k.csv.
