/*
    functions which expect null ptr as input forcefully convert 0 and NULL to nullptr,
    However this doesn't work well with templates because 0's type is deduced as int
    and that of NULL is long int.     
*/

#include<iostream>
#include<memory>
#include<mutex>

using namespace std;

class Dummy{
    
};

void f1(shared_ptr<Dummy> sptr){
    cout << "sptr" << endl;
}

void f2(unique_ptr<Dummy> uptr){
    cout << "uptr" << endl;
}

void f3(Dummy* ptr){
    cout << "ptr" << endl;
}

template<typename funcType, 
        typename mutexType,
        typename ptrType>
void lockAndCall(funcType f, mutexType& m, ptrType ptr){
    lock_guard<mutexType> g(m);
    f(ptr);
}

int main(){
    mutex m1, m2, m3;
    
    lock_guard<mutex> g1(m1);
    f1(0); //0 is interpreted grudgingly as NULL
    
    lock_guard<mutex> g2(m2);
    f2(NULL); //NULL interpreted as ptr
    
    lock_guard<mutex> g3(m3);
    f3(nullptr); //nullptr of the type pointer
    
    //To avoid repetition of code we write a template T which gives error for 0 and NULL
    
    //lockAndCall(f1, m1, 0); error: cannot convert int to shared_ptr 
    
    //lockAndCall(f2, m1, NULL); error: cannot convert long int to unique_ptr
    
    lockAndCall(f3, m1, nullptr); //works, nullptr of ptr type
    
    return 0;
}

/*
    output:
        sptr                                                                                                                                          
        uptr                                                                                                                                          
        ptr                                                                                                                                           
        ptr 
*/
