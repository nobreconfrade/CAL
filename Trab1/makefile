all:
	g++ megalovania.cpp quicksort.cpp bucketsort.cpp countingsort.cpp bubblesort.cpp insertsort.cpp mergesort.cpp heapsort.cpp vector_fill_utils.cpp timer.cpp -std=c++11 -o trabalho1.exe

test:
	g++ main_tests.cpp quicksort.cpp bucketsort.cpp countingsort.cpp bubblesort.cpp insertsort.cpp mergesort.cpp heapsort.cpp vector_fill_utils.cpp timer.cpp -std=c++11 -o trabalho1.exe

testnobubble:
	g++ main_tests_nobubble.cpp quicksort.cpp bucketsort.cpp countingsort.cpp bubblesort.cpp insertsort.cpp mergesort.cpp heapsort.cpp vector_fill_utils.cpp timer.cpp -std=c++11 -o trabalho1_NO_BUBBLE.exe

testonlybucket:
	g++ main_tests_onlybucket.cpp bucketsort.cpp vector_fill_utils.cpp timer.cpp -std=c++11 -o trabalho1_ONLY_BUCKET.exe

debug:
	g++ -g main_tests.cpp quicksort.cpp bucketsort.cpp countingsort.cpp bubblesort.cpp insertsort.cpp mergesort.cpp heapsort.cpp vector_fill_utils.cpp timer.cpp -std=c++11 -o trabalho1.exe
