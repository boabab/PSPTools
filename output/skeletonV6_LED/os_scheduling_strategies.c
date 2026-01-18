/*! \file
 *
 * Scheduling strategies used by the Interrupt Service RoutineA from Timer 2 (in scheduler.c) to
 * determine which process may continue its execution next. The file contains five strategies: -even
 * -random -round-robin -inactive-aging -run-to-completion
 *
 */

#include "os_scheduling_strategies.h"
#include "defines.h"
#include "os_core.h"
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
 * Maps a process-priority to a priority class. Returns The index of the ProcessQueue/priority class
 *
 * @param prio     The process-priority.
 */
uint8_t MLFQ_MapToQueue(Priority prio) {
    // TODO implement.
}

/*!
 * Returns the default number of timeslices for a specific ProcessQueue/priority class. Returns
 * Number of timeslices.
 *
 * @param queueID  The index of the ProcessQueue/the priority class.
 */
uint8_t MLFQ_getDefaultTimeslice(uint8_t queueID) {
    // TODO implement.
}

/*!
 * Returns the corresponding ProcessQueue . Returns a pointer to the ProcessQueue with index queueID
 * from the schedulingInformation Returns Pointer to the specific ProcessQueue .
 *
 * @param queueID  Index of the queue.
 */
ProcessQueue *MLFQ_getQueue(uint8_t queueID) {
    // TODO implement.
}

/*!
 * Initializes the given ProcessQueue with a predefined size
 *
 * @param queue    The ProcessQueue to initialize.
 */
void pqueue_init(ProcessQueue *queue) {
    // TODO implement.
}

/*!
 * Resets the given ProcessQueue .
 *
 * @param queue    The ProcessQueue to reset.
 */
void pqueue_reset(ProcessQueue *queue) {
    // TODO implement.
}

/*!
 * Checks whether there is next a ProcessID. Returns True if queue has a next element
 *
 * @param queue    The ProcessQueue to check.
 */
bool pqueue_hasNext(const ProcessQueue *queue) {
    // TODO implement.
}

/*!
 * Returns the first ProcessID of the given ProcessQueue . Returns the first ProcessID.
 *
 * @param queue    The specific ProcessQueue .
 */
ProcessID pqueue_getFirst(const ProcessQueue *queue) {
    // TODO implement.
}

/*!
 * Drops the first ProcessID of the given ProcessQueue .
 *
 * @param queue    The specific ProcessQueue .
 */
void pqueue_dropFirst(ProcessQueue *queue) {
    // TODO implement.
}

/*!
 * Appends a ProcessID to the given ProcessQueue .
 *
 * @param queue    The ProcessQueue in which the pid should be appended.
 * @param pid      The ProcessId to append.
 */
void pqueue_append(ProcessQueue *queue, ProcessID pid) {
    // TODO implement.
}

/*!
 * Removes a ProcessID from the given ProcessQueue .
 *
 * @param queue    The ProcessQueue from which the pid should be removed.
 * @param pid      The ProcessId to remove.
 */
void pqueue_removePID(ProcessQueue *queue, ProcessID pid) {
    // TODO implement.
}

/*!
 * Initializes all ProcessQueues for the MLFQ.
 */
void os_initSchedulingInformation() {
    // TODO implement.
}

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

/*!
 * Function that removes the given ProcessID from the ProcessQueues.
 *
 * @param pid      The ProcessId to remove.
 */
void MLFQ_removePID(ProcessID pid) {
    // TODO implement.
}

/*!
 * This function implements the multilevel-feedback-queue with 4 priority-classes. Every process is
 * inserted into a queue of a priority-class and gets a default amount of timeslices which are class
 * dependent. If a process has no timeslices left, it is moved to the next class. If a process
 * yields, it is moved to the end of the queue. Returns The next process to be executed determined
 * on the basis of the even strategy.
 *
 * @param processes An array holding the processes to choose the next process from.
 * @param current  The id of the current process.
 */
ProcessID os_Scheduler_MLFQ(const Process processes [], ProcessID current) {
    // TODO implement.
}
