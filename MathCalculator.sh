echo "1.Addition 2.Subtraction 3.Multiplication 4.Division"
read n
echo "Enter the operends"
read a
read b
case $n in
"1") echo "$a +$b =`expr $a \ + $b`";
"2") echo "$a-$b=`expr $a \ - $b`";
"3") echo "$a*$b=`expr $a \ * $b`";
"4") echo "$a/$b=`expr $a \ / $b`";
