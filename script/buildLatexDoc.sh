#!/bin/bash
cd out/
pdflatex start.tex
bibtex start
pdflatex start.tex
pdflatex start.tex

sh ../script/clean.sh

echo "*** Export successfully completed ***"
echo "Your document can be found in : out/"