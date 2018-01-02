#!/bin/bash
#Shell中的三种循环
for i in {A..Z}
    do
    echo $i
done

count=0
while true
    do
    echo $count
    let count++
    if [ $count -eq 10 ] 
    then
        break
    fi
done

count2=0
until [ $count2 -gt 10 ]
    do
    let count2++
    echo $count2
done