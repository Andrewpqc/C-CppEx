#!/bin/bash
#将多行文本变单行或指定的行

#实现方式:将换行符变为空格
cat example.txt |xargs

#指定每行的个数
cat example.txt |xargs -n 2

#用于将流转化为命令行参数