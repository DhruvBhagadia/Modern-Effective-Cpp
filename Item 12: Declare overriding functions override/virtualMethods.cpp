/*
    "virtual" keyword is a way of letting the compiler know that late binding/overriding
    (runtime polymorphism) is to be achieved (by default early binding is done)
*/

#include<iostream>

using namespace std;

class Base{
    public:
        virtual void vmethod(){
            cout << "virtual base" << endl;
        } 
        
        void method(){
            cout << "non-virtual base" << endl;
        }
};

class Derived: public Base{
    public:
        void vmethod(){
            cout << "virtual Derived" << endl;
        }
        
        void method(){
            cout << "non-virtual Derived" << endl; 
        }
};

int main(){
    
    Derived d;
    Base* b = &d; //b of type pointer to base but holds reference of d
    
    /*
        late binding: the content of the variable decides which method will be binded
        Here b is a reference to derived. vmethod being a virtual function tells compiler
        that it can be overriden and the call to be processed at runtime, here derived
        overrides base's virtual method. 
    */
    
    b -> vmethod(); //op: virtual Derived
    
    /*
        early binding: the data_type of b decides which method to be called, 
        here since b is of type Base* base's non-virtual method is called
    */
    
    b -> method(); //op: non-virtual base
	
	return 0;
}
