#pragma once

#include <inttypes.h>

#include "mem_mapping.h"
#include "ch32v307_core.h"
#include "rcc.h"
#include "gpio.h"
#include "afio.h"


#define EXTI_IMR        (*((volatile uint32_t *)(EXTI + 0x00))) // Interrupt mask
#define EXTI_RTSR       (*((volatile uint32_t *)(EXTI + 0x08))) // Rising trigger


void led1_toggle();

