/** @file Timer.h
 *  @brief Contains the Timer class declaration.
 *  @author João Ramos e Matilde Simões
 *  @bug No known bugs.
 */

#ifndef PROJ2_DA_2022_2023_TIMER_H
#define PROJ2_DA_2022_2023_TIMER_H

/** @brief Timer class that provides functionality to measure the elapsed time.
 *
 */
class Timer {

    //! @brief Represents the start time.
    unsigned long startTime;

public:

    /** @brief Starts the timer.
     *
     * This method records the current time in the private member variable startTime.
     *
     * @return Void.
     */
    void start();

    /** @brief Stops the timer and returns the elapsed time.
     *
     * This method calculates and returns the elapsed time since the timer was started.
     *
     * @return unsigned long The elapsed time in clock ticks since the timer was started.
     */
    unsigned long stop();
};


#endif //PROJ2_DA_2022_2023_TIMER_H
