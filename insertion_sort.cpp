#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
namespace{
   auto swap = [](auto& a,auto& b){
      auto tmp = std::move(a);
      a = std::move(b);
      b = std::move(tmp);
   };
}
template<typename bidirectional_iterator>
void insertion_sort(bidirectional_iterator begin,
      bidirectional_iterator end){
   auto cur = begin;
   for (++cur; cur != end; ++cur){
      auto pos = cur;
      --pos;
      while (*cur < *pos && pos != begin  ){
	 --pos;
      }
      ++pos;
      auto tmp = cur;
      std::rotate(pos,cur,++tmp);
      if (begin == --pos && *begin > *++pos)
	 swap(*begin,*pos);  
   }
}

int main(){
   std::vector<int> v;
   for (auto i = 0; i < 100;i++)
      v.push_back(i);
   random_shuffle(v.begin(),v.end());
   std::cout<<"before sorting\n";
   for (auto i:v)
      std::cout<<i<<" ";
   std::cout<<"\n";
   insertion_sort(v.rbegin(),v.rend());
   for (auto i:v)
      std::cout<<i<<" ";
}
