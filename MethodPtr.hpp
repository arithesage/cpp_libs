#ifndef __METHOD_PTR__
#define __METHOD_PTR__

template <typename Class>
using Method = void (Class::*) ();

template <typename InstanceClass>
void CallMethodPtr (InstanceClass instance,
                    MethodPtr<InstanceClass> method)
{
    (instance.*method) ();
}

#endif
