/*
	Case 3: paramType is a pass by value

    The reference/pointer ans/or constness/volatility of expr are ignored since the expr being const/volatile
    nothing to do with what param will be

    Template of the form: 
    template<typename T>
    void f(paramType param){}
*/

template<typename T>
void f(T param){}

int main() {
    int x = 27;
    const int cx = x;
    const int& rx = x;
        
    f(x); //paramType is int
    f(cx); //paramType in int
    f(rx); //paramType is int
    
    //const to the right of * makes the ptr to be const and not modifiable, 
    //that to the left indicates ptr points to constness 

    const char* const ptr = "Hello"; //const ptr to a const string
    f(ptr); //const is ignored, paramType is ptr to a const string

    return 0;
}
