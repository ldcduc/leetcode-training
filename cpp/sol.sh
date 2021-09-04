FILE=./$1
if [ -f "$FILE" ]; then
    echo "$1 exists."
else
    echo "/* Problem url: https://leetcode.com/problems/$1" | sed 's/.cpp//' >  $1
    cat format >> $1
    echo "$1 is created!"
    vim ./$1
fi
