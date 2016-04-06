#if !defined OBJECT_T_HPP
#define OBJECT_T_HPP
#include<iostream>
class object_t{
   friend 
      std::ostream& operator<<(std::ostream& os,const object_t&);
   public:
   object_t(std::size_t id);
   object_t(object_t&&) =default;
   object_t(const object_t&) = default;
   object_t& 
      operator=(const object_t&) = default;
   object_t&
      operator=(object_t&&)=default;
   std::size_t comparison() const;
   std::size_t ID() const;
   bool operator<(const object_t&);
   bool operator>(const object_t &);
   bool operator==(const object_t & );

   private:
   std::size_t id,comparison_counter;
};
std::ostream& operator<<(std::ostream& os,const object_t&);
#endif
