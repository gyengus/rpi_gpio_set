// After installing bcm2835, you can build this 
// with something like:
// gcc -o blink blink.c -l bcm2835

#include <string.h>
#include <stdio.h>
#include <bcm2835.h>

//#define PIN RPI_GPIO_P1_11

// fájlnév PIN 0/1/t/?
int main(int argc, char *argv[])
{
    uint8_t PIN;

    //printf("%s %s\n", argv[1], argv[2]);

    if (strcmp(argv[1], "11") == 0) {
	PIN = RPI_GPIO_P1_11;
	//printf("11 ok\n");
    } else if (strcmp(argv[1], "15") == 0) {
	PIN = RPI_GPIO_P1_15;
    } else if (strcmp(argv[1], "16") == 0) {
	PIN = RPI_GPIO_P1_16;
    } else if (strcmp(argv[1], "18") == 0) {
	PIN = RPI_GPIO_P1_18; // GPIO24
    } else if (strcmp(argv[1], "22") == 0) {
	PIN = RPI_GPIO_P1_22; // GPIO 25
    }
    // If you call this, it will not actually access the GPIO
    // Use for testing
//    bcm2835_set_debug(1);

    if (!bcm2835_init()) {
	printf("Hiba!\n");
	return 1;
    }

    // Set the pin to be an output
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);

    if (argv[2][0] == '0') {
        // ki
	bcm2835_gpio_write(PIN, LOW);
	//printf("ki\n");
    } else if (argv[2][0] == '1') {
	// be
	bcm2835_gpio_write(PIN, HIGH);
	//printf("be\n");
    } else if (argv[2][0] == 't') {
	// toggle
	if (bcm2835_gpio_lev(PIN)) {
	    bcm2835_gpio_write(PIN, LOW);
        } else {
	    bcm2835_gpio_write(PIN, HIGH);
	}
    } else if (argv[2][0] == '?') {
	// állapot lekérdezés
	//printf("?\n");
	printf("%d", bcm2835_gpio_lev(PIN));
    }

    bcm2835_close();
    return 0;
}

