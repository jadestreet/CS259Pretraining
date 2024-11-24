# Overview
This repo is used for UCLA CS259 course project pretraining. The exact components are as follows:
## Code (folder)
In this folder, there are 2,000 executable c files.
All the files are extracted from https://huggingface.co/datasets/codeparrot/github-code.
To use the files, feel free to clone a copy to your PC.
git clone https://github.com/jadestreet/CS259Pretraining.git
## 259_2k.csv
This csv file contains the following attributes:
'unique_id', 'repo_name', 'path',
'effective_code_length', 'loop_count', 'computation_count',
'execution_time', 'execution_time_cycles', 'instruction_count', 'cpi',
'I1mr', 'ILmr', 'Dr', 'Dw', 'D1mr', 'D1mw', 'DLmr', 'DLmw', 'instruction_cache_miss_rate',
'data_cache_miss_rate',
'cpu_fre', 'total_memory', 'code'
