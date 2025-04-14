#!/bin/bash

echo "=== 🧪 Test 1: /bin/ls ==="
echo "/bin/ls" | ./hsh

echo -e "\n=== 🧪 Test 2: ls (via PATH) ==="
echo "ls" | ./hsh

echo -e "\n=== 🧪 Test 3: ls -l /tmp (with args) ==="
echo "ls -l /tmp" | ./hsh

echo -e "\n=== 🧪 Test 4: invalid command ==="
echo "qwerty" | ./hsh

echo -e "\n=== 🧪 Test 5: env builtin ==="
echo "env" | ./hsh

echo -e "\n=== ✅ DONE: Task 4 Simulation Complete ==="
