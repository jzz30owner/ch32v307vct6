#include "gpio.h"

#include <inttypes.h>
#include "rcc.h"


void enable_gpioa() {
  RCC->APB2ENR |= (1 << 2);
}

void enable_gpiob() {
  RCC->APB2ENR |= (1 << 3);
}
