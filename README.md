rpi_gpio_set
============

Raspberry Pi GPIO reader/writer

Requirements

C library for Broadcom BCM 2835 as used in Raspberry Pi
root access to run, otherwise You can not access the Raspberry Pi GPIOs

How to build

<pre>
$ gcc -o bin/rpi_gpio_set rpi_gpio_set.c -l bcm2835
</pre>

Usage

<pre>
$ sudo bin/rpi_gpio_set PIN 0|1|t|?
</pre>
PIN	BCM 2835 pin number and <b>not</b> the Raspberry Pi pin number
0	set PIN state to low
1	set PIN state to high
t	toggle PIN state
?	read PIN state
