/*
    declaring a function private or deleted both serve as not allowing someone from calling
    or using the function, however deleted functions should be preferred over private undefined
    ones because: 
    
    1. Even the member functions or friend functions cannot access deleted functions
        which in case of private undefined functions cannot be revealed until link type
        (more on friend functions: https://www.programiz.com/cpp-programming/friend-function-class#:~:text=When%20a%20class%20is%20made,protected%20data%20of%20class%20A.)
    2. Prevent unwanted overloads
    3. Prevent use of template Instantiation that must be disabled
*/

#include<iostream>

using namespace std;

// Prevent unwanted overloads

bool isLucky(int a){
    return (a >= 0)? true: false;
}

//Declaring unwanted overloads deleted solves the problem

bool isLucky(bool a) = delete;
        
bool isLucky(char a) = delete;

/*
however since we are not inside any class using private gives error

private:
    bool isLucky(bool a);
            
    bool isLucky(char a); 

error: expected unqualified-id before ‘private’
*/

int main(){
    
    /*
        cout << isLucky(true) << endl; err:  use of deleted function ‘bool isLucky(bool)’
        cout << isLucky('a') << endl; err:  use of deleted function ‘bool isLucky(char)’
	*/
	
	cout << isLucky(10) << endl; //op: true
	
	return 0;
}
