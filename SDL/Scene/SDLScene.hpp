#ifndef __SDL_SCENE__
#define __SDL_SCENE__

#include <List.hpp>
#include <SDLEntityDestructionListener.hpp>

class Entity;


/**
 * Scene is just a container of entities
 */
class Scene : public EntityDestructionListener
{
    protected:
        List<Entity*> entities;

    public:
        Scene ();
        ~Scene ();

    private:
        void onEntityDestroyed (Entity* entity) override;

    public:
        void Render ();
        void Spawn (Entity* entity);
};

#endif
