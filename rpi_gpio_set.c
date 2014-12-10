/**
 * RPI GPIO reader/writer example
 * @author Gyengus(Tm)
 * @link http://gyengus.hu
 * Build:  gcc -o bin/rpi_gpi_set rpi_gpio_set.c -l bcm2835
 * Usage: sudo rpi_gpio_set PIN 0|1|t|?
 */

#include <string.h>
#include <stdio.h>
#include <bcm2835.h>

int main(int argc, char *argv[]) {
    uint8_t PIN;

    if (strcmp(argv[1], "11") == 0) {
	PIN = RPI_GPIO_P1_11;
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
    //bcm2835_set_debug(1);

    if (!bcm2835_init()) {
	printf("Hiba!\n");
	return 1;
    }

    // Set the pin to be an output
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);

    if (argv[2][0] == '0') {
        // To low
	bcm2835_gpio_write(PIN, LOW);
    } else if (argv[2][0] == '1') {
	// To high
	bcm2835_gpio_write(PIN, HIGH);
    } else if (argv[2][0] == 't') {
	// Toggle PIN
	if (bcm2835_gpio_lev(PIN)) {
	    bcm2835_gpio_write(PIN, LOW);
        } else {
	    bcm2835_gpio_write(PIN, HIGH);
	}
    } else if (argv[2][0] == '?') {
	// Retrieve PIN status
	printf("%d", bcm2835_gpio_lev(PIN));
    }

    bcm2835_close();
    return 0;
} // main
