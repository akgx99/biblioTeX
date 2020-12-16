#!/bin/bash
cd out/
pdflatex start.tex
bibtex start
pdflatex start.tex
pdflatex start.tex