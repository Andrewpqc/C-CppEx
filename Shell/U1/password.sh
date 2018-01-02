#!/bin/bash
#不回显将用户的输入读到password变量中
echo -e "Enter password:"
stty -echo
read password
stty echo
echo
echo Password read.
echo ${password}