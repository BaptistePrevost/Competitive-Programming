set -e
path=/home/bprevost/Competitive-Programming/stress-testing
g++ ${path}/code.cpp -o ${path}/code
g++ ${path}/generator.cpp -o ${path}/generator
g++ ${path}/brute.cpp -o ${path}/brute
for((i = 1; ; ++i)); do
    ${path}/generator $i > ${path}/input_file
    ${path}/code < ${path}/input_file > ${path}/myAnswer
    ${path}/brute < ${path}/input_file > ${path}/correctAnswer
    diff -Z ${path}/myAnswer ${path}/correctAnswer > /dev/null || break
    echo "Passed test: "  $i
    cat ${path}/input_file
done
echo "WA on the following test:"
cat ${path}/input_file
echo "Your answer is:"
cat ${path}/myAnswer
echo "Correct answer is:"
cat ${path}/correctAnswer