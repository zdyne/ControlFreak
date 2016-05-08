import serial
import struct
import time


def as_resistance(adc):
    return 976.0 / ((1023.0 / adc) - 1.0)


def main():
    s = serial.Serial(port='/dev/cu.usbmodem1411', baudrate=115200)
    print s

    with s:
        time.sleep(4)

        with open('/Users/patrick/tmp/temperature.csv', 'w') as fp:

            while True:
                s.write(struct.pack("!B", 0x55))
                s.write(struct.pack("!B", 0x02))
                s.write(struct.pack("!B", 0x00))
                s.write(struct.pack("!B", 0x03))

                bytes = []
                for i in xrange(6):
                    bytes.append(s.read(1))

                t = struct.unpack("!B", bytes[3])[0] | struct.unpack("!B", bytes[4])[0] << 8
                fp.write("%s,%s,%s\n" % (time.time(), t, as_resistance(t)))
                fp.flush()

                time.sleep(1)


if __name__ == '__main__':
    main()
