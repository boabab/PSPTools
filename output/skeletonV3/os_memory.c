/*! \file
 *
 * Contains functions to allocate blocks of any spos-memory-drivers. We manage the blocks by
 * creating a lookup table with one nibble per byte payload. So we have 1/3 map and 2/3 use-heap of
 * each driver. Important: Always use addresses of the use-heap and convert them into the nibbles of
 * the map (only) if needed. For this purpose, there are helper functions such as
 * os_getMapEntry(...).
 *
 */

#include "os_memory.h"
#include "os_core.h"
#include "os_memory_strategies.h"
#include "util.h"

//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

/*!
 * Writes a value from 0x0 to 0xF to the lower nibble of the given address.
 *
 * @param heap     The heap that is written to
 * @param addr     The address on which the lower nibble is supposed to be changed
 * @param value    The value that the lower nibble of the given addr is supposed to get
 */
void setLowNibble(const Heap *heap, MemAddr addr, MemValue value) {
    // TODO implement.
}

/*!
 * Writes a value from 0x0 to 0xF to the higher nibble of the given address.
 *
 * @param heap     The heap that is written to
 * @param addr     The address on which the higher nibble is supposed to be changed
 * @param value    The value that the higher nibble of the given addr is supposed to get
 */
void setHighNibble(const Heap *heap, MemAddr addr, MemValue value) {
    // TODO implement.
}

/*!
 * Returns The value that can be found on the lower nibble of the given address
 *
 * @param heap     The heap that is read from
 * @param addr     The address which the lower nibble is supposed to be read from
 */
MemValue getLowNibble(const Heap *heap, MemAddr addr) {
    // TODO implement.
}

/*!
 * Returns The value that can be found on the higher nibble of the given address
 *
 * @param heap     The heap that is read from
 * @param addr     The address which the higher nibble is supposed to be read from
 */
MemValue getHighNibble(const Heap *heap, MemAddr addr) {
    // TODO implement.
}

/*!
 * This function is used to set a heap map entry on a specific heap.
 *
 * @param heap     The heap on whos map the entry is supposed to be set
 * @param addr     The address in use space for which the corresponding map entry shall be set
 * @param value    The value that is supposed to be set onto the map (valid range: 0x0 - 0xF)
 */
void setMapEntry(const Heap *heap, MemAddr addr, MemValue value) {
    // TODO implement.
}

/*!
 * This function is used to get a heap map entry on a specific heap Returns The value that can be
 * found on the heap map entry that corresponds to the given use space address
 *
 * @param heap     The heap from whos map the entry is supposed to be fetched
 * @param addr     The address in use space for which the corresponding map entry shall be fetched
 */
MemValue os_getMapEntry(const Heap *heap, MemAddr addr) {
    // TODO implement.
}

/*!
 * This function is used to determine where a chunk starts if a given address might not point to the
 * start of the chunk but to some place inside of it. Returns The address that points to the first
 * byte of the chunk
 *
 * @param heap     The heap the chunk is on hand in
 * @param addr     The address that points to some byte of the chunk
 */
MemAddr os_getFirstByteOfChunk(const Heap *heap, MemAddr addr) {
    // TODO implement.
}

/*!
 * This function determines the value of the first nibble of a chunk. Returns The map entry that
 * corresponds to the first byte of the chunk
 *
 * @param heap     The heap the chunk is on hand in
 * @param addr     The address that points to some byte of the chunk
 */
ProcessID getOwnerOfChunk(const Heap *heap, MemAddr addr) {
    // TODO implement.
}

/*!
 * Takes a use-pointer and computes the length of the chunk. This only works for occupied chunks.
 * The size of free chunks is always 0. Returns The chunk's length.
 *
 * @param heap     The driver to be used.
 * @param addr     An address of the use-heap.
 */
uint16_t os_getChunkSize(const Heap *heap, MemAddr addr) {
    // TODO implement.
}

/*!
 * Frees a chunk of allocated memory on the medium given by the driver. This function checks if the
 * call has been made by someone with the right to do it (i.e. the process that owns the memory or
 * the OS). This function is made in order to avoid code duplication and is called by several
 * functions that, in some way, free allocated memory such as os_freeProcessMemory/os_free...
 *
 * @param heap     The driver to be used.
 * @param addr     An address inside of the chunk (not necessarily the start).
 * @param owner    The expected owner of the chunk to be freed
 */
void os_freeOwnerRestricted(Heap *heap, MemAddr addr, ProcessID owner) {
    // TODO implement.
}

/*!
 * Allocates a chunk of memory on the medium given by the driver and reserves it for the current
 * process. Returns A pointer to the first Byte of the allocated chunk. 0 if allocation fails (0 is
 * never a valid address).
 *
 * @param heap     The driver to be used.
 * @param size     The amount of memory to be allocated in Bytes. Must be able to handle a single
 *                byte and values greater than 255.
 */
MemAddr os_malloc(Heap *heap, size_t size) {
    // TODO implement.
}

/*!
 * Frees a chunk of allocated memory of the currently running process on the given heap
 *
 * @param heap     The driver to be used.
 * @param addr     An address inside of the chunk (not necessarily the start).
 */
void os_free(Heap *heap, MemAddr addr) {
    // TODO implement.
}

/*!
 * The Heap-map-size of the heap (needed by the taskmanager) Returns The size of the map of the heap
 *
 * @param heap     The heap to be used.
 */
size_t os_getMapSize(const Heap *heap) {
    // TODO implement.
}

/*!
 * The Heap-use-size of the heap (needed by the taskmanager) Returns The size of the use-area of the
 * heap
 *
 * @param heap     The heap to be used.
 */
size_t os_getUseSize(const Heap *heap) {
    // TODO implement.
}

/*!
 * The Map-start of the heap (needed by the taskmanager) Returns The first byte of the map of the
 * heap
 *
 * @param heap     The heap to be used.
 */
MemAddr os_getMapStart(const Heap *heap) {
    // TODO implement.
}

/*!
 * The Heap-use-start of the heap (needed by the taskmanager) Returns The first byte of the use-area
 * of the heap
 *
 * @param heap     The heap to be used.
 */
MemAddr os_getUseStart(const Heap *heap) {
    // TODO implement.
}

/*!
 * Simple setter function to change the allocation strategy of a given heap
 *
 * @param heap     The heap of which the allocation strategy shall be changed
 * @param allocStrat The strategy is changed to allocStrat
 */
void os_setAllocationStrategy(Heap *heap, AllocStrategy allocStrat) {
    // TODO implement.
}

/*!
 * Simple getter function to fetch the allocation strategy of a given heap Returns The allocation
 * strategy of the given heap
 *
 * @param heap     The heap of which the allocation strategy is returned
 */
AllocStrategy os_getAllocationStrategy(const Heap *heap) {
    // TODO implement.
}

/*!
 * This function realises the garbage collection. When called, every allocated memory chunk of the
 * given process is freed
 *
 * @param heap     The heap on which we look for allocated memory
 * @param pid      The ProcessID of the process that owns all the memory to be freed
 */
void os_freeProcessMemory(Heap *heap, ProcessID pid) {
    // TODO implement.
}
