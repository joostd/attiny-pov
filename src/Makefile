pov.hex: pov.c
	avr-gcc -g -Os -mmcu=attiny44a -c pov.c 
	avr-gcc -g -mmcu=attiny44a -o pov.elf pov.o
	avr-objcopy -j .text -j .data -O ihex pov.elf pov.hex

# NOTE: change the path to your programmer

flash: pov.hex
	avrdude -v -p t44 -c stk500v1 -P /dev/cu.usbmodem1411 -b 19200 -Uflash:w:pov.hex:i

