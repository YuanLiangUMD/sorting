#include "./object_t.hpp"
object_t::object_t(std::size_t num):id{num},comparison_counter{0}{
}

std::size_t 
object_t::comparison() const{
   return comparison_counter;
}

std::size_t 
object_t::ID() const {
   return id;
}

bool
object_t::operator<(const object_t& rhs){
   ++comparison_counter;
   return id < rhs.id;
}

bool 
object_t::operator==(const object_t& rhs){
   ++comparison_counter;
   return id == rhs.id;
}

bool 
object_t::operator>(const object_t& rhs){
   ++comparison_counter;
   return id > rhs.id;
}

std::ostream& operator<<(std::ostream& os, const object_t& rhs){
   os<<" object id:"<<rhs.id;
   return os;
}
