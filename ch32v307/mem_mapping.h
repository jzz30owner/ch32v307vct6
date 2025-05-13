#pragma once

#define PHY_ADDRESS   0x01 
#define DVP           0x50050000
#define USBFS         0x50000000
#define ETH_BASE      0x40028000
#define TRNG          0x40023C00 
#define EXTEN_BASE    0x40023800
#define USBHS         0x40023400         
#define CRC           0x40023000
#define FLASH_INTER   0x40022000
#define RCC_BASE      0x40021000
#define DMA2          0x40020400
#define DMA1          0x40020000
#define SDIO          0x40018000
#define TIM10_BASE    0x40015000
#define TIM9_BASE     0x40014C00
#define USART1        0x40013800
#define TIM8_BASE     0x40013400
#define SPI1          0x40013000
#define TIM1_BASE     0x40012C00
#define ADC2          0x40012800
#define ADC1          0x40012400

#define PE            0x40011800
#define PD            0x40011400
#define PC            0x40011000
#define PB            0x40010C00
#define PA            0x40010800

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

#define TIM7_BASE     0x40001400
#define TIM6_BASE     0x40001000
#define TIM5_BASE     0x40000C00
#define TIM4_BASE     0x40000800
#define TIM3_BASE     0x40000400
#define TIM2_BASE     0x40000000

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


