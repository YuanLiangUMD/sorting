#include<iostream>
#include<cstddef>
#include<vector>
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
	 for (auto i = begin;i != (end+1); i++){
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
template<typename Container>
void quick_sort(Container& arr){
   quick_sort_helper(arr.begin(),arr.end()-1);
}
int main(){
   std::vector<int> v{10,5,4,7,2};
   quick_sort(v);
   std::cout<<"array is ";
      for(auto i:v)
	 std::cout<<i<<" ";
      std::cout<<"\n";
}
