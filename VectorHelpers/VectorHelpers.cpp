#include <VectorHelpers.hpp>


std::vector<ItemType> VectorHelpers::Pack (std::initializer_list<ItemType> items)
{
    std::vector<ItemType> list;

    for (ItemType item : items)
    {
        list.push_back (item);
    }

    return list;
}
