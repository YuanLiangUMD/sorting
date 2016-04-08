#include<iostream>
#include<vector>
#include<numeric>
#include"./object_t.hpp"
#include"./quick_sort.hpp"
int main(){
   std::vector<object_t> v{80,30,40,70,10,20,60,50};
   quick_sort<>(v.begin(),v.end());
   for(auto& i: v)
     std::cout<<i<<" "; 
   auto total_comparisons = std::accumulate(v.cbegin(),v.cend(),0,
	 [](const auto& a,const auto& b) {return a+b.comparison();});
   std::cout<<"total comparisons is "<<total_comparisons<<std::endl;
}
