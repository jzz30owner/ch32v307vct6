#include "ch32v307.h"


void led1_toggle() {
  GPIOA_ODR ^= (1 << 15); 
}


