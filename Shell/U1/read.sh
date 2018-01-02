#!/bin/bash
#不需要回车键从stdin读取五个字符，并且存入var中
read -n 5 var
echo
echo $var

echo "-----------"
#无回显读取用户输入，存入变量password
read -s password
echo
echo $password

echo "-----------"

#显示提示信息
read -s -p "Enter password:" var2
echo 
echo $var2

echo "-----------"
#限定时限读取
read -t 2 var3
echo 
echo $var3
