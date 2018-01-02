#!/bin/bash
echo ${HOME}
echo ${PWD}
echo ${USER}
echo ${UID}
echo ${SHELL}
#单引号的时候变量不会被拓展，将会原样输出
echo '${PATH}'
#双引号的时候变量将会被拓展
echo "${PATH}"