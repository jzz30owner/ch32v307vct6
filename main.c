/*
*
* Just blink LED0 and write bytes to PA15
*
*
*
*
*/
#define RCC_APB2ENR   (*(volatile unsigned long *)0x40021018)
#define GPIOA_CRH     (*(volatile unsigned long *)0x40010804)
#define GPIOA_CRL     (*(volatile unsigned long *)0x40010800)
#define GPIOA_ODR     (*(volatile unsigned long *)0x4001080C)
#define AFIO_PCFR1    (*(volatile unsigned long *)0x40010004)

void delay(volatile unsigned int t) {
    while (t--) asm volatile ("nop");
}

void main(void) {
    // Enable GPIOA + AFIO
    RCC_APB2ENR |= (1 << 2);  // GPIOAEN
    RCC_APB2ENR |= (1 << 0);  // AFIOEN

    // Disable JTAG/SWD so PA15 can be used
    AFIO_PCFR1 |= (0b100 << 24); // Full disable: SWJ_CFG = 0b100

    // Configure PA15: push-pull output, 2 MHz
    GPIOA_CRH &= ~(0xF << 28); // clear
    GPIOA_CRH |=  (0x2 << 28); // MODE = 10, CNF = 00

    // Configure PA5 (A5) as push-pull output, 2MHz
    GPIOA_CRL &= ~(0xF << 20);
    GPIOA_CRL |=  (0x2 << 20);

    while (1) {
        GPIOA_ODR ^= (1 << 15); // toggle PA15
        GPIOA_ODR ^= (1 << 5);
        delay(200000);
    }
}

__attribute__((naked, section(".init"))) void _start(void) {
    main();
    while (1);
}

