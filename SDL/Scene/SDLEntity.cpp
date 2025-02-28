#include <SDLEntity.hpp>

#include <SDLEntityDestructionListener.hpp>
#include <SDLSprite.hpp>


Entity::Entity ()
{

}


Entity::~Entity ()
{
    onDestroy.Fire (this);
}

/*
Sprite* Entity::Graphic ()
{
    return sprite;
}
*/

void Entity::Hide ()
{
    visible = false;
}


bool Entity::IsVisible ()
{
    return visible;
}


void Entity::OnDestroy (EntityDestructionListener* listener)
{
    if (listener != nullptr)
    {
        onDestroy.Subscribe (listener);
    }
}


void Entity::SetCoords (int x, int y)
{
    this->x = x;
    this->y = y;
}

/*
void Entity::SetGraphic ()
{

}
*/

void Entity::Show ()
{
    visible = true;
}


int Entity::X ()
{
    return x;
}


int Entity::Y ()
{
    return y;
}
