#ifndef __SDL_ENTITY_EVENTS__
#define __SDL_ENTITY_EVENTS__

#include <Event.hpp>


class SDLEntity;

class SDLEntityDestroyedEvent : Event1P<SDLEntity*>
{
    
};

#endif