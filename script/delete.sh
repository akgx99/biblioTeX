#!/bin/bash
FICHLISTE=$1
i=0 #Compteur de lignes
j=0
k=0
trouve=1 #Vérification si on a déjà trouvé l'élément
while read line  #Lecture des lignes des documents
do   
      i=$(($i + 1))
   if [[ $line =  *${2}* ]] #Si la ligne contient la chaîne passée en paramètres
   then
        j=$i
         trouve=0
    fi
    if [[ $line =  "}" ]] && [ $trouve = 0 ] #si on a trouvé le document et que la ligne contient seulement "}"
        then
        k=$i
        trouve=1
    fi
done < $1

sed ${j},${k}'d' $1 > temp.bib #Suppression des lignes à partir de l'élément trouvé jusqu'à la prochaine accolade dans un fichier temporaire
cat temp.bib > $1 
rm temp.bib 
