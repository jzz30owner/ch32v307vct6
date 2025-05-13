#include "afio.h"

#include <inttypes.h>

#include "rcc.h"

void enable_afioen() {
  RCC_APB2EN |= (1 << 1);
}

