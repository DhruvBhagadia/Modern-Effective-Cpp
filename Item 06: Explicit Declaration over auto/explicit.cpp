/*
	Auto doesn't work well with invisible proxy classes. 

	Proxy classes are classes which are used to imitate some behavior,
	for example operator[] on a vector<bool> doesn't return a bool& but a proxy class
	called vector<bool>::reference which tries to imitate what bool& would do. 
	The reason of using this proxy class in this case is c++ forbids references to bits.  

*/
#include<iostream>
#include<boost/type_index.hpp>
#include<vector>

using namespace std;

vector<bool> features(){
	vector<bool> ans(5, false);
	return ans;
}

int main(){
	using boost::typeindex::type_id_with_cvr;
	bool prority = features()[4]; //vector<bool>::reference is implicitly converted to bool
	cout << type_id_with_cvr<decltype(prority)>().pretty_name() << endl;
	/*
		No implicit conversion and type of apriority is vector<bool>::reference
		and now the behavior of program depends on proxy class's internal implementation
		Without any proper implementation, apriority would be a dangling pointer
	*/

	auto aprority = features()[4];
	cout << type_id_with_cvr<decltype(aprority)>().pretty_name() << endl;

	/*
		If you know that proxy classes are being used then instead of not using auto 
		one can use explicit type conversions 
	*/

	auto bpriority = static_cast<bool>(features()[4]);
	cout << type_id_with_cvr<decltype(bpriority)>().pretty_name() << endl;

	return 0;
}

/*
	Output:
	bool
	std::_Bit_reference
	bool
*/