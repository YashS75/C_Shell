/* File: test/test_cases.sh */
#!/bin/bash

SHELL_EXEC=../bin/myshell
mkdir -p test_output

# Test 1: ls
echo "ls" | $SHELL_EXEC > test_output/out1.txt
ls > test_output/expected1.txt
diff test_output/out1.txt test_output/expected1.txt && echo "Test 1 Passed" || echo "Test 1 Failed"

# Test 2: echo
echo "echo Hello" | $SHELL_EXEC > test_output/out2.txt
echo "Hello" > test_output/expected2.txt
diff test_output/out2.txt test_output/expected2.txt && echo "Test 2 Passed" || echo "Test 2 Failed"

# Test 3: exit
(echo "exit" | $SHELL_EXEC > /dev/null) && echo "Test 3 Passed" || echo "Test 3 Failed"

# Cleanup
echo "Testing complete."

