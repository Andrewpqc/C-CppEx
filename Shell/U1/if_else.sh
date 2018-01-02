#!/bin/bash
a=1
if [ $a -lt 1 ]; then
    echo "smaller than 1"
else if [ $a -eq 1 ]; then
    echo "equal to 1"
else
    echo "bigger than 1"
fi