#include <SDLScene.hpp>

#include <SDL2/SDL.h>

#include <SDL.hpp>
#include <SDLEntity.hpp>
#include <SDLSprite.hpp>



Scene::Scene ()
{

}


Scene::~Scene ()
{
    for (Entity* entity : entities)
    {
        delete entity;
    }
}


void Scene::onEntityDestroyed (Entity* entity)
{

}


void Scene::Render ()
{
    for (Entity* entity : entities)
    {
        if (entity->IsVisible())
        {
            int x = entity->X();
            int y = entity->Y();
            int width = entity->Graphic()->Width();
            int height = entity->Graphic()->Height();

            SDL_Texture* graphic = entity->Graphic()->Texture();
            SDL_Rect rect = { x, y, width, height };
            SDL::Render (graphic, &rect);
        }
    }
}


void Scene::Spawn (Entity* entity)
{
    if (entity != nullptr)
    {
        entities.push_back (entity);
    }
}
