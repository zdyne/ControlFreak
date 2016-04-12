import serial
import struct
import time


def main():
    s = serial.Serial(port='/dev/cu.usbmodem1411', baudrate=115200)
    print s

    with s:
        time.sleep(4)

        s.write(struct.pack("!B", 0x55))
        s.write(struct.pack("!B", 0x00))
        s.write(struct.pack("!B", 0x01))
        # 50% duty cycle
        s.write(struct.pack("!B", 0x80))
        s.write(struct.pack("!B", 0x03))

        bytes = []
        for i in xrange(5):
            bytes.append(s.read(1))

        print "Tag: %s" % hex(struct.unpack("!B", bytes[0])[0])
        print "Cmd: %s" % hex(struct.unpack("!B", bytes[1])[0])
        print "Data Bytes: %s" % hex(struct.unpack("!B", bytes[2])[0])
        print "Data"
        print "\t[0]: %s" % hex(struct.unpack("!B", bytes[3])[0])
        print "Checksum: %s" % hex(struct.unpack("!B", bytes[4])[0])


        s.write(struct.pack("!B", 0x55))
        s.write(struct.pack("!B", 0x01))
        s.write(struct.pack("!B", 0x00))
        s.write(struct.pack("!B", 0x03))

        time.sleep(4)

        # Read the tach for a few seconds
        bytes = []
        for i in xrange(6):
            bytes.append(s.read(1))

        print "Tag: %s" % hex(struct.unpack("!B", bytes[0])[0])
        print "Cmd: %s" % hex(struct.unpack("!B", bytes[1])[0])
        print "Data Bytes: %s" % hex(struct.unpack("!B", bytes[2])[0])
        print "Data"
        print "\t[0]: %s" % hex(struct.unpack("!B", bytes[3])[0])
        print "\t[1]: %s" % hex(struct.unpack("!B", bytes[4])[0])
        print "Checksum: %s" % hex(struct.unpack("!B", bytes[5])[0])


if __name__ == '__main__':
    main()
