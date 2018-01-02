#!/bin/bash

#定义一个数组
array=(1 2 3 4 5 6)
#这些值会被存储在以0开始的索引上
#输出第一项
echo ${array[0]}

#更改第一项之后再次输出第一项
array[0]=100
echo ${array[0]}

#以列表的形式输出数组中的所有项
echo ${array[*]}

#或者
echo ${array[@]}

#输出列表的长度
echo ${#array[*]}