import serial
import struct
import time


def main():
    s = serial.Serial(port='/dev/cu.usbmodem1411', baudrate=115200)
    print s

    with s:
        time.sleep(4)

        s.write(struct.pack("!B", 0x55))
        s.write(struct.pack("!B", 0x02))
        s.write(struct.pack("!B", 0x00))
        s.write(struct.pack("!B", 0x03))
        time.sleep(1)


if __name__ == '__main__':
    main()
