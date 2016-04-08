avrdude -v -p atmega328p -c arduino -P /dev/cu.usbmodem1411 -b 115200 -D -U flash:w:build/arduino/control_freak.hex:i
