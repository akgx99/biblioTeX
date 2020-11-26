#!/bin/sh

gnuplot -p << EOF
set xlabel "xlabel"
set ylabel "ylabel"
set title "graphTitle"
plot "stats.dat" with lines
EOF

