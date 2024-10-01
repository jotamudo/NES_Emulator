#include "mem.h"

uint8_t g_zero_page[ZERO_PAGE_SIZE];
uint8_t g_stack[STACK_SIZE];

mem_region_t mem_regions[] = {
  {.tag = E_ZERO_PAGE, .buf = g_zero_page, .len = ZERO_PAGE_SIZE, .offset = ZERO_PAGE_OFFSET},
  {.tag = E_STACK, .buf = g_stack, .len = STACK_SIZE, .offset = STACK_OFFSET}
};
