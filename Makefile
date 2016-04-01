all:insertion_sort quick_sort

insertion_sort:insertion_sort.cpp
	g++ -std=c++14 -o3 insertion_sort.cpp -o insertion_sort

quick_sort:quick_sort.cpp
	g++ -std=c++14 -o3 quick_sort.cpp -o quick_sort

.PHONY:clean
clean:
	-rm quick_sort
	-rm insertion_sort
