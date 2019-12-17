#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <chrono>
#include <unistd.h>
#include <math.h>
#include <cmath>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <SDL_ttf.h>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <sstream>
#include <memory>
#include <set>
#include <fstream>

#define PI 3.14159265

class GTimer
{
    public:
        //Initializes variables
        GTimer();

        //The various clock actions
        void start();
        void stop();
        void pause();
        void unpause();

        //Gets the timer's time
        Uint32 getTicks();

        //Checks the status of the timer
        bool isStarted();
        bool isPaused();

    private:
        //The clock time when the timer started
        Uint32 mStartTicks;

        //The ticks stored when the timer was paused
        Uint32 mPausedTicks;

        //The timer status
        bool mPaused;
        bool mStarted;
};



#endif // TIMER_H
