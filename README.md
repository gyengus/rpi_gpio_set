rpi_gpio_set
============

Raspberry Pi GPIO reader/writer

<h3>Requirements</h3>

<ul>
<li>C library for Broadcom BCM 2835 as used in Raspberry Pi</li>
<li>root access to run, otherwise You can not access the Raspberry Pi GPIOs</li>
</ul>

<h3>How to build</h3>

<pre>
$ gcc -o bin/rpi_gpio_set rpi_gpio_set.c -l bcm2835
</pre>

<h3>Usage</h3>

<pre>
$ sudo bin/rpi_gpio_set PIN 0|1|t|?
</pre>
PIN	BCM 2835 pin number and <b>not</b> the Raspberry Pi pin number<br />
0	set PIN state to low<br />
1	set PIN state to high<br />
t	toggle PIN state<br />
?	read PIN state<br />
