#ifndef __METHOD_PTR__
#define __METHOD_PTR__

template <typename Class>
using Method = void (Class::*) ();

#define Call(instance,methodPtr) (instance.*ptr)();

#endif
