#!/bin/bash
# Demonstration of file deletion functionality in calc program

echo "=== Building the calc program ==="
cd "$(dirname "$0")"
mkdir -p build
cd build
cmake .. && make

echo -e "\n=== Demonstrating arithmetic operations (original functionality) ==="
./prog 12 4

echo -e "\n=== Demonstrating file deletion functionality ==="
echo "This is a test file for deletion" > demo_file.txt
echo "Created file: demo_file.txt"
ls -la demo_file.txt

echo -e "\nDeleting file using: ./prog delete demo_file.txt"
./prog delete demo_file.txt

echo -e "\nVerifying file was deleted:"
ls -la demo_file.txt 2>/dev/null || echo "File no longer exists ✓"

echo -e "\n=== Error handling demonstration ==="
echo "Attempting to delete non-existent file:"
./prog delete non_existent_file.txt

echo -e "\n=== Usage help ==="
./prog

echo -e "\nFile deletion functionality successfully implemented!"
echo "Usage: ./prog delete <filename>  (to delete files)"
echo "       ./prog <num1> <num2>     (for arithmetic operations)"