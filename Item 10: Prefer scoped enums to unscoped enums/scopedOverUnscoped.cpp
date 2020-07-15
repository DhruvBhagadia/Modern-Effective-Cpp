/*
    unscoped enums are default c++98 enums where the elements of enum have a scope 
    same as that of the enum hence the name unscoped.
    
    Reasons to prefer scoped enums over unscoped
    1. avoid namespace pollution 
    2. prevent implicit conversion of enumerators for unscoped enums to int
    3. by default scoped enums can be forward declared, however for unscoped enums
    underlying type needs to be declared to allow forward declaration. 
    
*/

#include<iostream>

using namespace std;

int main(){
    
    enum rgb{red, green, blue}; //unscoped enum
    //auto red = 0; //err: red redeclared
	
	enum class color{white, black, blue}; //scoped enum
	auto black = 0; //compiles, no namespace pollution
	
	rgb unscoped_color = blue;
	if(unscoped_color > 0)
	    cout << unscoped_color << endl; //op: int
	
	color scoped_color = color::white;
	
	/*
	error: cannot compare color with int
	if(scoped_color > 0) 
	    cout << scoped_color << endl;
    */
    
    cout << static_cast<int>(scoped_color) << endl; //explicit type conversion
	
	//forward declaration
	
	enum class Person; // compiles, underlying type int
	
	enum Person2: size_t; //unscoped can be forward declared if underlying type is predefined
	
	return 0;
}
