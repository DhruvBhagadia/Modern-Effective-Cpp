/*
	{} initialization is called uniform c++ initialization, however has following issues

	1. Constructor overloading as initializer_list hijacks other constructors
	2. While using auto the variable type is deduced to be initializer_list 
*/

#include<iostream>

using namespace std;

class A{
    private:
        int a;
        double b;
        bool c;
    
    public:
        A(int i, double d){
            a = i; b = d;
            cout << "int, double" << endl;    
        }
        
        A(int i, bool b){
            a = i; c = b;
            cout << "int, bool" << endl;
        }
        
        /*
            Copy constructor definition
            A(A& ob){
                cout << "copy constructor called" << endl;
            }  
        */
        
        // initializer_list hijacks all constructors when object is initialized with {}
        A(initializer_list<long double> l){
            cout << "initializer_list" << endl;
        }
};

int main() {

    double x=1.2, y=1.2, z=1.2;
    
    // int z{x+y+z}; error, no implicit type conversion from double to int
    
    int u(x+y+z); //op: 3, implicit type conversion
    int v = x+y+z; //op: 3, same
    
    /*
        Scenarios where initializer_list hijacks constructors 
    */
    
    A ob1(1, 1.2); //int, double
    
    A ob2{1, 1.2}; //initializer_list hijacks constructor int, double
    
    A ob3(1, true); //int, bool
    
    A ob4{1, true}; //initializer_list hijacks constructor int, bool
    
    A ob5(ob1); //default copy constructor called
    
    A ob6{ob2}; //initializer_list hijacks copy constructor
    
    /*
        Above copy constructor's scenario can be avoided by defining user-defined copy constructor
        By uncommenting copy constructor even braced initialization calls copy constructor
    */
    
    //Hijacking scenario is most common in vectors

    vector<int> v1(10, 0) //constructor with non initializer_list, 
    					  //creates a vector of size 10 and sets 0 as their value

    vector<int> v2{10, 0} //initializer_list constructor hijacks other constructors
    					  //creates a vector with two elements 10 and 0
    
    return 0;
}