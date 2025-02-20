#ifndef __TYPES__
#define __TYPES__

#include <any>
#include <iostream>
#include <map>
#include <type_traits>
#include <vector>


using Any = std::any;

using String = std::string;

template <typename Type>
using List = std::vector<Type>;

template <typename Key, typename Value>
using Dictionary = std::map<Key, Value>;

template <typename Key, typename Value>
using Map = std::map<Key, Value>;


class Anything
{
    private:
        Any* something = nullptr;

    public:
        Anything (Any something)
        {
            this->something = &something;
        }

        template <typename Type>
        Anything (Type obj)
        {
            Type* objPtr = &obj;
            Any* something = std::make_any<Type*> (objPtr);
        }

        template <typename Type>
        Anything (Type* obj)
        {
            Any* something = std::make_any<Type*> (obj);
        }

        template <typename Type>
        static Any From (Type obj)
        {
            return std::make_any<Type> (obj);
        }

        template <typename Type>
        bool Is ()
        {
            try
            {
                Type* obj = std::any_cast<Type>(something);

                return true;
            }
            catch (const std::bad_any_cast& e)
            {
                return false;
            }
        }
};


// Special class for testing types
template <typename This>
class Type
{
    public:
        // Returns if Other inherits from This type
        template <typename Base>
        static bool InheritsFrom ()
        {
            return std::is_base_of<Base,This>::value;
        }

        // Returns if This type is a pointer.
        // Intended for use with templated types.
        static bool IsPtr ()
        {
            return std::is_pointer<This>::value;
        }
};

#endif
