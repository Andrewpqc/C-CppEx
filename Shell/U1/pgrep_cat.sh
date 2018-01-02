#!/bin/bash
a=`pgrep gedit`
#3923
cat /proc/${a}/environ | tr '\0' '\n'
#将环境变量的分割字符'\0'替换成'\n'