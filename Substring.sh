S1=”this is a text”
S2=${s1:6:6}
echo $2
a=”good”
b=”bad”
if[$a=$b]
then
echo “a is equal to b”
else
echo “a is not equal to b”
fi
a=” ”
if[-z $a]
then
echo “string length is zero”
else
echo “string length is non zero”
fi
if[$a]
then
echo “string is not empty”
else 
echo “string is empty”
fi
if[-n $a]
then
echo “string is not zero”
else
echo “string length is zero”
fiif[$a!=$b]
then
echo “a is not equal to b”
else 
echo “a is equal to b”
fi
s=”sample string”
echo ${#s}
