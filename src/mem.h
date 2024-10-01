#pragma once
#include <stdint.h>

enum mem_tags {
  E_ZERO_PAGE = 0,
  E_STACK
};

typedef struct mem_region {
  uint8_t tag;
  uint8_t *buf;
  uint16_t len;
  uint16_t offset;
} mem_region_t;

#define ZERO_PAGE_SIZE 256
#define ZERO_PAGE_OFFSET 0
extern uint8_t g_zero_page[ZERO_PAGE_SIZE];
#define STACK_SIZE 256
#define STACK_OFFSET 0x0100
extern uint8_t g_stack[STACK_SIZE];

typedef struct mos_registers {
} mos_registers_t;
