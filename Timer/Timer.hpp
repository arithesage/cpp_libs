#ifndef __TIMER__
#define __TIMER__

#include <chrono>

using stopWatch = std::chrono::steady_clock;
using duration = std::chrono::duration<float>;
using moment = stopWatch::time_point;


/**
 * A simple timer.
 * 
 * You can create one just pausing the current thread, but this one
 * works without using them.
 * 
 * To create one, you need, at least, to specify a function to call when
 * the timeout ends.
 * 
 * Because the timer do not make use of threads, the way to make it advance
 * is using a infinite loop and calling its Update function/method there.
 */
class Timer
{
    private:
        float accumulator = 0.0f;
        float timeout = 1.0f;
        int currentLaps = 0;
        int totalLaps = 0;
        
        bool running = false;

        moment lastTime;
        moment now;

        void (*onStop) ();
        void (*onTimeout) ();

    public:
        Timer (void (*onTimeout) ());


        /**
         * Creates a new timer that will stop after X laps.
         * 
         * If laps == 0, it will last only one.
         * If laps == -1, it will last until stopped.
         */
        Timer (void (*onTimeout) (), int laps);


        /**
         * Creates a new timer that will stop after the given timeout
         */
        Timer (void (*onTimeout) (), float timeout);


        /**
         * Creates a new timer that will stop after X laps.
         * Each lap will last until the given timeout.
         * 
         * If laps == 0, it will last only one.
         * If laps == -1, it will last until stopped.
         */
        Timer (void (*onTimeout) (), float timeout, int laps);


        ~Timer ();


        /**
         * Stops the timer also resetting it
         */
        void OnStop (void (*onStop) ());


        /**
         * Resets the timer accumulator and lap counter
         */
        void Reset ();


        /**
         * Check if the timer is running
         */
        bool Running ();


        /**
         * Starts the timer
         */
        void Start ();


        /**
         * Stops the timer
         */
        void Stop ();


        /**
         * You must call this in your loop for the timer to advance
         */
        void Update ();
};

#endif