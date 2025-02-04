#ifndef __VECTOR_HELPERS__
#define __VECTOR_HELPERS__

#include <initializer_list>


class VectorHelpers
{
    public:
        /**
         * Returns a vector containing all the provided items.
         * The items must be provided betwee { and }.
         * Example: Pack<const char*> ({ "one", "two" })
         */
        template <typename ItemType>
        static std::vector<ItemType> Pack (std::initializer_list<ItemType> items);
};

#endif
