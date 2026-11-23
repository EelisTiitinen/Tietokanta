#!/bin/bash

c_files=(
    main
    file
    str
)

asm_files=(
    io
    string
)

for file in "${c_files[@]}"; do
    gcc -c "$file.c" -o "$file.o"
done

for file in "${asm_files[@]}"; do
    nasm -f elf64 "$file.asm" -o "$file.o"
done

obj_files=()

for file in "${c_files[@]}" "${asm_files[@]}"; do
    obj_files+=("$file.o")
done

gcc "${obj_files[@]}" -o app

rm -f "${obj_files[@]}"
