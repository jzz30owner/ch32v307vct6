#include "ch32v307.h"


void led1_toggle() {
  GPIOA_ODR ^= (1 << 15); 
}

void enable_afioen() {
  RCC_APB2EN |= (1 << 1);
}

void enable_gpioa() {
  RCC_APB2EN |= (1 << 2);
}

void enable_gpiob() {
  RCC_APB2EN |= (1 << 3);
}



