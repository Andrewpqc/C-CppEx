#!/bin/bash
#关联数组
declare  -A ass_array
ass_array=([hhh]=aaa [jjj]=bbb)
echo ${ass_array[hhh]}

#以列表的形式列出数组的值
echo ${ass_array[*]}
echo ${ass_array[@]}
#以列表的形式列出数组的键
echo ${!ass_array[*]}
echo ${!ass_array[@]}

ass_array[kkk]=mmm

echo ${#ass_array[@]}