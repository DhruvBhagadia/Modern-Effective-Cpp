/*
	Deducing types for variables declared auto is similar to template type deduction
    with the only exception being braced initialization, during which auto deduces type
    to be initializer_list while template type deduction gives an error

    Template of the form: 
    template<typename T>
    void f(paramType param){}
*/

template<typename T>
void virtual_func_to_deduce_type_of_x(T param){}

template<typename T>
void virtual_func_to_deduce_type_of_cx(const T param){}

template<typename T>
void virtual_func_to_deduce_type_of_rx(T param){}

int main() {
    auto x = 27;
    const auto cx = x;
    const auto& rx = &x;

    //virtual template call, auto is analogous to T

    virtual_func_to_deduce_type_of_x(27) //paramType is the type for x
    
    //Similarly, following calls are made and type of auto is deduced to be int
    virtual_func_to_deduce_type_of_cx(x);
    virtual_func_to_deduce_type_of_rx(x);

    auto y = 30; //int type
    auto y(30); //int type
    auto y{30}; //initalizer_list<int> type and not int

    /*
    auto equivalent will be
    
    template<typename T>
    void func(T param){}
    
    func({30}): err, cannot deduce type T
    */ 

    return 0;
}
