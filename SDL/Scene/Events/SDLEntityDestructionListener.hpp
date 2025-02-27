#ifndef __SDL_ENTITY_LISTENERS__
#define __SDL_ENTITY_LISTENERS__

#include <Listener.hpp>
#include <SDLEntity.hpp>


class EntityDestructionListener : Listener1P<Entity*>
{
    protected:
        virtual void onEntityDestroyed (Entity* entity) = 0;

    public:
        void _Notify (Entity* entity) override
        {
            onEntityDestroyed (entity);
        }
};

#endif