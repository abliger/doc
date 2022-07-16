str="0"
for ii in `seq 1 1000`
do 
str="$str,$(($RANDOM - 10000))" 
done
echo $str