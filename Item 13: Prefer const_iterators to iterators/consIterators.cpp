/*
    const_iterators are stl equivalent of iterators to const, hence if the content 
    need not be changed const_iterators should be preferred over iterators 
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
    When one needs to write maximal generic code in C++11, there might be no
    implementation of non-member functions cbegin() and cend(). In such scenario
    one needs to write its own implementation
*/

template<class C>
auto cbegin(const C& container) -> decltype(begin(container)){ 
    //since we have reference to a const container the return_value is const_iterator(cbegin)
    return begin(container);
}


int main(){
    
    vector<int> values{10, 12, 15};
    
    // cbegin and cend produce const_iterators even if the container is non_const
    auto it = find(values.cbegin(), values.cend(), 10);
    
    values.insert(it, 9);
    
    for(auto i: values)
        cout << i << " ";
	
	return 0;
}
