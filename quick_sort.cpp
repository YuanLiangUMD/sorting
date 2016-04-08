#include "./quick_sort.hpp"
namespace {
   auto swap = [](auto& x,auto& y){ 
      auto tmp = std::move(x);
      x = std::move(y); 
      y = std::move(tmp);
   };
   template <typename random_iterator>
      auto partition(random_iterator begin, random_iterator end){
	 auto pivot = end;
	 auto r = begin;
	 for (auto i = begin;i < end; i++){
	    if (*i < *pivot ){
	       swap(*i,*r);
	       r++;
	    }
	 }
	 swap(*pivot,*r);
	 return r;
      }
   template<typename random_iterator>
      void quick_sort_helper(random_iterator begin,random_iterator end){
	 if (end > begin){
	    auto p = partition(begin,end);
	    quick_sort_helper(begin, --p);
	    quick_sort_helper(++p, end);
	 };    
      }

}
 template<typename randomIt>
void quick_sort(randomIt begin,randomIt end){
   quick_sort_helper(begin ,end -1);
}
