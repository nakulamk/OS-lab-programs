#!/bin/bash

echo "Enter the string"
read str

length=${#str}

for((i=$length-1;i>=0;i--))
do
    REV=$REV${str:$i:1}
done
echo "the reverse of the string using looping is:"
echo $REV
if [ $str == $REV ]
then
    echo "$str is a palindrome"
else
    echo "$str is not a palindrome"
fi
