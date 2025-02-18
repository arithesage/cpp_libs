#ifndef __TIMER__
#define __TIMER__

#include <chrono>

using stopWatch = std::chrono::steady_clock;
using duration = std::chrono::duration<float>;
using moment = stopWatch::time_point;


class Timer
{
    private:
        float accumulator = 0.0f;
        float interval = 1.0f;
        int currentLaps = 0;
        int totalLaps = 0;
        
        bool running = false;

        moment lastTime;
        moment now;

        void (*onTimeout) ();

    public:
        Timer (void (*onTimeout) ());
        Timer (void (*onTimeout) (), int laps);
        Timer (float interval, void (*onTimeout) ());
        Timer (float interval, void (*onTimeout) (), int laps);

        ~Timer ();

        void Reset ();
        bool Running ();
        void Start ();
        void Stop ();

    private:        
        void update ();
};

#endif