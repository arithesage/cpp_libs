#include <SDLScene.hpp>

#include <SDLEntity.hpp>


Scene::Scene ()
{

}


Scene::~Scene ()
{
    for (SDLEntity* entity : entities)
    {
        delete entity;
    }
}


void Scene::Spawn (SDLEntity* entity)
{
    if (entity != nullptr)
    {
        entities.push_back (entity);
    }
}