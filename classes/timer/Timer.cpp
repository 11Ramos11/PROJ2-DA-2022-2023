//
// Created by Ramos on 5/29/2023.
//

#include <ctime>
#include "Timer.h"


void Timer::start() {
    startTime = clock();
}

unsigned long Timer::stop() {
    return clock() - startTime;
}