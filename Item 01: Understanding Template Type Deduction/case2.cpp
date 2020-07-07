/*
    Case 2: paramType is a universal reference

    Rule Depends on whether param is lvalue or rvalue. 

    1. param is lvalue: 
        a. Both T and paramType are lvalue references (only case in which T is a reference)
    2. param is rvalue:
        Normal Case 1 rules apply 

    Template of the form: 
    template<typename T>
    void f(paramType param){}
*/

template<typename T>
void f(T&& param){}

int main() {
    int x = 27;
    const int cx = x;
    const int& rx = x;
    
    f(x); //T and paramType are int&
    f(cx); //T and paranType are both const int&
    f(rx); //T and paranType are both const int&
    f(27); //27 is rvalue, T is int and paramType is int&&

    return 0;
}
