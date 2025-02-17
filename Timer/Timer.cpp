#include <Timer.hpp>


Timer::Timer (void (*onFinish) ())
{
    this->onFinish = onFinish;
}


Timer::Timer (void (*onFinish) (), bool repeat)
{
    this->onFinish = onFinish;
    this->repeat = repeat;
}


Timer::Timer (float interval, void (*onFinish) ())
{
    this->interval = interval;
    this->onFinish = onFinish;
}


Timer::Timer (float interval, void (*onFinish) (), bool repeat)
{
    this->interval = interval;
    this->onFinish = onFinish;
    this->repeat = repeat;
}


Timer::~Timer ()
{

}


bool Timer::Running ()
{
    return running;
}


void Timer::Start ()
{
    running = true;
    accumulator = 0.0f;
}


void Timer::Stop ()
{

}


void Timer::tick ()
{

}


void Timer::update ()
{
    if (running)
    {
        auto currentTime = stopWatch::now ();

        timeLapse deltaTime = (currentTime - lastTime);
    }
}