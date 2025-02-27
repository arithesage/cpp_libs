#ifndef __SDL_KEYBOARD_LISTENER__
#define __SDL_KEYBOARD_LISTENER__

#include <SDL2/SDL.h>

#include <Listener.hpp>


class SDLKeyListener : public Listener2P<bool, SDL_Keycode>
{
    protected:
        virtual void onKeyPressed (SDL_Keycode key) = 0;
        virtual void onKeyRelease (SDL_Keycode key) = 0;

    public:
        void _Notify (bool status, SDL_Keycode key) override;
};

#endif