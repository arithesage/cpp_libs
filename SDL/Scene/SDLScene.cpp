#include <SDLScene.hpp>

#include <SDLEntity.hpp>


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


void Scene::Spawn (Entity* entity)
{
    if (entity != nullptr)
    {
        entities.push_back (entity);
    }
}


void Scene::onEntityDestroyed (Entity* entity)
{
    
}