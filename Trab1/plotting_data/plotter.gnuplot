set title "Crescente"
set xlabel "Número de elementos (N)"
set ylabel "Segundos"

set terminal pngcairo size 800,600 enhanced font "Verdana,10"
set output 'crescente.png'

set xrange [25000:100000]

set style line 1 lc rgb '#0060ad' lt 1 lw 2 pt 7 ps 1.0   
set style line 2 lc rgb '#ad60ad' lt 1 lw 2 pt 7 ps 1.0  
set style line 3 lc rgb '#118811' lt 1 lw 2 pt 7 ps 1.0  
set style line 4 lc rgb '#ad0060' lt 1 lw 2 pt 7 ps 1.0 
set style line 5 lc rgb '#6060ad' lt 1 lw 2 pt 7 ps 1.0 
set style line 6 lc rgb '#80ad60' lt 1 lw 2 pt 7 ps 1.0 
set style line 7 lc rgb '#9960ad' lt 1 lw 2 pt 7 ps 1.0  
set style line 8 lc rgb '#ad90ad' lt 1 lw 2 pt 7 ps 1.0 

plot 'crescente.dat' using 1:2 with linespoints ls 1 title 'Merge', \
	 ''				 using 1:3 with linespoints ls 2 title 'QuickMid', \
	 ''				 using 1:4 with linespoints ls 3 title 'QuickFirst', \
	 ''				 using 1:5 with linespoints ls 4 title 'Heap', \
	 ''				 using 1:6 with linespoints ls 5 title 'Count', \
#	 ''				 using 1:7 with linespoints ls 6 title 'Bubble', \
	 ''				 using 1:8 with linespoints ls 7 title 'Bucket', \
	 ''				 using 1:9 with linespoints ls 8 title 'Insert'
