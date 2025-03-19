# **BCON- Byte Conversion Command Line Tool**

## **Overview**
`bconv` is a lightweight command-line tool for converting numbers between **binary**, **decimal**, and **hexadecimal** formats. It allows users to quickly perform conversions directly in the terminal without needing an interactive interface.

https://github.com/user-attachments/assets/282043a7-6a7a-401f-9b5b-1560aa4c306b

## **Features**
- Convert between **binary, decimal, and hexadecimal** number systems.
- Simple CLI syntax using flags.
- Efficient implementation using standard C.
- Works on Linux and macOS (and Windows via WSL or MinGW).

## **Installation**

### **1. Compile the Source Code**
Ensure you have `gcc` installed, then compile the program:
```
gcc main.c conversion.c -o bconv 
```

Or if you're on a mac use `clang` and compile 
```
clang -o bonv main.c conversion.c
```

## **Move the Executable**
Move the Executable to /usr/local/bin/ so that you can run bconv from anywhere in the terminal. 
```
sudo mv bconv /usr/local/bin/
```

## Usage

bconv <input_format_flag> <output_format_flag> <value>

Support flags include: 
    -b, for binary
    -d, for decimal
    -h, for hexadecimal



