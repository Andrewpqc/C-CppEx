#!/bin/bash
#列出某一目录及其子孙目录的所有文件及文件夹
#find base_path

#当前目录及其子目录下的所有文件以及文件夹
find $PWD
echo "--------"
find $PWD -print
echo "--------"

#ianme忽略大小写，name严格按照大小写
find $PWD -name "*.sh" -print
echo "--------"
find $PWD -iname "*.SH" -print

#否定参数
echo "--------"
find $PWD ! -name "*.sh" -print

#基于目录深度
echo "--------"
#该命令就是只允许在当前目录中查找
find $PWD -maxdepth 1 -name "*.sh" -print
#该命令就是跳过当前目录，在下一级目录中开始查找
find $PWD -mindepth 1 -name "*.sh" -print

#基于文件类型搜索
echo "--------"
find $PWD -type f -name "*.sh" -print

#基于时间搜索

#基于文件大小搜索

#基于用户的搜索

#基于权限的搜索

#find命令的exec选项