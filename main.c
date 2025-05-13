/*
*
* Just blink LED0 and write bytes to PA15
*
*
*
*
*/
#include "ch32v307.h"
#include "timers.h"
#include <string.h>

#define RCC_AHBPeriph_ETH_MAC            ((uint32_t)0x00004000)
#define RCC_AHBPeriph_ETH_MAC_Tx         ((uint32_t)0x00008000)
#define RCC_AHBPeriph_ETH_MAC_Rx         ((uint32_t)0x00010000)


void main(void) {
  enable_afioen();
  tim2_init();
  enable_gpioa();

  RCC->AHBENR &= ~(RCC_AHBPeriph_ETH_MAC | RCC_AHBPeriph_ETH_MAC_Tx | RCC_AHBPeriph_ETH_MAC_Rx);

  // Disable JTAG/SWD so PA15 can be used
  AFIO_PCFR1 |= (0b100 << 24); // Full disable: SWJ_CFG = 0b100

  // Configure PA15: push-pull output, 2 MHz
  GPIOA_CRH &= ~(0xF << 28); // clear
  GPIOA_CRH |=  (0x2 << 28); // MODE = 10, CNF = 00

  // Configure PA5 (A5) as push-pull output, 2MHz
  GPIOA_CRL &= ~(0xF << 20);
  GPIOA_CRL |=  (0x2 << 20);

  while (1) {
      led1_toggle();
      GPIOA_ODR ^= (1 << 5);
      delay_ms(1000);
  }
}

__attribute__((naked, section(".init"))) void _start(void) {
    main();
    while (1);
}

