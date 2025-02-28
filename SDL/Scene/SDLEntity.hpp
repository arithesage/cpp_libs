#ifndef __SDL_ENTITY__
#define __SDL_ENTITY__

#include <SDLEntityEvents.hpp>

class EntityDestructionListener;
//class Sprite;

class Entity
{
    private:
        int x = 0;
        int y = 0;

//        Sprite* sprite = nullptr;
        EntityDestroyedEvent onDestroy;

        bool visible = true;

    public:
        Entity ();
        ~Entity ();

//        Sprite* Graphic ();
        void Hide ();
        bool IsVisible ();

        void OnDestroy (EntityDestructionListener* listener);

        void SetCoords (int x, int y);
//        void SetGraphic ();
        void Show ();
        int X ();
        int Y ();
};

#endif
