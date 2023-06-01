/** @file Timer.cpp
 *  @brief Contains the Timer Class implementation.
 *  @author -
 *  @bug No known bugs.
 */

#include <ctime>
#include "Timer.h"


void Timer::start() {
    startTime = clock();
}

unsigned long Timer::stop() {
    return clock() - startTime;
}