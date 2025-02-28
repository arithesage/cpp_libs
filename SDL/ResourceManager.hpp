#ifndef __SDL_RESOURCE_MANAGER__
#define __SDL_RESOURCE_MANAGER__

#include <Dictionary.hpp>
#include <Event.hpp>


/**
 * A class for tracking resource usage
 */
template <typename T>
class ResourceManager
{
    public:
        class ResourceFreeListener : public Listener1P<T>
        {
            protected:
                void onResourceFree (T* resource);

            public:
                void _Notify (P1 p1) override;
        };


        /**
         * The resource is free (nobody is using it)
         */
        class ResourceFreeEvent : public Event1P<T>
        {

        };

    private:
        Dictionary<const char*, T*> resources;
        Dictionary<const char*, int> currentUsers;        

    public:
        /**
         * Register a new resource
         * 
         * @param resourceId Resource name (ID)
         * @param resource A pointer to the resource itself
         */
        void Register (const char* resourceId, T* resource);


        /**
         * Leave a resource (end using it).
         * Decrements the current user count of this resource.
         * 
         * @param resourceId Resource name (ID)
         */
        void Leave (const char* resourceId);


        /**
         * Start using a resource.
         * Increments the current user count of this resource.
         * 
         * @param resourceId Resource name (ID)
         * @returns A pointer to the desired resource
         */
        T* Use (const char* resourceId);
};


template <typename T>
void ResourceManager<T>::ResourceFreeListener::_Notify (T* resource)
{

}



template <typename T>
void ResourceManager<T>::Register (const char* resourceId, T* resource)
{
    if (resource != nullptr)
    {
        resources[resourceId] = resource;
        currentUsers[resourceId] = 0;
    }
}


template <typename T>
void ResourceManager<T>::Leave (const char* resourceId)
{
    if (currentUsers[resourceId] > 0)
    {
        currentUsers[resourceId]--;
    }
}


template <typename T>
T* ResourceManager<T>::Use (const char* resourceId)
{
    T* res = resources[resourceId];

    if (res == nullptr)
    {
        return nullptr;
    }

    currentUsers[resourceId]++;
    return res;
}

#endif


















