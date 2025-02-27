#ifndef __SDL_SCENE__
#define __SDL_SCENE__

#include <List.hpp>


class Entity;


/**
 * Scene is just a container of entities
 */
class Scene
{
    protected:
        List<Entity*> entities;

    public:
        Scene ();
        ~Scene ();

        void Spawn (Entity* entity);
};

#endif