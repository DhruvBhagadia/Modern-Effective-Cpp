/*
	Case 1: paramType is a reference but not universal reference

    Template of the form: 
    template<typename T>
    void f(paramType param){}
*/

template<typename T>
void f1(T& param){}

template<typename T>
void f2(const T& param){}

template<typename T>
void f3(T* param){}

int main() {
    int x = 27;
    const int cx = x;
    const int& rx = x;
    const int* px = &x;
    
    //f1: referenceness of variables is ignored because paramType is already a reference
    
    f1(x); //paramType is int&
    f1(cx); //paramType in const int&
    f1(rx); //paramType is const int&

    //for f2 with reference wven the constness of variables will be ignored because paramType already includes const and &
    
    f2(x); //paramType is const int&
    f2(cx); //paramType is const int&
    f2(rx); //paramType is const int&
    
    //same rules apply for pointers
    
    f3(&x); //paramType is int*
    f3(&px); //paramType is const int*
    
    return 0;
}
