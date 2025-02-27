#ifndef __SDL_ENTITY__
#define __SDL_ENTITY__

class Sprite;

class Entity
{
    private:
        Sprite* sprite = nullptr;

    public:
        Entity ();
        ~Entity ();

        Sprite* Sprite ();
};

#endif