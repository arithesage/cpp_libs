#ifndef __METHOD_PTR__
#define __METHOD_PTR__

template <typename C>
class MethodPtr
{
    private:
        C* instance = nullptr;
        void (C::*funcPtr) () = nullptr;

    public:
        MethodPtr (C* instance, void (C::*func ());
        void Call ();
};


template <typename C>
MethodPtr::MethodPtr (C* instance, void (C::*func ())
{
    this->instance = instance;
    this->funcPtr = func;
}


template <typename C>
void MethodPtr::Call ()
{
    if ((instance != nullptr) && (funcPtr != nullptr))
    {
        (cInstance->*funcPtr) ();
    }
};
#endif
