# First 1,000,000 Digit Fibonacci Number

This project contains a C++ program that generates the first Fibonacci number with 1,000,000 digits.
It also includes a bash script that formats the output to be more readable.

## Code Explanation

### C++ Program
```c++
#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;
using namespace std;

int main() {
    cpp_int a = 1;
    cpp_int b = 1;
    cpp_int next_a = b;

    for (int i = 0; i < 4784967; ++i) {
        next_a = b;
        b += a;
        a = next_a; 
      }

   cout << b << endl;

   return 0;
}
```
The above program uses the Boost.Multiprecision library to handle large integers which can't be stored
in built-in data types. In this program, `cpp_int` is used to store large integers.

The initial two numbers in the Fibonacci sequence are both set to `1`. The main loop runs for about `4.78`
million times - enough iterations to generate the first Fibonacci number with `1,000,000` digits.
The loop count was estimated using this formula:

```
index ≈ (n-1)/log10(φ) where φ is the golden ratio (~1.61803398875).
```

Several trials were required to find our desired Fibonacci number. The output of the program was directed
to a text file named bigfib.txt.

### Bash Command To Confirm The Digit Count:
```bash
tr -d '\n' < bigfib.txt | wc -c 
```
This command counts characters in file named 'bigfib.txt'. It first removes newline characters using 'tr'
command and then pipes ('|') output into 'wc -c' command which counts the number of characters, thereby
giving us the total number of digits in our Fibonacci number.

### Bash Script To Format The Output:

```bash
#!/bin/bash

# Providing input and output file names
input_file="bigfib.txt"
output_file="formated_bigfib.txt"

# This awk command inserts a space every 5 characters and ensures line width of 80 characters.
awk '{gsub(/...../,"& "); print}' $input_file | fold -w 80 -s > $output_file
```
This script reads from 'bigfib.txt' file as input. It uses awk to insert a space after every five
characters making it easier to count the number of digits in each line. Then, 'fold' command is
used to limit the width of each line to 80 characters keeping digits intact with '-s' option.
The formatted output is then redirected into 'formated_bigfib.txt'.

## Compilation Instructions:

You need Boost C++ library installed on your system to compile this program.

Below is an example compilation command for an M2 Mac mini:

``` bash
c++ -std=c++20 -O3 -I /opt/homebrew/include -o fib fib.cpp
```

This is a sample run on my machine:

```
$ time ./fib >> bigfib.txt
./fib >> bigfib.txt  179.16s user 0.02s system 99% cpu 2:59.62 total
```

