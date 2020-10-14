/* Problem url: https://leetcode.com/problems/tenth-line
 * Code by: ldcduc
 * */
/* Begin of Solution */
# Read from the file file.txt and output the tenth line to stdout.
index=0
cat file.txt | while read line
do
    index=$index+1
    if [[ index -eq 10 ]]; then
        echo $line
        break
    fi
done
/* End of Solution */
/*
 * Comment by ldcduc
 * Suggested tags: bash script
 * 
 * */
