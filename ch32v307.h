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

typedef struct {
    volatile uint32_t MACCR;
    volatile uint32_t MACFFR;
    volatile uint32_t MACHTHR;
    volatile uint32_t MACHTLR;
    volatile uint32_t MACMIIAR;
    volatile uint32_t MACMIIDR;
    volatile uint32_t MACFCR;
    volatile uint32_t MACVLANTR;
    uint32_t RESERVED0[2];
    volatile uint32_t MACRWUFFR;
    volatile uint32_t MACPMTCSR;
    uint32_t RESERVED1;
    volatile uint32_t MACDBGR;
    volatile uint32_t MACSR;
    volatile uint32_t MACIMR;
    volatile uint32_t MACA0HR;
    volatile uint32_t MACA0LR;
} EMAC_TypeDef;


#define ETH            ((EMAC_TypeDef *) ETH_BASE)

#define RCC_CTL         (*((volatile uint32_t *)(RCC + 0x00))) // Control register
#define RCC_CFG0        (*((volatile uint32_t *)(RCC + 0x04))) // Clock config
#define RCC_APB2EN      (*((volatile uint32_t *)(RCC + 0x18))) // APB2 enable
                                                               //
// Ports
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
