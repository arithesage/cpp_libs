#include <Common.hpp>

#include <Types.hpp>
#include <StringHelpers.hpp>


void Common::Print (const char* message, Args<const char *> params)
{
    using SHelpers = StringHelpers;

    String _message (message);
    List<const char*> _params = ListFromArgs<const char*> (params);

    for (int p = 0; p < _params.size(); p ++)
    {
        const char* param = _params[p];
        
        String paramPlaceHolder = SHelpers::Concat (
            "${",
            SHelpers::IntToStr(p).c_str(),
            "}"
        );

        if (SHelpers::Has (message, paramPlaceHolder))
        {
            //SHelpers::Replace ()
        }
    }    
}
