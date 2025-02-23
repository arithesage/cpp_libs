#ifndef __LANG_HELPERS__
#define __LANG_HELPERS__

#include <initializer_list>

#ifndef __TYPES__
    #include <vector>

    template <typename Type>
    using List = std::vector<Type>;
#endif


// A variable list of args of the given type
template <typename ArgsType>
using Args = std::initializer_list<ArgsType>;


// Obtain a List (vector) from the params
template <typename Type>
List<Type> ListFromArgs (Args<Type> params)
{
    List<Type> list;

    typename Args<Type>::iterator it;

    for (it = params.begin(); it != params.end(); it ++)
    {
        list.push_back (*it);
    }

    return list;
}


// Obtain a List (vector) from the params.
// This version allows changing the List type.
//
// ATTENTION: The destination type MUST BE compatible.
// That is: The destination type needs a constructor to
// create a new object from the other type.
template <typename ArgsType, typename ToType>
List<ToType> ListFromArgs (Args<ArgsType> params)
{
    List<ToType> list;

    typename Args<ArgsType>::iterator it;

    bool conversionTested = false;

    for (it = params.begin(); it != params.end(); it ++)
    {
        if (!conversionTested)
        {
            ToType* test = new ToType (*it);

            if (test == nullptr)
            {
                return list;
            }
            else
            {
                delete test;
                conversionTested = true;
            }
        }        

        list.push_back (ToType (*it));
    }

    return list;
}


#endif