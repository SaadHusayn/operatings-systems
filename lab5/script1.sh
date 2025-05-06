if [ $# -ne 1 ]; then
	echo "Usage: $0 <filename>"
	exit 1
fi
filename="$1"

if [ ! -f $filename ]; then
	echo "Invalid filename"
	exit 1
fi

numlines="$(cat $filename | wc -l)"
echo $numlines
