/*
    typedefs and alias are used to name a particular type, generally used to rename
    types which are inconvinient to write again and again. However, using typedefs
    with template programming is not possible and hence alias declarations should be preferred
*/

#include<iostream>
#include<memory>
#include<list>

using namespace std;

template<typename T>
class MyAlloc: public allocator<T> {}; // custom memory allocation class inherits std::allocator

class Dummy{
    
};

//Alias declaration
template<typename T>
using MyAllocList = list<T, MyAlloc<T>>; //MyAlloc<T> specifies list to use our custom allocator, default is std::allocator

//Typedef declaration
template<typename T>
struct MyAllocList2{
    typedef list<T, MyAlloc<T>> type;
};

/*
    To use MyAllocList inside template
    
    1. alais declaration: compiler comes to know that MyAllocList is a alais template
    meaning it has to be referring to type of a variable hence "typename" is not required
    
    2. typedef declaration: compiler when sees MyAllocList2<T>::type doesn't know whether
    it is referring to type or a variable whose name is type, since here it is referring to 
    a type which depends on T, it needs to be preceeded with "typename"
*/

template<typename T>
class Widget{
    MyAllocList<T> list;
    typename MyAllocList2<T>::type list2;
};


int main(){

    MyAllocList<Dummy> ld; //using alais
	
	MyAllocList2<Dummy>::type ld2; //using typedef
	
	return 0;
}
