#read -p "Enter answer in Y or N: " ans

#case $ans in "Y"|"y")
#echo "Your ans is yes";;
#"N"|"n")
#echo "Your ans is no";;
#esac

func(){
#i=0
#while [ $i -lt 10 ]
read -p "Enter n: " n
for ((i=1;i<=n;i++))
do
for ((j=1;j<=i;j++))
do
echo -n $i
done
echo -e
done

echo $1
}


func $1
