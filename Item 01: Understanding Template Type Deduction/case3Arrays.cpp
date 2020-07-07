/*
    Case 3: paramType is a pass by value and Array is passed

    Arrays and pointers are different types in c++, however there's this array to pointer 
    decay rule where if try and assign array type variable to pointer type, the array gets
    decayed to pointer to the first element(see the code for an example)   

    Template of the form: 
    template<typename T>
    void f(paramType param){}
*/

#include <typeinfo>
#include <iostream>

using namespace std;

template<typename T>
void f(T param){
    cout << typeid(param).name() << endl;
}

template<typename T>
void k(T& param){
    cout << typeid(param).name() << endl;
}

int main() {
    char name[] = "Dhruv";
    const char const_name[] = "Dhruv";

    //Array to pointer decay rule applies to 3 below scenarios

    const char* const ptr = const_name; // array gets converted to pointer to first element
    
    f(name); //paramType is pointer to a char
    f(const_name); //paramType is pointer to a const char
    
    //Inorder for pramaType to be an array, T& can be used
    
    k(name);//T is char[13] and paramType is char (&)[13]
    return 0;
}

/*
Output: 
Pc
PKc
A6_c
*/
