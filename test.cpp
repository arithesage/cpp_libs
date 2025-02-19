#include <iostream>
#include <FunctionPointers.hpp>

using std::cout;
using std::endl;


class Test
{
    public:
        void func ()
        {
            cout << "Hello\n";
        }

        void func2 (const char* message)
        {
            cout << message;
        }
};


int main ()
{
    Test t;

    MethodPtr<Test> testFunc = &Test::func;
    MethodPtr1P<Test, const char*> testFunc2 = &Test::func2;

    CallMethodPtr<Test> (t, testFunc);
    CallMethodPtr<Test, const char*> (t, testFunc2, "Hello world!\n");

    return 0;
}
