#ifndef __TIMER__
#define __TIMER__

#include <chrono>

using stopWatch = std::chrono::steady_clock;
using timeLapse = std::chrono::duration<float>;


class Timer
{
    private:
        float accumulator = 0.0f;
        float interval = 1.0f;
        bool repeat = false;
        bool running = false;

        void (*onFinish) ();

    public:
        Timer (void (*onFinish) ());
        Timer (void (*onFinish) (), bool repeat);
        Timer (float interval, void (*onFinish) ());
        Timer (float interval, void (*onFinish) (), bool repeat);

        ~Timer ();

        bool Running ();
        void Start ();
        void Stop ();

    private:
        void tick ();
        void update ();
};

#endif