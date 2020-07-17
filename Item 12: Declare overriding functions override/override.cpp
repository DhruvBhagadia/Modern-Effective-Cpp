/*
    whenever a method is overridden few conditions need to be met. However, if
    these conditions are not met the code still compiles and produces unpredictable
    results. To avoid such scenarios declaring methods that override base methods as
    "override" produces meaningful errors and solves alot of problems
*/

#include<iostream>

using namespace std;

class Base {
    public:
        virtual void f1() const;
        virtual void f2(int x);
        virtual void f3() &;
        void f4() const;
};

/*
    Having a code like this will not produce errors

    class Derived: public Base {
        public:
            virtual void f1();
            virtual void f2(unsigned int x);
            virtual void f3() &&;
            void f4() const;
    };
*/

/*
    Declared with "override" produces meaningful errors
    error: ‘virtual void Derived::f1()’ marked ‘override’, but does not override
    error: ‘virtual void Derived::f2(unsigned int)’ marked ‘override’, but does not override...
*/

class Derived: public Base {
    public:
        virtual void f1() override;
        virtual void f2(unsigned int x) override;
        virtual void f3() && override;
        void f4() const override;
};

int main(){
    
    return 0;
}
