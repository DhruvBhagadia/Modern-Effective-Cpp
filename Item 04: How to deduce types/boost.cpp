/*
	There are different ways to get the deduced type of a variable, some of which are
	1. IDEs: once compiled, IDEs show deduced types
	2. Compilers: errors help in knowing deduced type
	3. typeid(param).name(): o/p like i, d, f which is quite confusing
	4. boost library
*/


#include<iostream>
#include<boost/type_index.hpp>
using namespace std;

template<typename T>
void f(const T& param){

	using boost::typeindex::type_id_with_cvr;
	
	cout << type_id_with_cvr<T>().pretty_name() << endl;
	cout << type_id_with_cvr<decltype(param)>().pretty_name() << endl;
}

int main(){
	f(27);

	return 0;
}

/*
Output: 
int
int const&
*/
