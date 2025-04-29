#include "timers.h"

#define TIM2_PSC     (*(volatile unsigned long *)0x40000028)
#define TIM2_ARR     (*(volatile unsigned long *)0x4000002C)
#define TIM2_CNT     (*(volatile unsigned long *)0x40000024)
#define TIM2_CR1     (*(volatile unsigned long *)0x40000000)
#define TIM2_SR      (*(volatile unsigned long *)0x40000010)

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

