#!/bin/bash
GREEN="✅"
RED="❌"

echo "== 🌐 Test 1: ../../hbtn_ls /var (parent/parent)"
cp /bin/ls ../../hbtn_ls 2>/dev/null
env -i PATH=/bin ./hsh <<< "../../hbtn_ls /var"
status=$?
[ $status -eq 0 ] && echo "$GREEN OK" || echo "$RED KO (status: $status)"

echo -e "\n== 🌐 Test 2: ./.././../////././hbtn_ls /var"
cp /bin/ls ../../hbtn_ls 2>/dev/null
env -i PATH=/bin ./hsh <<< "./.././../////././hbtn_ls /var"
status=$?
[ $status -eq 0 ] && echo "$GREEN OK" || echo "$RED KO (status: $status)"

echo -e "\n== 🔒 Test 3: PATH='' and ls"
env -i PATH="" ./hsh <<< "ls"
status=$?
[ $status -eq 127 ] && echo "$GREEN OK" || echo "$RED KO (status: $status)"

echo -e "\n== 🧼 Test 4: no env at all (env -i ls)"
env -i ./hsh <<< "ls"
status=$?
[ $status -eq 127 ] && echo "$GREEN OK" || echo "$RED KO (status: $status)"

echo -e "\n== 💀 Test 5: PATH='' and fakecmd"
env -i PATH="" ./hsh <<< "fakecmd"
status=$?
[ $status -eq 127 ] && echo "$GREEN OK" || echo "$RED KO (status: $status)"

echo -e "\n== 🧪 Test 6: PATH1 only (no PATH)"
env -i PATH1="/bin" ./hsh <<< "ls"
status=$?
[ $status -eq 127 ] && echo "$GREEN OK" || echo "$RED KO (status: $status)"

echo -e "\n== ⚙️  Test 7: PATH=\$PWD and hbtn_ls /var"
cp /bin/ls ./hbtn_ls
env -i PATH="$PWD" ./hsh <<< "hbtn_ls /var"
status=$?
[ $status -eq 0 ] && echo "$GREEN OK" || echo "$RED KO (status: $status)"

echo -e "\n== 🧠 Test 8: no fork on invalid command"
if env -i PATH=/bin strace -f -e fork ./hsh <<< "invalidcmd" 2>&1 | grep -q fork; then
  echo "$RED Fork was called ❌"
else
  echo "$GREEN No fork called ✅"
fi

echo -e "\n== ✅ CHECK COMPLETED ✅ =="
