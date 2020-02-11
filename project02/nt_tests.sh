#set -x

run_test () {
    echo $1
    eval $1
    echo
}

echo "=== Website Tests ==="
run_test "./nt 713"
run_test "./nt -713"
run_test "./nt 0b11100011"
run_test "./nt 0xE3"
run_test "./nt -b 16 713"
run_test "./nt -b 16 -713"
run_test "./nt -b 8 0xE0"
run_test "./nt -b 4 -r 4,7 0b000010100000"
echo "=== Grading Tests ==="
run_test "./nt 0"
run_test "./nt 1"
run_test "./nt 2"
run_test "./nt -1"
run_test "./nt -2"
run_test "./nt 4294967295"
run_test "./nt 4294967296"
run_test "./nt 429496729600"
run_test "./nt 2147483647"
run_test "./nt -2147483648"
run_test "./nt -2147483649"
run_test "./nt 0b00000000000000000000001011001001"
run_test "./nt 0x000002C9"
run_test "./nt 0b11111111111111111111110100110111"
run_test "./nt 0xFFFFFD37"
run_test "./nt 713"
run_test "./nt -b 4 -r 0,3 0x000002C9"
run_test "./nt -b 8 -r 0,7 0x000002C9"
run_test "./nt -b 4 -r 4,7 0x000002C9"
echo "=== Additional Tests ==="
run_test "./nt -b 4 -r 28,31 0xABCDEF12"
run_test "./nt -b 8 -r 24,31 0xABCDEF12"
run_test "./nt -b 16 -r 16,31 0xABCDEF12"
run_test "./nt -b 32 -r 0,31 0xABCDEF12"
run_test "./nt -b 4 -r 16,19 0xABCDEF12"
run_test "./nt"
