#ifndef __SDL_ENTITY__
#define __SDL_ENTITY__

#include <SDLEntityEvents.hpp>

class EntityDestructionListener;
class Sprite;

class Entity
{
    private:
        Sprite* sprite = nullptr;
        EntityDestroyedEvent onDestroy;

    public:
        Entity ();
        ~Entity ();

        void OnDestroy (EntityDestructionListener* listener);
        Sprite* Sprite ();
};

#endif