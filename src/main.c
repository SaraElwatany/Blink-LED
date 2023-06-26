/*

 Name: Sara Ayman Mohamed Abdullah
 Section: 1
 Bench Number: 39

 */

#define GPIOB_BASE_ADDR  0x40020000


#define GPIOB_MODER      (*(unsigned long *)(GPIOB_BASE_ADDR + 0x00))
#define GPIOB_OTYPER     (*(unsigned long *)(GPIOB_BASE_ADDR + 0x04))
#define GPIOB_ODR        (*(unsigned long *)(GPIOB_BASE_ADDR + 0x14))

#define RCC_AHB1ENR      (*(unsigned long *) (0x40023800 + 0x30))
#define RCC_CR           (*(unsigned long *) (0x40023800 + 0x00))




int main(){

    RCC_CR |= (1 << 0);
	RCC_AHB1ENR  |= (1 << 0);       // enable clock on portA

	unsigned char mode_pin_gpio_a = 1;    // pin 0 output mode

	GPIOB_MODER &= ~(0x03 << 0);                /* clear pin 0*/
    GPIOB_MODER |= mode_pin_gpio_a << (0);     // pin 0 output mode

    GPIOB_OTYPER &= ~(1 << 0); // pin0 push pull

	GPIOB_ODR |= (1 << 0);
	unsigned long i = 0;

	while(1) {
		// set pin 0 to high
		GPIOB_ODR |= (1 << 0);
		// wait 1s
		for(i = 0; i < 1000000; i++);
		// set pin 0 to low
		GPIOB_ODR &= ~(1 << 0);
		// wait 1s
		for(i = 0; i < 1000000; i++);
	}


	return 0;
}
