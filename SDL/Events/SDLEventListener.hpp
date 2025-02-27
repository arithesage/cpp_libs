#ifndef __SDL_LISTENER__
#define __SDL_LISTENER__

#include <Listener.hpp>


class SDLEventListener : public Listener
{
    protected:
        virtual void onQuit () = 0;

    public:
        void _Notify () override;
};

#endif