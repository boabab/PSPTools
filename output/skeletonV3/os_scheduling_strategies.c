/*! \file
 *
 * Scheduling strategies used by the Interrupt Service RoutineA from Timer 2 (in scheduler.c) to
 * determine which process may continue its execution next. The file contains five strategies: -even
 * -random -round-robin -inactive-aging -run-to-completion
 *
 */

#include "os_scheduling_strategies.h"
#include "defines.h"
#include <stdbool.h>
#include <stdlib.h>

//----------------------------------------------------------------------------
// Variables
//----------------------------------------------------------------------------

/*!
 * Global Variables.
 */
SchedulingInformation schedulingInfo;


//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

/*!
 * Reset the scheduling information for a specific strategy This is only relevant for RoundRobin and
 * InactiveAging and is done when the strategy is changed through os_setSchedulingStrategy
 *
 * @param strategy The strategy to reset information for
 */
void os_resetSchedulingInformation(SchedulingStrategy strategy) {
    // TODO implement.
}

/*!
 * Reset the scheduling information for a specific process slot This is necessary when a new process
 * is started to clear out any leftover data from a process that previously occupied that slot
 *
 * @param id       The process slot to erase state for
 */
void os_resetProcessSchedulingInformation(ProcessID id) {
    // TODO implement.
}

/*!
 * Function used to determine whether there is any process ready (except the idle process) Returns
 * True iff there is a process ready which is not the idle proc
 *
 * @param processes[] The array of processes that it supposed to be looked through for processes
 *                that are ready
 */
bool isAnyProcReady(const Process processes []) {
    // TODO implement.
}

/*!
 * This function implements the even strategy. Every process gets the same amount of processing time
 * and is rescheduled after each scheduler call if there are other processes running other than the
 * idle process. The idle process is executed if no other process is ready for execution Returns The
 * next process to be executed determined on the basis of the even strategy.
 *
 * @param processes An array holding the processes to choose the next process from.
 * @param current  The id of the current process.
 */
ProcessID os_Scheduler_Even(const Process processes [], ProcessID current) {
    // TODO implement.
}

/*!
 * This function implements the random strategy. The next process is chosen based on the result of a
 * pseudo random number generator. Returns The next process to be executed determined on the basis
 * of the random strategy.
 *
 * @param processes An array holding the processes to choose the next process from.
 * @param current  The id of the current process.
 */
ProcessID os_Scheduler_Random(const Process processes [], ProcessID current) {
    // TODO implement.
}

/*!
 * This function implements the round-robin strategy. In this strategy, process priorities are
 * considered when choosing the next process. A process stays active as long its time slice does not
 * reach zero. This time slice is initialized with the priority of each specific process and
 * decremented each time this function is called. If the time slice reaches zero, the even strategy
 * is used to determine the next process to run. Returns The next process to be executed determined
 * on the basis of the round robin strategy.
 *
 * @param processes An array holding the processes to choose the next process from.
 * @param current  The id of the current process.
 */
ProcessID os_Scheduler_RoundRobin(const Process processes [], ProcessID current) {
    // TODO implement.
}

/*!
 * This function realizes the inactive-aging strategy. In this strategy a process specific integer
 * ("the age") is used to determine which process will be chosen. At first, the age of every waiting
 * process is increased by its priority. After that the oldest process is chosen. If the oldest
 * process is not distinct, the one with the highest priority is chosen. If this is not distinct as
 * well, the one with the lower ProcessID is chosen. Before actually returning the ProcessID, the
 * age of the process who is to be returned is reset to 0. Returns The next process to be executed,
 * determined based on the inactive-aging strategy.
 *
 * @param processes An array holding the processes to choose the next process from.
 * @param current  The id of the current process.
 */
ProcessID os_Scheduler_InactiveAging(const Process processes [], ProcessID current) {
    // TODO implement.
}

/*!
 * This function realizes the run-to-completion strategy. As long as the process that has run before
 * is still ready, it is returned again. If it is not ready, the even strategy is used to determine
 * the process to be returned Returns The next process to be executed, determined based on the run-
 * to-completion strategy.
 *
 * @param processes An array holding the processes to choose the next process from.
 * @param current  The id of the current process.
 */
ProcessID os_Scheduler_RunToCompletion(const Process processes [], ProcessID current) {
    // TODO implement.
}
