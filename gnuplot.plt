reset

set xlabel "λ"
set y2label "呼損率"
set ylabel "スループット[Mbps]"

set datafile separator ","
#set y2range [0:1]
set y2tics
set logscale y2 10
set yrange [0:100]

set terminal png font "MigMix 2M"
#set terminal png font "游明朝"

# 1000
target=ARG1
set title "発生源数 ".target
datafile = "data/".target.".csv"
pngfile = "graph/".target.".png"
set output pngfile

plot datafile using 1:2 axis x1y2 with line lt 1 title "呼損率",\
     datafile using 1:($3/1000000) axis x1y1 with line lt 2 title "スループット"

replot