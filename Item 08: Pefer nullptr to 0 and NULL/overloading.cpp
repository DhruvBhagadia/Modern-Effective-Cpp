/*
    0 and NULL are deduced to integral type and are not pointers, NULL can be 
    deduced to 0L (long) hence can lead to undesirable outputs when function accepts
    a pointer. nullptr is of ptr type and hence should be preferred over NULL and 0
*/

#include<iostream>

using namespace std;

void f(int){
    cout << "int" << endl;
}

void f(bool){
    cout << "bool" << endl;
}

void f(void*){ //void* is a ptr that can point to any data_type and can be type casted to any
    cout << "ptr" << endl;
}

int main(){
    
    f(0); //op: int
    
    // f(NULL); //error: call of overloaded ‘f(NULL)’ is ambiguous
    
    f(nullptr); //op: ptr
	
	return 0;
}
