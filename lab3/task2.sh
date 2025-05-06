sentence=$*
count=$(echo "$sentence" | grep -i -o '[aeiou]' | wc -l )
echo "Vowel Count: $count"
