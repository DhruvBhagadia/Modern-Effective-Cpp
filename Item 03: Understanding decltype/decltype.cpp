/*
	decltype is used to find the type of a variable, it
	has it's major use-case in determining the return type of a
	method where input types keep on changing
*/
#include<typeinfo>
#include<iostream>

using namespace std;

/*
    auto: the returnType is yet to be deduced
    decltype: the returnType will be that of t+u
*/

template<typename T, typename U>
auto add(T t, U u) -> decltype(t+u){
    return (t+u);
}

int main() {
    
    int x = 27;
    float y = 4.3;
    auto ans = add(x, y);
    cout << "ans is: " << ans << " " << "and it's type is: " << typeid(ans).name();
    
    return 0;
}
