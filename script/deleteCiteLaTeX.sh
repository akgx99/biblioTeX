#!/bin/bash

sed -e '/'$1'/d' $2 > data/temp.txt
cat data/temp.txt > $2
rm data/temp.txt 
