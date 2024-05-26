#! /bin/bash

i=0
while (($i<10))
do 
echo $i
((i++))
done

i=10
until (($i>10))
do 
echo $i
((i++))
echo $i
done

i=0
for i in  {1..10}
do 
echo $i
done

i=0
for ((i=0;$i<10;((i++))))
do 
echo $i
done
