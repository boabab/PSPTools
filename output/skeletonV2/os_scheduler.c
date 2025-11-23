/*! \file
 * \brief Scheduling module for the OS.
 *
 * Contains everything needed to realise the scheduling between multiple processes. Also contains
 * functions to start the execution of programs.
 *
 * \author Lehrstuhl Informatik 11 - RWTH Aachen
 *
 */

#include "os_scheduler.h"
#include "lcd.h"
#include "os_core.h"
#include "os_input.h"
#include "os_scheduling_strategies.h"
#include "os_taskman.h"
#include "util.h"
#include <avr/interrupt.h>
#include <stdbool.h>

//----------------------------------------------------------------------------
// Variables
//----------------------------------------------------------------------------

/*!
 * Array of states for every possible process.
 */
Process os_processes [ MAX_NUMBER_OF_PROCESSES ];

/*!
 * Index of process that is currently executed (default: idle)
 */
ProcessID currentProc = 0;

/*!
 * Currently active scheduling strategy.
 */
SchedulingStrategy currSchedStrat;

/*!
 * Count of currently nested critical sections.
 */
uint8_t criticalSectionCount = 0;


//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

/*!
 * ISR for timer compare match (scheduler)
 */
__attribute__((naked)) {
    // TODO implement.
}

/*!
 * Timer interrupt that implements our scheduler. Execution of the running process is suspended and
 * the context saved to the stack. Then the periphery is scanned for any input events. If everything
 * is in order, the next process for execution is derived with an exchangeable strategy. Finally the
 * scheduler restores the next process for execution and releases control over the processor to that
 * process.
 */
ISR(TIMER2_COMPA_vect) {
    // TODO implement.
}

/*!
 * This is the idle program. The idle process owns all the memory and processor time no other
 * process wants to have.
 */
void idle(void) {
    // TODO implement.
}

/*!
 * This function is used to register the given program for execution. A stack will be provided if
 * the process limit has not yet been reached. This function is multitasking safe. That means that
 * programs can repost themselves, simulating TinyOS 2 scheduling (just kick off interrupts ;) ).
 * Returns The index of the new process or INVALID_PROCESS as specified in defines.h on failure
 *
 * @param program  The function of the program to start.
 * @param priority A priority ranging 0..255 for the new process: 0 means least favourable 255 means
 *                most favourable Note that the priority may be ignored by certain scheduling
 *                strategies.
 */
ProcessID os_exec(Program * program , Priority priority) {
    // TODO implement.
}

/*!
 * If all processes have been registered for execution, the OS calls this function to start the idle
 * program and the concurrent execution of the applications.
 */
void os_startScheduler(void) {
    // TODO implement.
}

/*!
 * In order for the Scheduler to work properly, it must have the chance to initialize its internal
 * data-structures and register.
 */
void os_initScheduler(void) {
    // TODO implement.
}

/*!
 * A simple getter for the slot of a specific process. Returns A pointer to the memory of the
 * process at position pid in the os_processes array.
 *
 * @param pid      The processID of the process to be handled
 */
Process * os_getProcessSlot(ProcessID pid) {
    // TODO implement.
}

/*!
 * A simple getter to retrieve the currently active process. Returns The process id of the currently
 * active process.
 */
ProcessID os_getCurrentProc(void) {
    // TODO implement.
}

/*!
 * Sets the current scheduling strategy.
 *
 * @param strategy The strategy that will be used after the function finishes.
 */
void os_setSchedulingStrategy(SchedulingStrategy strategy) {
    // TODO implement.
}

/*!
 * This is a getter for retrieving the current scheduling strategy. Returns The current scheduling
 * strategy.
 */
SchedulingStrategy os_getSchedulingStrategy(void) {
    // TODO implement.
}

/*!
 * Enters a critical code section by disabling the scheduler if needed. This function stores the
 * nesting depth of critical sections of the current process (e.g. if a function with a critical
 * section is called from another critical section) to ensure correct behaviour when leaving the
 * section. This function supports up to 255 nested critical sections.
 */
void os_enterCriticalSection(void) {
    // TODO implement.
}

/*!
 * Leaves a critical code section by enabling the scheduler if needed. This function utilizes the
 * nesting depth of critical sections stored by os_enterCriticalSection to check if the scheduler
 * has to be reactivated.
 */
void os_leaveCriticalSection(void) {
    // TODO implement.
}

/*!
 * Calculates the checksum of the stack for a certain process. Returns The checksum of the pid'th
 * stack.
 *
 * @param pid      The ID of the process for which the stack's checksum has to be calculated.
 */
StackChecksum os_getStackChecksum(ProcessID pid) {
    // TODO implement.
}
