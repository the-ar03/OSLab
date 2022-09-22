for i in vishnu
do 
echo “before conversion is”
echo $i;
j=`echo $i|tr’[a-z]’’[A-Z]’`
echo “after conversion is”
echo $j;
done
