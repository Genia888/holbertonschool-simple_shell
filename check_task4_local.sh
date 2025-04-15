#!/bin/bash

echo "== 🧪 Test 1: PATH -> ls = OK"
env -i PATH=/bin ./hsh <<< "ls"

echo -e "\n== 🧪 Test 2: ABSOLUTE -> /bin/ls = OK"
env -i ./hsh <<< "/bin/ls"

echo -e "\n== 🧪 Test 3: With args -> ls -l /tmp"
env -i PATH=/bin ./hsh <<< "ls -l /tmp"

echo -e "\n== 🧪 Test 4: Trim test -> '     ls     '"
env -i PATH=/bin ./hsh <<< "     ls     "

echo -e "\n== 🧪 Test 5: PATH = '' (empty)"
env -i PATH="" ./hsh <<< "ls"

echo -e "\n== 🧪 Test 6: No PATH + fallback /bin/ls"
env -i ./hsh <<< "/bin/ls"

echo -e "\n== 🧪 Test 7: Invalid cmd -> NO FORK"
env -i PATH=/bin strace -f -e fork ./hsh <<< "invalidcmd" 2>&1 | grep -q fork && echo "❌ Fork called" || echo "✅ No fork called"

echo -e "\n== 🧪 Test 8: Builtin env"
env -i PATH=/bin ./hsh <<< "env"

echo -e "\n== ✅ LOCAL CHECK FINISHED ✅ =="
