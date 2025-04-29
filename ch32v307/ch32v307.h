#include <inttypes.h>

#define PHY_ADDRESS   0x01 
#define DVP           0x50050000
#define USBFS         0x50000000
#define ETH_BASE      0x40028000
#define TRNG          0x40023C00 
#define EXTEND        0x40023800
#define USBHS         0x40023400         
#define CRC           0x40023000
#define FLASH_INTER   0x40022000
#define RCC           0x40021000
#define DMA2          0x40020400
#define DMA1          0x40020000
#define SDIO          0x40018000
#define TIM10         0x40015000
#define TIM9          0x40014C00
#define USART1        0x40013800
#define TIM8          0x40013400
#define SPI1          0x40013000
#define TIM1          0x40012C00
#define ADC2          0x40012800
#define ADC1          0x40012400
// Ports
#define PE            0x40011800
#define PD            0x40011400
#define PC            0x40011000
#define PB            0x40010C00
#define PA            0x40010800
#define GPIOE         PE
#define GPIOD         PD
#define GPIOC         PC
#define GPIOB         PB
#define GPIOA         PA

#define EXTI          0x40010400
#define AFIO          0x40010000
#define DAC           0x40007400
#define PWR           0x40007000
#define BKP           0x40006c00

#define CAN2          0x40006800
#define CAN1          0x40006400

#define SH512_SRAM    0x40006000
#define I2C2          0x40005800
#define I2C1          0x40005400
#define UART5         0x40005000
#define UART4         0x40004C00
#define UART3         0x40004800
#define UART2         0x40004400
#define SPI3          0x40003C00
#define SPI2          0x40003800
#define I2S3          SPI3
#define I2S2          SPI2
#define IWDG          0x40003000
#define WWDG          0x40002C00
#define RTC           0x40002800
#define UART8         0x40002000
#define UART7         0x40001C00
#define UART6         0x40001800

#define TIM7          0x40001400
#define TIM6          0x40001000
#define TIM5          0x40000C00
#define TIM4          0x40000800
#define TIM3          0x40000400
#define TIM2          0x40000000

#define FLASH         0x08000000
#define CODE_FLASH    FLASH
#define SYS_FLASH     0x1FFF8000
#define SRAM          0x20000000
#define PHY           0x40000000
#define VENDOR_BYTES  0x1FFFF700
#define OPTION_BYTES  0x1FFFF800
#define PSRAM1        0x60000000
#define NAND1         0x70000000
#define FSMC          0xA0000000
#define CORE_PPHY     0xE0000000

#define RCC_CTL         (*((volatile uint32_t *)(RCC + 0x00))) // Control register
#define RCC_CFG0        (*((volatile uint32_t *)(RCC + 0x04))) // Clock config

/*
 * RCC_APB2ENR: A 32-bit register where each bit enables the clock for a specific APB2 peripheral:
 * Bit 0: AFIOEN (AFIO clock). 
 * Bit 2: GPIOAEN (GPIOA clock).
 * Bit 3: GPIOBEN (GPIOB clock).
 * Bit 4: GPIOCEN, etc.
*/
#define RCC_APB2EN      (*((volatile uint32_t *)(RCC + 0x18))) // APB2 enable
                                                               //
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

/**
 * @brief AFIO_PCFR1 - Alternate Function Input/Output Port Configuration Register 1
 *
 * @details This 32-bit register configures remapping of peripheral functions to alternate
 * GPIO pins and other alternate function settings on the GD32VF103. It is located at
 * address 0x40010004 (AFIO base + 0x04). The AFIO clock must be enabled via RCC_APB2ENR
 * (bit 0) before accessing this register. After remapping, GPIO pins must be configured
 * as alternate function mode (e.g., CNF = 10 or 11 in GPIOx_CRL/CRH).
 *
 * @note Not all features (e.g., Ethernet, CAN2) are available on all GD32VF103 models.
 * Always consult the MCU datasheet for supported remappings and bit assignments.
 *
 * Bit fields:
 * - Bit 0  : SPI1RM
 *   - Description: SPI1 remapping
 *   - Values:
 *     - 0: No remap (PA4/PA5/PA6/PA7)
 *     - 1: Remap (PB3/PB4/PB5/PA15)
 * - Bit 1  : I2C1RM
 *   - Description: I2C1 remapping
 *   - Values:
 *     - 0: No remap (PB6/PB7)
 *     - 1: Remap (PB8/PB9)
 * - Bit 2  : USART1RM
 *   - Description: USART1 remapping
 *   - Values:
 *     - 0: No remap (PA9/PA10)
 *     - 1: Remap (PB6/PB7)
 * - Bit 3  : USART2RM
 *   - Description: USART2 remapping
 *   - Values:
 *     - 0: No remap (PA2/PA3)
 *     - 1: Remap (PD5/PD6)
 * - Bit 4  : USART3RM (partial)
 *   - Description: USART3 remapping (partial)
 *   - Values:
 *     - 0: No remap (PB10/PB11)
 *     - 1: Remap (PC10/PC11)
 * - Bits 5-6: USART3RM (full)
 *   - Description: USART3 remapping (full)
 *   - Values:
 *     - 00: No remap
 *     - 01: Partial remap (set by bit 4)
 *     - 10: Full remap (PD8/PD9)
 * - Bit 7  : TIM1RM
 *   - Description: TIM1 remapping
 *   - Values:
 *     - 0: No remap (PA8/PA9/PA10/PA11)
 *     - 1: Remap (PE9/PE11/PE13/PE14)
 * - Bit 8  : TIM2RM (partial)
 *   - Description: TIM2 remapping (partial)
 *   - Values:
 *     - 0: No remap (PA0/PA1/PA2/PA3)
 *     - 1: Remap (PA15/PB3/PA2/PA3)
 * - Bits 9-10: TIM2RM (full)
 *   - Description: TIM2 remapping (full)
 *   - Values:
 *     - 00: No remap
 *     - 01: Partial remap (set by bit 8)
 *     - 10: Full remap (PA15/PB3/PB10/PB11)
 * - Bit 11 : TIM3RM (partial)
 *   - Description: TIM3 remapping (partial)
 *   - Values:
 *     - 0: No remap (PA6/PA7/PB0/PB1)
 *     - 1: Remap (PB4/PB5/PB0/PB1)
 * - Bits 12-13: TIM3RM (full)
 *   - Description: TIM3 remapping (full)
 *   - Values:
 *     - 00: No remap
 *     - 01: Partial remap (set by bit 11)
 *     - 10: Full remap (PC6/PC7/PC8/PC9)
 * - Bit 14 : TIM4RM
 *   - Description: TIM4 remapping
 *   - Values:
 *     - 0: No remap (PB6/PB7/PB8/PB9)
 *     - 1: Remap (PD12/PD13/PD14/PD15)
 * - Bit 15 : CANRM
 *   - Description: CAN remapping
 *   - Values:
 *     - 0: No remap (PA11/PA12)
 *     - 1: Remap (PB8/PB9)
 * - Bit 16 : PD01RM
 *   - Description: Port D0/D1 remapping (for oscillators)
 *   - Values:
 *     - 0: No remap (PD0/PD1)
 *     - 1: Remap (PD0/PD1 as OSC_IN/OSC_OUT)
 * - Bit 17 : TIM5CH4RM
 *   - Description: TIM5 channel 4 remapping
 *   - Values:
 *     - 0: No remap (PA3)
 *     - 1: Remap (internal LSI clock)
 * - Bit 18 : ADC1_ETRG_INJ
 *   - Description: ADC1 external trigger injected conversion remapping
 *   - Values:
 *     - 0: No remap
 *     - 1: Remap
 * - Bit 19 : ADC1_ETRG_REG
 *   - Description: ADC1 external trigger regular conversion remapping
 *   - Values:
 *     - 0: No remap
 *     - 1: Remap
 * - Bit 20 : ADC2_ETRG_INJ
 *   - Description: ADC2 external trigger injected conversion remapping
 *   - Values:
 *     - 0: No remap
 *     - 1: Remap
 * - Bit 21 : ADC2_ETRG_REG
 *   - Description: ADC2 external trigger regular conversion remapping
 *   - Values:
 *     - 0: No remap
 *     - 1: Remap
 * - Bit 22 : ETHRM
 *   - Description: Ethernet remapping (if supported)
 *   - Values:
 *     - 0: No remap
 *     - 1: Remap
 * - Bit 23 : CAN2RM
 *   - Description: CAN2 remapping
 *   - Values:
 *     - 0: No remap
 *     - 1: Remap
 * - Bit 24 : SWJCFG
 *   - Description: Serial Wire JTAG configuration (partial disable)
 *   - Values:
 *     - 0: Full SWJ
 *     - 1: Partial disable (e.g., JTAG-DP disabled)
 * - Bits 25-26: SWJCFG
 *   - Description: Serial Wire JTAG configuration (full/partial disable)
 *   - Values:
 *     - 00: Full SWJ
 *     - 01: JTAG-DP disabled
 *     - 10: SW-DP only
 * - Bit 27 : SPI3RM
 *   - Description: SPI3 remapping (if supported)
 *   - Values:
 *     - 0: No remap
 *     - 1: Remap
 * - Bit 28 : TIM2ITR1RM
 *   - Description: TIM2 internal trigger 1 remapping
 *   - Values:
 *     - 0: No remap
 *     - 1: Remap
 * - Bit 29 : PTP_PPSRM
 *   - Description: PTP PPS remapping (for Ethernet)
 *   - Values:
 *     - 0: No remap
 *     - 1: Remap
 */
#define AFIO_PCFR1      (*((volatile uint32_t *)(AFIO + 0x04))) // Port config 1

/**
 * @brief AFIO_EXTICR1 - Alternate Function Input/Output External Interrupt Configuration Register 1
 *
 * @details This 32-bit register configures the GPIO port source for external interrupt lines
 * EXTI0 to EXTI3 on the GD32VF103. It is located at address 0x40010008 (AFIO base + 0x08).
 * Each EXTI line (EXTI0–EXTI3) is mapped to a pin from a selected GPIO port (e.g., PA0, PB0 for EXTI0).
 * The AFIO clock must be enabled via RCC_APB2ENR (bit 0), and the relevant GPIO port clock
 * (e.g., GPIOA via RCC_APB2ENR bit 2) must be enabled before accessing this register. The selected
 * GPIO pin must be configured as an input (e.g., MODE=00, CNF=01 for floating input in GPIOx_CRL).
 * The EXTI peripheral and NVIC must also be configured for interrupt handling.
 *
 * @note Not all GPIO ports (e.g., PFx, PGx) are available on all GD32VF103 models. Consult the
 * MCU datasheet for supported ports. Only one pin per EXTI line can be active at a time
 * (e.g., PA0 or PB0 for EXTI0, not both).
 *
 * Bit fields:
 * - Bits 3:0  : EXTI0
 *   - Description: Selects GPIO port for EXTI0 interrupt
 *   - Values:
 *     - 0x0: PAx (e.g., PA0 for EXTI0)
 *     - 0x1: PBx (e.g., PB0 for EXTI0)
 *     - 0x2: PCx (e.g., PC0 for EXTI0)
 *     - 0x3: PDx (e.g., PD0 for EXTI0)
 *     - 0x4: PEx (e.g., PE0 for EXTI0)
 *     - 0x5: PFx (e.g., PF0 for EXTI0, if available)
 *     - 0x6: PGx (e.g., PG0 for EXTI0, if available)
 *     - 0x7: PHx (e.g., PH0 for EXTI0, if available)
 *     - Others: Reserved
 * - Bits 7:4  : EXTI1
 *   - Description: Selects GPIO port for EXTI1 interrupt
 *   - Values: Same as EXTI0 (e.g., 0x0 for PA1, 0x1 for PB1, etc.)
 * - Bits 11:8 : EXTI2
 *   - Description: Selects GPIO port for EXTI2 interrupt
 *   - Values: Same as EXTI0 (e.g., 0x0 for PA2, 0x1 for PB2, etc.)
 * - Bits 15:12 : EXTI3
 *   - Description: Selects GPIO port for EXTI3 interrupt
 *   - Values: Same as EXTI0 (e.g., 0x0 for PA3, 0x1 for PB3, etc.)
 * - Bits 31:16 : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 */
#define AFIO_EXTICR1    (*((volatile uint32_t *)(AFIO + 0x08))) // EXTI config 1

#define EXTI_IMR        (*((volatile uint32_t *)(EXTI + 0x00))) // Interrupt mask
#define EXTI_RTSR       (*((volatile uint32_t *)(EXTI + 0x08))) // Rising trigger


void led1_toggle();

void enable_afioen();
void enable_gpioa();
void enable_gpiob();
