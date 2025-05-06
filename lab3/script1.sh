#read -p "Enter alue: " val
#echo $1 $2 $3 #comman line arguments

read -p "Enter var1: " var1
read -p "Enter var2: " var2
#var3=$((var1 * var2))
echo $((var1 * var2))
#((var1=var1 * var2))
#((var1++))
#echo $var1
#without $ assignment operator, with $ we are returning the calculation to echo
#or to a new variable

if [ $var1 -eq $var2 ];
then
	echo "Equal"
elif [ $var1 -gt $var2 ];
then
	echo "Greater"
else
	echo "Lesser"
fi


