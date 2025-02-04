#ifndef __VECTOR_HELPERS__
#define __VECTOR_HELPERS__

#include <initializer_list>
#include <vector>


class VectorHelpers
{
    public:
        /**
         * Returns a vector containing all the provided items.
         * The items must be provided betwee { and }.
         * Example: Pack<const char*> ({ "one", "two" })
         */
        template <typename ItemType>
        std::vector<ItemType> VectorHelpers::Pack (std::initializer_list<ItemType> items)
        {
            std::vector<ItemType> list;

            for (ItemType item : items)
            {
                list.push_back (item);
            }

            return list;
        }
};

#endif
