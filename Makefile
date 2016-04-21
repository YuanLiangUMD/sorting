all:insertion_sort bubble_sort
	@echo "This project was written by Yuan Liang"
	@echo "Email: yliang12@terpmail.umd.edu"

insertion_sort:insertion_sort.cpp object_t.cpp
	g++ -std=c++14 -o3 object_t.cpp insertion_sort.cpp -o insertion_sort

bubble_sort:bubble_sort.cpp
	g++ -std=c++14 -o3 bubble_sort.cpp -o bubble_sort
.PHONY:clean
clean:
	-rm insertion_sort
	-rm bubble_sort
