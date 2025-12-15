/*! \file
 * \brief Scheduling library for the OS.
 *
 * Contains the scheduling strategies.
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#ifndef _OS_SCHEDULING_STRATEGIES_H
#define _OS_SCHEDULING_STRATEGIES_H

#include "defines.h"
#include "os_scheduler.h"

//----------------------------------------------------------------------------
// Typedefs
//----------------------------------------------------------------------------

//! Structure used to store specific scheduling informations such as a time slice.
typedef struct {
    // TODO implement.
} SchedulingInformation;


//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

//! Initialises the scheduling information.
void os_initSchedulingInformation();

//! Used to reset the SchedulingInfo for one process.
void os_resetProcessSchedulingInformation(ProcessID id);

//! Used to reset the SchedulingInfo for a strategy.
void os_resetSchedulingInformation(SchedulingStrategy strategy);

//! Even strategy.
ProcessID os_Scheduler_Even(const Process processes [], ProcessID current);

//! Random strategy.
ProcessID os_Scheduler_Random(const Process processes [], ProcessID current);

//! RoundRobin strategy.
ProcessID os_Scheduler_RoundRobin(const Process processes [], ProcessID current);

//! InactiveAging strategy.
ProcessID os_Scheduler_InactiveAging(const Process processes [], ProcessID current);

//! RunToCompletion strategy.
ProcessID os_Scheduler_RunToCompletion(const Process processes [], ProcessID current);

//! MultiLevelFeedbackQueue strategy.
ProcessID os_Scheduler_MLFQ(const Process processes [], ProcessID current);

//! Function that removes the given ProcessID from the ProcessQueues.
void MLFQ_removePID(ProcessID pid);

//! Returns the corresponding ProcessQueue .
ProcessQueue *MLFQ_getQueue(uint8_t queueID);

//! Returns the default number of timeslices for a specific ProcessQueue/priority class.
uint8_t MLFQ_getDefaultTimeslice(uint8_t queueID);

//! Maps a process-priority to a priority class.
uint8_t MLFQ_MapToQueue(Priority prio);

//! Initializes the given ProcessQueue with a predefined size.
void pqueue_init(ProcessQueue *queue);

//! Resets the given ProcessQueue .
void pqueue_reset(ProcessQueue *queue);

//! Checks whether there is next a ProcessID.
bool pqueue_hasNext(const ProcessQueue *queue);

//! Returns the first ProcessID of the given ProcessQueue .
ProcessID pqueue_getFirst(const ProcessQueue *queue);

//! Drops the first ProcessID of the given ProcessQueue .
void pqueue_dropFirst(ProcessQueue *queue);

//! Appends a ProcessID to the given ProcessQueue .
void pqueue_append(ProcessQueue *queue, ProcessID pid);

//! Removes a ProcessID from the given ProcessQueue .
void pqueue_removePID(ProcessQueue *queue, ProcessID pid);

#endif
