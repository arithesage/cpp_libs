#include <SDLEntity.hpp>

#include <SDLEntityDestructionListener.hpp>


Entity::Entity ()
{

}


Entity::~Entity ()
{
    onDestroy.Fire (this);
}


Sprite* Entity::Sprite ()
{
    return sprite;
}


void Entity::OnDestroy (EntityDestructionListener* listener)
{
    if (listener != nullptr)
    {
        onDestroy.Subscribe (listener);
    }
}