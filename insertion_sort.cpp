///still needs improve 4/1/2016
#include"./object_t.hpp"
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<numeric>
template<typename bidirectional_iterator>
void insertion_sort(bidirectional_iterator begin,
      bidirectional_iterator end){
   auto cur = begin;
   for (++cur; cur != end; ++cur){
      auto pos = cur;
      do{
	 --pos;
	 if (*cur > *pos){
          ++pos;
	  break;
	 }
      } while (pos != begin);

      auto tmp_val = std::move(*cur);
      auto tmp = cur;
      std::move_backward(pos,cur,++tmp);
      *pos = std::move(tmp_val);
   }
}

int main(){
   std::vector<object_t> v;
   const auto total_elements = 10000;

   v.reserve(total_elements);
   for (auto i = 0; i < total_elements;i++)
      v.emplace_back(i);
   random_shuffle(v.begin(),v.end());

   std::cout<<"before sorting ID \n";
   for (auto& i:v)
      std::cout<<i.ID()<<" ";
   std::cout<<"\n";
   std::cout<<"after sorting ID\n";
   insertion_sort(v.begin(),v.end());
   for (auto& i:v)
      std::cout<<i.ID()<<" ";
   std::cout<<"\n";
   std::cout<<"total elements is "<<total_elements<<" \n";
   std::cout<<"total comparison is ";

   auto total_comparisons = 
      std::accumulate(v.cbegin(),v.cend(),0,
	 [](const auto& a,const auto& b){
              return (a + b.comparison()); 
	      });

   std::cout<<total_comparisons<<" comaprisons\n";
}
