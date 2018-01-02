#!/bin/bash
#每10秒钟执行一次传入的命令，直到该命令执行成功
function repeat()
{
    while :
        do
        $@  && return 0
        sleep 10
    done
}

repeat wget -c https://pypi.python.org/packages/07/0f/c5b7d1f4dd9b720e23f6cf7be5c411dea0f33ec4d13a5996978445d05059/colorqrxy-0.0.1.tar.gz#md5=d90223435336f73b8527c13a3dcef98d