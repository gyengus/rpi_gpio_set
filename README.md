rpi_gpio_set
============

Raspberry Pi GPIO reader/writer

<h3>Requirements</h3>

<ul>
<li>C library for Broadcom BCM 2835 as used in Raspberry Pi (<a href='http://www.airspayce.com/mikem/bcm2835/' target='_blank'>link</a>)</li>
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
PIN <a href='http://www.airspayce.com/mikem/bcm2835/group__constants.html#ga63c029bd6500167152db4e57736d0939' target='_blank'>click here</a> for pin assignment<br />
0	set PIN state to low<br />
1	set PIN state to high<br />
t	toggle PIN state<br />
?	read PIN state<br />
