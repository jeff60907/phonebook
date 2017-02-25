reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:0.150]'output.txt'\
    using 2:xtic(1) with histogram title 'original',        \
''  using 3:xtic(1) with histogram title 'optimized',       \
''  using 4:xtic(1) with histogram title 'BKDRHash',   \
''  using ($0-0.2):($2+0.008):2 with labels title ' ',      \
''  using ($0+0.1):($3+0.006):3 with labels title ' ',      \
''  using ($0+0.4):($4+0.004):4 with labels title ' ',      

