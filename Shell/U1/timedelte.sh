#!/bin/bash
#统计六个echo所花费的纳秒数
start=$(date +%N)
echo "hello,world"
echo "hello,world"
echo "hello,world"
echo "hello,world"
echo "hello,world"
echo "hello,world"
end=$(date +%N)
let diff=end-start
echo "${diff} Nseconds costs\!"