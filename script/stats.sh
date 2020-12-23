#!/bin/bash

i=0
j=0
k=0
l=""
title=""
xlabel=""
if [[ $2 = 'annee' ]]
title="Éléments par année"
xlabel="Année"
count=""
then
rm script/st.dat
while read line  #Lecture des lignes des documents
	do   
	   if [[ $line =  *year* ]] #Si la ligne contient la chaîne passée en paramètres
	   then
	l=$line
	l= echo $l | cut -c8- | sed "s/.$//" >> script/st.dat
	    fi
done < $1
while read line 
do
	count=`grep -c $line script/st.dat`
	echo $count " $line" >> script/sta.dat
done < "script/st.dat"
cat script/sta.dat | sort | uniq > script/st.dat
rm script/sta.dat
fi

if [[ $2 = 'total' ]]
then
title=total
xlabel="Type de document"
	while read line  #Lecture des lignes des documents
	do   
	   if [[ $line =  *@* ]] #Si la ligne contient la chaîne passée en paramètres
	   then
		  i=$(($i + 1))
	    fi
	   if [[ $line =  *@book* ]] #Si la ligne contient la chaîne passée en paramètres
	   then
		  j=$(($j + 1))
	    fi
	   if [[ $line =  *@misc* ]] #Si la ligne contient la chaîne passée en paramètres
	   then
		  k=$(($k + 1))
	    fi
	done < $1
echo $i  " éléments" > script/st.dat
echo $j  " book" >> script/st.dat
echo $k  " misc" >> script/st.dat
fi


gnuplot -p << EOF


set title "$title"
set style data histogram
set xlabel "$xlabel"
set style fill transparent solid 0.5
set ylabel "Quantité"
set yrange [0:9]
plot 'script/st.dat' using 1:xtic(2)
EOF
