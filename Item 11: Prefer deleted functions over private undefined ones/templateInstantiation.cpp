/*
    Preventing use of template Instantiation is not possible using private because
    template specifications need to be written at namespace scope and hence gives 
    Error
*/

#include<iostream>

using namespace std;

//template Instantiation

class PrivateUnDefined{
    public:
        template<typename T>
        void processPtr(T* ptr);
    
    /* ERROR
    private:
        template<>
        void processPtr<void>(void* ptr)
    */
};

class deleted{
    public:
        template<typename T>
        void processPtr(T* ptr){
            cout << "here";
        };
};

template<>
void deleted::processPtr<void>(void* ptr) = delete; //works! specialization at namespace level

int main(){

    int i;
    void* v = &i;
    deleted d;
    
    d.processPtr(&i); //op: here
    
    //d.processPtr(v); //err: use of deleted function
    
    return 0;
}