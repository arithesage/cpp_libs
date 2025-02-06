#include <FilesystemHelpers.hpp>

#include <StringHelpers.hpp>


using FSHelpers = FilesystemHelpers;


bool FilesystemHelpers::IsFile (String path)
{
    ifstream file;
    
    file.open (path);

    if (file.is_open())
    {
        file.close ();
        return true;
    }

    return false;
}


String FilesystemHelpers::MakePath (std::initializer_list<String> pathParts)
{
    String path = StringHelpers::Concat (pathParts, "/");
    return path;
}