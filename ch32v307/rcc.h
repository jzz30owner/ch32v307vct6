#pragma once

#include "mem_mapping.h"


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
#define RCC_CTL         (*((volatile uint32_t *)(RCC_BASE + 0x00))) // Control register
                                                               //
 /**
 * @brief RCC_CIR - Reset and Clock Control Clock Interrupt Register
 *
 * @details This 32-bit read-write register configures and monitors clock-related
 * interrupts and status flags on the CH32V307, located at address 0x40021004
 * (RCC base + 0x04). It enables/disables interrupts for clock readiness events
 * (LSI, HSI, HSE, PLL) and Clock Security System (CSS) events, provides status
 * flags for these events, and allows clearing interrupt flags. Clock sources must
 * be enabled via RCC_CR (e.g., HSION, HSEON, PLLON) and configured in RCC_CFGR
 * before using interrupts. RCC interrupts must be enabled in the NVIC for
 * interrupt-driven operation. The CSS interrupt requires CSSON in RCC_CR.
 *
 * @note The CH32V307 supports HSI (8 MHz), HSE (4–32 MHz), PLL, and LSI (40 kHz)
 * clock sources. Use this register to monitor clock stability or handle HSE failures
 * via CSS. Write 1 to clear flags (e.g., PLLRDYC). Ensure NVIC is configured for RCC
 * interrupts. Consult the CH32V307 datasheet and reference manual for interrupt
 * configuration details.
 *
 * Bit fields:
 * - Bits 31:24 : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 23     : CSSC
 *   - Description: Clock security system interrupt clear (write-only)
 *   - Values:
 *     - 0: No effect
 *     - 1: Clear CSS interrupt flag
 * - Bit 22     : PLLRDYC
 *   - Description: PLL ready interrupt clear (write-only)
 *   - Values:
 *     - 0: No effect
 *     - 1: Clear PLLRDY interrupt flag
 * - Bit 21     : HSERDYC
 *   - Description: HSE ready interrupt clear (write-only)
 *   - Values:
 *     - 0: No effect
 *     - 1: Clear HSERDY interrupt flag
 * - Bit 20     : HSIRDYC
 *   - Description: HSI ready interrupt clear (write-only)
 *   - Values:
 *     - 0: No effect
 *     - 1: Clear HSIRDY interrupt flag
 * - Bit 19     : LSIRDYC
 *   - Description: LSI ready interrupt clear (write-only)
 *   - Values:
 *     - 0: No effect
 *     - 1: Clear LSIRDY interrupt flag
 * - Bits 18:16 : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 15     : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 14     : CSSONIE
 *   - Description: Clock security system interrupt enable
 *   - Values:
 *     - 0: CSS interrupt disabled
 *     - 1: CSS interrupt enabled
 * - Bit 13     : PLLRDYIE
 *   - Description: PLL ready interrupt enable
 *   - Values:
 *     - 0: PLLRDY interrupt disabled
 *     - 1: PLLRDY interrupt enabled
 * - Bit 12     : HSERDYIE
 *   - Description: HSE ready interrupt enable
 *   - Values:
 *     - 0: HSERDY interrupt disabled
 *     - 1: HSERDY interrupt enabled
 * - Bit 11     : HSIRDYIE
 *   - Description: HSI ready interrupt enable
 *   - Values:
 *     - 0: HSIRDY interrupt disabled
 *     - 1: HSIRDY interrupt enabled
 * - Bit 10     : LSIRDYIE
 *   - Description: LSI ready interrupt enable
 *   - Values:
 *     - 0: LSIRDY interrupt disabled
 *     - 1: LSIRDY interrupt enabled
 * - Bits 9:8   : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 * - Bit 7      : CSSF
 *   - Description: Clock security system interrupt flag (read-only)
 *   - Values:
 *     - 0: No CSS event
 *     - 1: CSS event detected (HSE failure)
 * - Bit 6      : PLLRDYF
 *   - Description: PLL ready interrupt flag (read-only)
 *   - Values:
 *     - 0: No PLL ready event
 *     - 1: PLL ready event
 * - Bit 5      : HSERDYF
 *   - Description: HSE ready interrupt flag (read-only)
 *   - Values:
 *     - 0: No HSE ready event
 *     - 1: HSE ready event
 * - Bit 4      : HSIRDYF
 *   - Description: HSI ready interrupt flag (read-only)
 *   - Values:
 *     - 0: No HSI ready event
 *     - 1: HSI ready event
 * - Bit 3      : LSIRDYF
 *   - Description: LSI ready interrupt flag (read-only)
 *   - Values:
 *     - 0: No LSI ready event
 *     - 1: LSI ready event
 * - Bits 2:0   : Reserved
 *   - Description: Reserved, should be kept at 0
 *   - Values: N/A
 */
#define RCC_CIR         (*((volatile uint32_t *)(RCC_BASE + 0x04))) 

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
#define RCC_CFGR        (*((volatile uint32_t *)(RCC_BASE + 0x08))) // Clock config

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

 /**
 * @brief RCC_AHBENR - AHB Peripheral Clock Enable Register
 *
 * @details The RCC_AHBENR register enables or disables the clock for peripherals
 * connected to the AHB bus in the CH32V307 microcontroller. Located at address
 * 0x40021014, this 32-bit register controls clock gating for peripherals such as
 * DMA1, DMA2, SRAM, USB, and CRC, which are essential for high-performance
 * operations like Ethernet frame transfers (via DMA2) and data integrity checks
 * (via CRC). Writing 1 to a bit enables the corresponding peripheral's clock,
 * while writing 0 disables it. Ensure stable system clocks (via RCC_CR, RCC_CFGR)
 * before accessing this register. This register is particularly relevant for
 * Ethernet applications (e.g., enabling DMA2 for ETH frame handling) and CRC
 * calculations, complementing RCC_APB2ENR (EMACEN) settings.
 *
 * @note Bits not listed are reserved and should be kept at reset value (0).
 * Consult the CH32V307 reference manual (CH32FV2x_V3xRM.PDF) for detailed
 * peripheral clock dependencies. Register access requires AHB clock stability,
 * monitorable via RCC_CIR (e.g., PLLRDYF, CSSF).
 *
 * Bit fields:
 * - Bit 0 : DMA1EN
 *   - Description: DMA1 clock enable
 *   - Values: 0 = Disabled, 1 = Enabled
 * - Bit 1 : DMA2EN
 *   - Description: DMA2 clock enable (used for Ethernet)
 *   - Values: 0 = Disabled, 1 = Enabled
 * - Bit 2 : SRAMEN
 *   - Description: SRAM clock enable
 *   - Values: 0 = Disabled, 1 = Enabled
 * - Bit 3 : Reserved
 *   - Description: Reserved, keep at 0
 *   - Values: 0
 * - Bit 4 : USBEN
 *   - Description: USB clock enable
 *   - Values: 0 = Disabled, 1 = Enabled
 * - Bit 5 : Reserved
 *   - Description: Reserved, keep at 0
 *   - Values: 0
 * - Bit 6 : CRCEN
 *   - Description: CRC clock enable
 *   - Values: 0 = Disabled, 1 = Enabled
 * - Bits 7-31 : Reserved
 *   - Description: Reserved, keep at 0
 *   - Values: 0
 */
#define RCC_AHBENR      (*((volatile uint32_t *)(RCC_BASE + 0x14)))

#define RCC_APB2EN      (*((volatile uint32_t *)(RCC_BASE + 0x18))) // APB2 enable
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
#define RCC_APB1ENR     (*((volatile uint32_t *)(RCC_BASE + 0x1C)))

typedef struct {
  volatile uint32_t CTLR;
  volatile uint32_t CFGR0;
  volatile uint32_t INTR;
  volatile uint32_t APB2PRSTR;
  volatile uint32_t APB1PRSTR;
  volatile uint32_t AHBENR;
  volatile uint32_t APB2ENR;
  volatile uint32_t APB1ENR;
  volatile uint32_t BDCTLR;
  volatile uint32_t RSTSCKR;
  volatile uint32_t AHBRSTR;
  volatile uint32_t CFGR2;
} RCC_TypeDef;

#define RCC                 ((RCC_TypeDef *)RCC_BASE)

