#!/bin/bash

while read line  #Lecture des lignes des documents
do   
   if [[ $line =  *@* ]] #Si la ligne contient la chaîne passée en paramètres
   then
          i=$(($i + 1))
    fi
done < $1
echo $i " éléments" > script/st.dat

gnuplot -p << EOF

plot 'script/stats.dat' with linespoints ls 1
set title "éléments"
set style data histogram
set xlabel "xlabel"
set ylabel "ylabel"
set xr [$xmin:$xmax]
set yr [$ymin:$ymax]
set xtic auto
set ytic auto
set nokey
set output 'curve.png'
EOF

