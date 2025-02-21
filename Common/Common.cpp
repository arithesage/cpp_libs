#include <Common.hpp>

#include <Types.hpp>
#include <StringHelpers.hpp>


void Common::Print (const char* message, Args<const char *> params)
{
    using SHelpers = StringHelpers;

    List<const char*> _params = ListFromArgs<const char*> (params);
    String placeHolders = "";

    for (int p = 0; p < _params.size(); p ++)
    {
        placeHolders = SHelpers::Concat ({
            "$[",
            SHelpers::IntToStr(p).c_str(),
            "]"
        });

        if (p < (_params.size() - 1))
        {
            placeHolders += " ";
        }
    }
}

