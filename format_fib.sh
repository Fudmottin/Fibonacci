#!/bin/bash

# Providing input and output file names
input_file="bigfib.txt"
output_file="formated_bigfib.txt"

# This awk command inserts a space every 5 characters and ensures line width of 80 characters.
awk '{gsub(/...../,"& "); print}' $input_file | fold -w 80 -s > $output_file

