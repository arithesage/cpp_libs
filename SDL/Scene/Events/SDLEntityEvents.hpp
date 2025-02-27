#ifndef __SDL_ENTITY_EVENTS__
#define __SDL_ENTITY_EVENTS__

#include <Event.hpp>


class Entity;

class EntityDestroyedEvent : public Event1P<Entity*>
{
    
};

#endif