#ifndef __SDL_EVENTS__
#define __SDL_EVENTS__

#include <SDL2/SDL.h>

#include <Event.hpp>


class SDLKeyboardEvent : public Event2P<bool, SDL_Keycode>
{

};


class SDLQuitEvent : public Event
{

};

#endif