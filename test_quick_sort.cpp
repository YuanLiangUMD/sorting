#include<iostream>
#include<vector>
#include<numeric>
#include"./object_t.hpp"
#include"./quick_sort.hpp"
int main(){
   std::vector<object_t> v;
   v.reserve(1000);
   for(auto i = 0; i != 100; i++)
      v.emplace_back(i);

   std::random_shuffle(v.begin(),v.end());
   quick_sort<>(v.begin(),v.end());
   for(auto& i: v)
     std::cout<<i.ID()<<" "; 
   auto total_comparisons = std::accumulate(v.cbegin(),v.cend(),0,
	 [](const auto& a,const auto& b) {return a+b.comparison();});
   std::cout<<"total comparisons is "<<total_comparisons<<std::endl;
}
