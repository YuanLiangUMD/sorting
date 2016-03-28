#include<iostream>
#include<vector>
#include<list>
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
      while (*cur < *pos  ){
	 --pos;
	 if (pos == begin)
	    break;
      }
      ++pos;
      for (auto i = cur; i != pos; --i){
	 auto tmp = i;
	 swap(*i,*--tmp);
      }

      auto tmp = begin;
      if (*begin > *++tmp)
	 swap(*begin,*tmp);
   }

}

int main(){
   std::list<int> v{1,5,3,9,6,7};

   insertion_sort(v.begin(),v.end());
   for (auto i:v)
      std::cout<<i<<" ";
}