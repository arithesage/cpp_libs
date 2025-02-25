#ifndef __POOL_RESOURCE_LOADER__
#define __POOL_RESOURCE_LOADER__

template <typename R>
class ResourceLoader
{
    protected:
        virtual bool Load (const char* filePath) = 0;
};

#endif