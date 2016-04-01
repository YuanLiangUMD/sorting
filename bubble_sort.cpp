#include<iostream>
#include<vector>
#include<algorithm>
namespace{
auto swap = [](auto& a,auto&b){
      auto tmp = std::move(a);
      a = std::move(b);
      b = std::move(tmp);
  };

}

template<typename bidirection_iterator>
void bubble_sort(bidirection_iterator begin,
                 bidirection_iterator end){
   --end;
  for( auto i = end; i != begin;i--)
     for( auto j = begin; j != end; j++){
	auto tmp = j;
	if (*j > *(++tmp))
	   swap(*j,*tmp);
	}
}
int main(){
   std::vector<int> v;
   v.reserve(100);
   for(auto i = 0; i != 100;i++)
      v.push_back(i);

   random_shuffle(v.begin(),v.end());
   bubble_sort(v.begin(),v.end());
   for(auto i:v)
      std::cout<<i<<" ";

}
