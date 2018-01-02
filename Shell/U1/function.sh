#!/bin/bash
#定义函数
function first_func()
{
    echo "$@"
    return 0
}

#调用函数
first_func 1 2 3

#打印上一条命令的返回值
echo $?