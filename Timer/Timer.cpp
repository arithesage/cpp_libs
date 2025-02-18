#include <Timer.hpp>


Timer::Timer (void (*onTimeout) ())
{
    this->onTimeout = onTimeout;
}


Timer::Timer (void (*onTimeout) (), int laps)
{
    this->onTimeout = onTimeout;
    this->totalLaps = laps;
}


Timer::Timer (void (*onTimeout) (), float timeout)
{
    this->timeout = timeout;
    this->onTimeout = onTimeout;
}


Timer::Timer (void (*onTimeout) (), float timeout, int laps)
{
    this->timeout = timeout;
    this->onTimeout = onTimeout;
    this->totalLaps = laps;
}


Timer::~Timer ()
{

}


void Timer::OnStop (void (*onStop) ())
{
    this->onStop = onStop;
}


void Timer::Reset ()
{
    accumulator = 0.0f;
    currentLaps = 0;
}


bool Timer::Running ()
{
    return running;
}


void Timer::Start ()
{
    Reset ();

    running = true;
    lastTime = stopWatch::now();
}


void Timer::Stop ()
{
    running = false;

    if (onStop != nullptr)
    {
        onStop ();
    }
}


void Timer::Update ()
{
    if (running)
    {
        now = stopWatch::now ();
        duration deltaTime = (now - lastTime);
        lastTime = now;
        
        accumulator += deltaTime.count ();
        
        if (accumulator >= timeout)
        {
            accumulator = 0;
            onTimeout ();

            if (totalLaps == 0)
            {
                Stop ();
            }
            else if (totalLaps > 0)
            {
                currentLaps ++;
            
                if (currentLaps == totalLaps)
                {
                    Stop ();
                }
            }            
        }
    }
}