#ifndef _PMM_H_
#define _PMM_H_
#include "util/types.h"
// Initialize phisical memeory manager
void pmm_init();
// Allocate a free phisical page
void* alloc_page();
// Free an allocated page
void free_page(void* pa);

/** self realization **/
typedef struct memory_descriptor_t { 
    uint64 start_pa;
    // uint64 start_va;
    uint64 size;
    uint64 page_start_pa;
    uint64 page_start_va;
    struct memory_descriptor_t *next;
    // when a malloc cross page, succ points to the next md (in another page)
    struct memory_descriptor_t *succ;
} memory_descriptor;

// Function to allocate a memory descriptor
// Returns a pointer to the allocated memory descriptor
memory_descriptor *alloc_memory_descriptor();
// Function to free a memory descriptor
// Takes a pointer to the memory descriptor to be freed
void free_memory_descriptor(memory_descriptor *md);


void insert_into_md_list(memory_descriptor **head, memory_descriptor *md, int merge);
void remove_from_md_list(memory_descriptor **head, memory_descriptor *md);
void remove_core_from_list(memory_descriptor **head, memory_descriptor *md);
int get_page_id_by_start_pa(uint64 pa);
int get_page_id_by_start_pa_plus(uint64 pa);
/** end **/

#endif