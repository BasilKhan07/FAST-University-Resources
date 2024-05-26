#! /bin/bash


echo $1 $2 $3
args=("$@")
echo ${args[0]} ${args[1]} ${args[2]}

echo "Hello From Ali Fatmi"
echo Which $BASH
echo $BASH
echo $PWD
echo $HOME


read name 
echo 'your name is '  $name

read name1 name2 name3
echo $name1 $name2 $name3

read -a array
echo ${array[0]} ${array[1]} ${array[2]}
read -p "please input your First Number" var1
read -p "Please input your second Number " var2
read -p "Please input your second Number " var3
read -p "Please input your second Number " var4
read -p "Please input your second Number " var5



sum=$(($var1 + $var2 + $var3 + $var4 + $var5))
echo $sum
