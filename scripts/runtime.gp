reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:0.200]'output.txt'\
    using 2:xtic(1) with histogram title 'original',        \
''  using 3:xtic(1) with histogram title 'optimized',       \
''  using 4:xtic(1) with histogram title 'BKDRHash',   \
''  using 5:xtic(1) with histogram title 'Trie',   \
''  using ($0):(0.100):2 with labels title ' ' textcolor lt 1,      \
''  using ($0):(0.110):3 with labels title ' ' textcolor lt 2,      \
''  using ($0):(0.120):4 with labels title ' ' textcolor lt 3,      \
''  using ($0):(0.130):5 with labels title ' ' textcolor lt 4,   
