# ControlFreak System Design

## Overview

Smoker has 3 x outputs:

1. Pit temperature
1. Food temperature
1. Food temperature

Initial build will use Maverick ET-723 probes for all temperatures.

A blower attached to one of the smoker input vents controls the pit temperature.

A microcontroller reads the temperature sensors and controls a PWM output to the blower. To
avoid an additional driver circuit, a blower with RPM output and PWM input control was
selected. The microcontroller provides a serial API to read/configure/control the system. A
connected computer (e.g. Raspberry Pi) can run the associated web app to
visualize/configure/control the system.

System can be run off a single 12V DC supply.


