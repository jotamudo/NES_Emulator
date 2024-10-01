#pragma once
#include <stdint.h>

typedef struct mos_opcodes {
  uint8_t code;
  uint8_t num_operands;
} mos_opcodes_t;
