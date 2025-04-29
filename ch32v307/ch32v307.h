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

/**
 * @brief RCC_CR - Reset and Clock Control Clock Control Register
 *
 * @details This 32-bit read-write register controls the enabling and monitoring of
 * clock sources on the CH32V307, located at address 0x40021000 (RCC base + 0x00).
 * It enables/disables the High-Speed Internal (HSI) oscillator, High-Speed External
 * (HSE) oscillator, and Phase-Locked Loop (PLL), and manages clock security and HSI
 * calibration. Clock sources must be enabled and stable before selection in RCC_CFGR
 * for system clock (SYSCLK) or peripheral use. A stable power supply is required, and
 * for HSE, an external crystal/oscillator (4–32 MHz, typically 8 MHz) must be connected
 * to OSC_IN/OSC_OUT pins. Peripheral clocks must be enabled via RCC_APB1ENR or
 * RCC_APB2ENR after clock source setup.
 *
 * @note The CH32V307 supports HSI (8 MHz), HSE (4–32 MHz), and PLL as clock sources.
 * Check readiness flags (e.g., HSIRDY, HSERDY, PLLRDY) before switching clocks in
 * RCC_CFGR. The clock security system (CSS) monitors HSE failures. HSI calibration
 * adjusts frequency accuracy. Consult the CH32V307 datasheet and reference manual
 * for clock configuration details.
 *
 * Bit fields:
 * - Bits 31:26 : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 25     : PLLRDY
 *   - Description: PLL clock ready flag (read-only)
 *   - Values:
 *     - 0: PLL not ready
 *     - 1: PLL locked and ready
 * - Bit 24     : PLLON
 *   - Description: PLL enable
 *   - Values:
 *     - 0: PLL disabled
 *     - 1: PLL enabled
 * - Bits 23:20 : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 19     : CSSON
 *   - Description: Clock security system enable
 *   - Values:
 *     - 0: CSS disabled
 *     - 1: CSS enabled (monitors HSE failure)
 * - Bit 18     : HSEBYP
 *   - Description: HSE bypass
 *   - Values:
 *     - 0: HSE oscillator not bypassed
 *     - 1: HSE oscillator bypassed (external clock input)
 * - Bit 17     : HSERDY
 *   - Description: HSE clock ready flag (read-only)
 *   - Values:
 *     - 0: HSE not ready
 *     - 1: HSE ready
 * - Bit 16     : HSEON
 *   - Description: HSE enable
 *   - Values:
 *     - 0: HSE disabled
 *     - 1: HSE enabled
 * - Bits 15:8  : HSICAL
 *   - Description: HSI calibration value (read-only)
 *   - Values:
 *     - 0x00–0xFF: Factory-calibrated HSI value
 * - Bits 7:3   : HSITRIM
 *   - Description: HSI trimming
 *   - Values:
 *     - 0x00–0x1F: Trim HSI frequency (default 0x10, ±40 kHz per step)
 * - Bit 2      : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 1      : HSIRDY
 *   - Description: HSI clock ready flag (read-only)
 *   - Values:
 *     - 0: HSI not ready
 *     - 1: HSI ready
 * - Bit 0      : HSION
 *   - Description: HSI enable
 *   - Values:
 *     - 0: HSI disabled
 *     - 1: HSI enabled
 */
#define RCC_CTL         (*((volatile uint32_t *)(RCC + 0x00))) // Control register
                                                               //
#define RCC_CFG0        (*((volatile uint32_t *)(RCC + 0x04))) // Clock config

/**
 * @brief RCC_CFGR - Reset and Clock Control Configuration Register
 *
 * @details This 32-bit read-write register configures the clock system of the CH32V307,
 * located at address 0x40021008 (RCC base + 0x08). It selects the system clock source
 * (SYSCLK), configures the PLL source and multiplier, and sets prescalers for the AHB,
 * APB1, and APB2 buses. It also configures the MCO pin for clock output. The desired
 * clock sources (e.g., HSI, HSE) must be enabled and stable via RCC_CR before switching.
 * Peripheral clocks must be enabled via RCC_APB1ENR or RCC_APB2ENR after setting
 * prescalers. This register is critical for ensuring peripherals like EMAC, GPIO, and
 * UART operate at the correct frequency.
 *
 * @note The CH32V307 supports HSI (8 MHz), HSE (4–32 MHz), and PLL as clock sources.
 * Ensure clock stability (e.g., HSERDY in RCC_CR) before switching SYSCLK. The APB1
 * clock must not exceed 36 MHz in some configurations. The MCO pin (PA8) requires
 * GPIOA clock enable and configuration. Consult the CH32V307 datasheet and reference
 * manual for clock configuration details.
 *
 * Bit fields:
 * - Bits 31:27 : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bits 26:24 : MCO
 *   - Description: Microcontroller clock output
 *   - Values:
 *     - 0x0: No clock output
 *     - 0x4: SYSCLK output
 *     - 0x5: HSI output
 *     - 0x6: HSE output
 *     - 0x7: PLL clock divided by 2 output
 *     - Others: Reserved
 * - Bits 23:22 : PLLMUL
 *   - Description: PLL multiplication factor
 *   - Values:
 *     - 0x0: PLL x2
 *     - 0x1: PLL x3
 *     - 0x2: PLL x4
 *     - ...
 *     - 0xF: PLL x16
 * - Bit 21     : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 20     : OTGFSPRE
 *   - Description: USB OTG FS prescaler
 *   - Values:
 *     - 0: USB OTG FS clock = PLLCLK / 1.5
 *     - 1: USB OTG FS clock = PLLCLK
 * - Bits 19:18 : PLLXTPRE
 *   - Description: HSE divider for PLL entry
 *   - Values:
 *     - 0: HSE not divided (PLL input = HSE)
 *     - 1: HSE divided by 2 (PLL input = HSE/2)
 * - Bit 17     : PLLSRC
 *   - Description: PLL clock source
 *   - Values:
 *     - 0: HSI/2
 *     - 1: HSE
 * - Bit 16     : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bits 15:14 : ADCPRE
 *   - Description: ADC prescaler
 *   - Values:
 *     - 0x0: PCLK2 divided by 2
 *     - 0x1: PCLK2 divided by 4
 *     - 0x2: PCLK2 divided by 6
 *     - 0x3: PCLK2 divided by 8
 * - Bits 13:11 : PPRE2
 *   - Description: APB2 prescaler (high-speed APB)
 *   - Values:
 *     - 0x0: HCLK not divided
 *     - 0x4: HCLK divided by 2
 *     - 0x5: HCLK divided by 4
 *     - 0x6: HCLK divided by 8
 *     - 0x7: HCLK divided by 16
 * - Bits 10:8  : PPRE1
 *   - Description: APB1 prescaler (low-speed APB)
 *   - Values:
 *     - 0x0: HCLK not divided
 *     - 0x4: HCLK divided by 2
 *     - 0x5: HCLK divided by 4
 *     - 0x6: HCLK divided by 8
 *     - 0x7: HCLK divided by 16
 * - Bits 7:4   : HPRE
 *   - Description: AHB prescaler
 *   - Values:
 *     - 0x0: SYSCLK not divided
 *     - 0x8: SYSCLK divided by 2
 *     - 0x9: SYSCLK divided by 4
 *     - 0xA: SYSCLK divided by 8
 *     - 0xB: SYSCLK divided by 16
 *     - 0xC: SYSCLK divided by 64
 *     - 0xD: SYSCLK divided by 128
 *     - 0xE: SYSCLK divided by 256
 *     - 0xF: SYSCLK divided by 512
 * - Bits 3:2   : SWS
 *   - Description: System clock switch status (read-only)
 *   - Values:
 *     - 0x0: HSI selected
 *     - 0x1: HSE selected
 *     - 0x2: PLL selected
 *     - 0x3: Reserved
 * - Bits 1:0   : SW
 *   - Description: System clock switch
 *   - Values:
 *     - 0x0: HSI selected
 *     - 0x1: HSE selected
 *     - 0x2: PLL selected
 *     - 0x3: Reserved
 */
#define RCC_CFGR        (*((volatile uint32_t *)(RCC + 0x08))) // Clock config

/**
 * @brief RCC_APB2ENR - Reset and Clock Control APB2 Enable Register
 *
 * @details This 32-bit read-write register enables or disables clock signals for
 * peripherals on the APB2 bus of the CH32V307, located at address 0x40021018
 * (RCC base + 0x18). Setting a bit to 1 enables the clock for the corresponding
 * peripheral, allowing it to operate, while setting it to 0 disables the clock to
 * save power. Peripherals include timers (TIM1, TIM8), USART1, ADCs (ADC1–ADC2),
 * SPI1, GPIOs (GPIOA–GPIOE), AFIO, and EMAC. The system clock must be configured
 * via RCC_CR and RCC_CFGR, and the APB2 prescaler must be set in RCC_CFGR
 * (bits 13:11) to define the APB2 clock frequency.
 *
 * @note The CH32V307 supports high-speed APB2 peripherals for critical functions
 * like Ethernet (EMAC) and GPIO configuration. Ensure the APB2 clock frequency is
 * appropriate for the peripheral's requirements. Disabling unused peripheral clocks
 * reduces power consumption. Consult the CH32V307 datasheet and reference manual
 * for clock configuration and peripheral initialization details.
 *
 * Bit fields:
 * - Bits 31:15 : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 14     : EMACEN
 *   - Description: Ethernet MAC clock enable
 *   - Values:
 *     - 0: EMAC clock disabled
 *     - 1: EMAC clock enabled
 * - Bit 13     : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 12     : ADC2EN
 *   - Description: ADC2 clock enable
 *   - Values:
 *     - 0: ADC2 clock disabled
 *     - 1: ADC2 clock enabled
 * - Bit 11     : ADC1EN
 *   - Description: ADC1 clock enable
 *   - Values:
 *     - 0: ADC1 clock disabled
 *     - 1: ADC1 clock enabled
 * - Bit 10     : USART1EN
 *   - Description: USART1 clock enable
 *   - Values:
 *     - 0: USART1 clock disabled
 *     - 1: USART1 clock enabled
 * - Bit 9      : TIM8EN
 *   - Description: TIM8 clock enable
 *   - Values:
 *     - 0: TIM8 clock disabled
 *     - 1: TIM8 clock enabled
 * - Bit 8      : SPI1EN
 *   - Description: SPI1 clock enable
 *   - Values:
 *     - 0: SPI1 clock disabled
 *     - 1: SPI1 clock enabled
 * - Bit 7      : TIM1EN
 *   - Description: TIM1 clock enable
 *   - Values:
 *     - 0: TIM1 clock disabled
 *     - 1: TIM1 clock enabled
 * - Bit 6      : GPIOEEN
 *   - Description: GPIOE clock enable
 *   - Values:
 *     - 0: GPIOE clock disabled
 *     - 1: GPIOE clock enabled
 * - Bit 5      : GPIODEN
 *   - Description: GPIOD clock enable
 *   - Values:
 *     - 0: GPIOD clock disabled
 *     - 1: GPIOD clock enabled
 * - Bit 4      : GPIOCEN
 *   - Description: GPIOC clock enable
 *   - Values:
 *     - 0: GPIOC clock disabled
 *     - 1: GPIOC clock enabled
 * - Bit 3      : GPIOBEN
 *   - Description: GPIOB clock enable
 *   - Values:
 *     - 0: GPIOB clock disabled
 *     - 1: GPIOB clock enabled
 * - Bit 2      : GPIOAEN
 *   - Description: GPIOA clock enable
 *   - Values:
 *     - 0: GPIOA clock disabled
 *     - 1: GPIOA clock enabled
 * - Bit 1      : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 0      : AFIOEN
 *   - Description: Alternate function I/O clock enable
 *   - Values:
 *     - 0: AFIO clock disabled
 *     - 1: AFIO clock enabled
 */

#define RCC_APB2EN      (*((volatile uint32_t *)(RCC + 0x18))) // APB2 enable
/**
 * @brief RCC_APB1ENR - Reset and Clock Control APB1 Enable Register
 *
 * @details This 32-bit read-write register enables or disables clock signals for
 * peripherals on the APB1 bus of the CH32V307, located at address 0x4002101C
 * (RCC base + 0x1C). Setting a bit to 1 enables the clock for the corresponding
 * peripheral, allowing it to operate, while setting it to 0 disables the clock to
 * save power. Peripherals include timers (TIM2–TIM7), UARTs (UART2–UART5),
 * I2C1–I2C2, SPI2–SPI3, CAN, USB, and others. The system clock must be configured
 * via RCC_CR and RCC_CFGR, and the APB1 prescaler must be set in RCC_CFGR
 * (bits 10:8) to define the APB1 clock frequency. Some peripherals (e.g., USB,
 * backup domain) may require additional power domain configuration.
 *
 * @note The CH32V307 supports a variety of APB1 peripherals for low-speed operations.
 * Ensure the APB1 clock frequency is appropriate for the peripheral's requirements.
 * Disabling unused peripheral clocks reduces power consumption. Consult the
 * CH32V307 datasheet and reference manual for clock configuration and peripheral
 * initialization details.
 *
 * Bit fields:
 * - Bits 31:30 : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 29     : PWREN
 *   - Description: Power interface clock enable
 *   - Values:
 *     - 0: Power interface clock disabled
 *     - 1: Power interface clock enabled
 * - Bit 28     : BKPEN
 *   - Description: Backup interface clock enable
 *   - Values:
 *     - 0: Backup interface clock disabled
 *     - 1: Backup interface clock enabled
 * - Bits 27:26 : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 25     : CANEN
 *   - Description: CAN clock enable
 *   - Values:
 *     - 0: CAN clock disabled
 *     - 1: CAN clock enabled
 * - Bit 24     : USBEN
 *   - Description: USB clock enable
 *   - Values:
 *     - 0: USB clock disabled
 *     - 1: USB clock enabled
 * - Bit 23     : I2C2EN
 *   - Description: I2C2 clock enable
 *   - Values:
 *     - 0: I2C2 clock disabled
 *     - 1: I2C2 clock enabled
 * - Bit 22     : I2C1EN
 *   - Description: I2C1 clock enable
 *   - Values:
 *     - 0: I2C1 clock disabled
 *     - 1: I2C1 clock enabled
 * - Bit 21     : UART5EN
 *   - Description: UART5 clock enable
 *   - Values:
 *     - 0: UART5 clock disabled
 *     - 1: UART5 clock enabled
 * - Bit 20     : UART4EN
 *   - Description: UART4 clock enable
 *   - Values:
 *     - 0: UART4 clock disabled
 *     - 1: UART4 clock enabled
 * - Bit 19     : UART3EN
 *   - Description: UART3 clock enable
 *   - Values:
 *     - 0: UART3 clock disabled
 *     - 1: UART3 clock enabled
 * - Bit 18     : UART2EN
 *   - Description: UART2 clock enable
 *   - Values:
 *     - 0: UART2 clock disabled
 *     - 1: UART2 clock enabled
 * - Bit 17     : SPI3EN
 *   - Description: SPI3 clock enable
 *   - Values:
 *     - 0: SPI3 clock disabled
 *     - 1: SPI3 clock enabled
 * - Bit 16     : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 15     : SPI2EN
 *   - Description: SPI2 clock enable
 *   - Values:
 *     - 0: SPI2 clock disabled
 *     - 1: SPI2 clock enabled
 * - Bits 14:11 : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 10     : DACEN
 *   - Description: DAC clock enable
 *   - Values:
 *     - 0: DAC clock disabled
 *     - 1: DAC clock enabled
 * - Bits 9:6   : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 5      : TIM7EN
 *   - Description: TIM7 clock enable
 *   - Values:
 *     - 0: TIM7 clock disabled
 *     - 1: TIM7 clock enabled
 * - Bit 4      : TIM6EN
 *   - Description: TIM6 clock enable
 *   - Values:
 *     - 0: TIM6 clock disabled
 *     - 1: TIM6 clock enabled
 * - Bit 3      : TIM5EN
 *   - Description: TIM5 clock enable
 *   - Values:
 *     - 0: TIM5 clock disabled
 *     - 1: TIM5 clock enabled
 * - Bit 2      : TIM4EN
 *   - Description: TIM4 clock enable
 *   - Values:
 *     - 0: TIM4 clock disabled
 *     - 1: TIM4 clock enabled
 * - Bit 1      : TIM3EN
 *   - Description: TIM3 clock enable
 *   - Values:
 *     - 0: TIM3 clock disabled
 *     - 1: TIM3 clock enabled
 * - Bit 0      : TIM2EN
 *   - Description: TIM2 clock enable
 *   - Values:
 *     - 0: TIM2 clock disabled
 *     - 1: TIM2 clock enabled
 */
#define RCC_APB1ENR     (*((volatile uint32_t *)(RCC + 0x1C)))

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
