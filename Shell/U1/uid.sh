#!/bin/bash
#检查执行该脚本的用户是root还是非root
if [ ${UID} -ne 0 ];then
    echo "you are not root\!"
else
    echo "you are root\!"
fi