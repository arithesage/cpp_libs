#include <Log.hpp>

#include <FilesystemHelpers.hpp>


int main ()
{
    String path = FSHelpers::MakePath ({ ".", "README.md" });

    if (FSHelpers::IsFile (path))
    {
        Log::i ("File exists.");
    }
    else
    {
        Log::e ("File not found.");
    }

    return 0;
}
