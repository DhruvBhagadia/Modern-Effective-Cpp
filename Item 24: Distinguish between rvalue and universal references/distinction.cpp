/*
	Both rvalue and universal references are referred to as T&&
	In cases where type-deduction of a parameter is involved T&& is universal reference else it is rvalue reference
*/

void func(int&& a){} //a is rvalue reference

template<typename T>
void f1(vector<T>&& param) //param is rvalue reference

template<typename T>
void f2(T&& param) //param is universal reference

int main() {

    int&& a = someMethod(); //a is rvalue reference
    auto&& var = someMethod(); //type of var has to be deduced and hence universal reference

    return 0;
}