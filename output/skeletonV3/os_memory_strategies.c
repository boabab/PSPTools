/*! \file
 *
 * Memory strategies used by the malloc function of os_memory to allocate blocks on the memory. The
 * file contains four strategies: -First-Fit -Next-Fit -Best-Fit -Worst-Fit
 *
 */

#include "os_memory_strategies.h"
#include "os_memory.h"

//----------------------------------------------------------------------------
// Functions
//----------------------------------------------------------------------------

/*!
 * First-fit strategy. Returns The first address of the found free chunk, or 0 if no chunk was
 * found.
 *
 * @param heap     The heap in which we want to find a free chunk
 * @param size     The size of the desired free chunk
 */
MemAddr os_Memory_FirstFit(Heap * heap , size_t size) {
    // TODO implement.
}

/*!
 * Next-fit strategy. Returns The first address of the found free chunk. Returns 0, if no chunk was
 * found.
 *
 * @param heap     The heap in which we want to find a free chunk
 * @param size     The size of the desired free chunk
 */
MemAddr os_Memory_NextFit(Heap * heap , size_t size) {
    // TODO implement.
}

/*!
 * Worst-fit strategy. Returns The first address of the found free chunk. Returns 0, if no chunk was
 * found.
 *
 * @param heap     The heap in which we want to find a free chunk
 * @param size     The size of the desired free chunk
 */
MemAddr os_Memory_WorstFit(Heap * heap , size_t size) {
    // TODO implement.
}

/*!
 * Best-fit strategy. Returns The first address of the found free chunk. Returns 0, if no chunk was
 * found.
 *
 * @param heap     The heap in which we want to find a free chunk
 * @param size     The size of the desired free chunk
 */
MemAddr os_Memory_BestFit(Heap * heap , size_t size) {
    // TODO implement.
}
