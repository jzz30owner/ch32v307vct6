#include "gpio.h"
#include <inttypes.h>
#include "rcc.h"


void enable_gpioa() {
  RCC_APB2EN |= (1 << 2);
}

void enable_gpiob() {
  RCC_APB2EN |= (1 << 3);
}
