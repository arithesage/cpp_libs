#ifndef __RESOURCE__
#define __RESOURCE__

/**
 * A resource. Can be provided by a loaded file or not.
 * For use with the Pool.
 */
class Resource
{
    protected:
        const char* filePath = "";
        bool exists = false;

        virtual void Dispose ();

    public:
        Resource ();
        Resource (const char* filePath);
        ~Resource ();

        virtual bool IsValid ();
};

#endif
