#pragma once

#include "mem_mapping.h"


// Ports
// CTL -> control register. Each pin uses 4 bits (2 for mode, 2 for configuration).
#define GPIOA_CRL       (*((volatile uint32_t *)(PA + 0x00))) // Control low (PA0–PA7)
#define GPIOA_CRH       (*((volatile uint32_t *)(PA + 0x04))) // Control high (PA8–PA15)
#define GPIOA_IDR       (*((volatile uint32_t *)(PA + 0x08))) // Input data
#define GPIOA_ODR       (*((volatile uint32_t *)(PA + 0x0C))) // Output data

#define GPIOB_CRL       (*((volatile uint32_t *)(PB + 0x00))) // Control low (PB0–PB7)
#define GPIOB_CRH       (*((volatile uint32_t *)(PB + 0x04))) // Control high (PB8–PB15)
#define GPIOB_IDR       (*((volatile uint32_t *)(PB + 0x08))) // Input data
#define GPIOB_ODR       (*((volatile uint32_t *)(PB + 0x0C))) // Output data

#define GPIOC_CRL       (*((volatile uint32_t *)(PC + 0x00))) // Control low (PC0–PC7)
#define GPIOC_CRH       (*((volatile uint32_t *)(PC + 0x04))) // Control high (PC8–PC15)
#define GPIOC_IDR       (*((volatile uint32_t *)(PC + 0x08))) // Input data
#define GPIOC_ODR       (*((volatile uint32_t *)(PC + 0x0C))) // Output data

void enable_gpioa();
void enable_gpiob();

