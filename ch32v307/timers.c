#include "timers.h"
#include <stdint.h>

#define TIM2_PSC      (*((volatile uint32_t *)(TIM2 + 0x28)))
#define TIM2_ARR      (*((volatile uint32_t *)(TIM2 + 0x2C)))
#define TIM2_CNT      (*((volatile uint32_t *)(TIM2 + 0x24)))
#define TIM2_CR1      (*(volatile uint32_t *)TIM2)

void tim2_init() {
  RCC_APB1ENR |= (1 << 0); // Enable TIM2 ticks
  TIM2_PSC = 71999;        // Devide: 72_000_000 / (71999+1) = 1_000 HZ
  TIM2_ARR = 0xFFFF;       // Reloading
  TIM2_CNT = 0;            // Reset timer
  TIM2_CR1 |= (1 << 0);    // Enable timer (CEN)
}

void delay_ms(uint32_t ms) {
  unsigned int start = TIM2_CNT;
  while ((unsigned int)(TIM2_CNT - start) < ms);
}

