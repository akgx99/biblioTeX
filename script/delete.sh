#!/bin/bash
FICHLISTE=$1
i=0
j=0
k=0
trouve=1
while read line  
do   
      i=$(($i + 1))
   if [[ $line =  *${2}* ]]
   then
        j=$i
        trouve=0
    fi
    if [[ $line =  "}" ]] && [ $trouve = 0 ]
        then
        k=$i
        trouve=1
    fi
done < $1

sed ${j},${k}'d' $1
echo $j
echo $k
echo $trouve
