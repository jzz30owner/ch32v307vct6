#include "afio.h"

#include <inttypes.h>

#include "rcc.h"

void enable_afioen() {
  RCC->APB2ENR |= (1 << 1);
}

