EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:arduino_shieldsNCL
LIBS:ESP8266
LIBS:arduino
LIBS:4x4_keypad
LIBS:fablab-noninventory
LIBS:prj-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ARDUINO_NANO ARDUINO_NANO
U 1 1 59DA704E
P 6400 3550
F 0 "ARDUINO_NANO" H 6400 4400 70  0000 C CNN
F 1 "ARDUINO_NANO" V 6400 3550 70  0000 C CNN
F 2 "" H 6400 3550 60  0000 C CNN
F 3 "" H 6400 3550 60  0000 C CNN
	1    6400 3550
	1    0    0    -1  
$EndComp
$Comp
L 4x4_Keypad 96BB2-006-F?
U 1 1 59DA70C7
P 4850 5150
F 0 "96BB2-006-F?" H 4850 5150 60  0000 C CNN
F 1 "4x4_Keypad" H 4850 5250 60  0000 C CNN
F 2 "" H 4850 5150 60  0000 C CNN
F 3 "" H 4850 5150 60  0000 C CNN
	1    4850 5150
	1    0    0    -1  
$EndComp
$Comp
L 0.96"_OLED_I2C DS?
U 1 1 59DA7625
P 7800 3250
F 0 "DS?" H 7800 3550 60  0000 C CNN
F 1 "0.96\"_OLED_I2C" H 7800 2850 60  0000 C CNN
F 2 "" H 7800 3100 60  0000 C CNN
F 3 "" H 7800 3100 60  0000 C CNN
	1    7800 3250
	0    -1   1    0   
$EndComp
Wire Wire Line
	4700 4300 4700 3600
Wire Wire Line
	4700 3600 5800 3600
Wire Wire Line
	5800 3700 4800 3700
Wire Wire Line
	4800 3700 4800 4300
Wire Wire Line
	4900 4300 4900 3800
Wire Wire Line
	4900 3800 5800 3800
Wire Wire Line
	5000 4300 5000 3900
Wire Wire Line
	5000 3900 5800 3900
Wire Wire Line
	5100 4300 5100 4000
Wire Wire Line
	5100 4000 5800 4000
Wire Wire Line
	5200 4300 5200 4100
Wire Wire Line
	5200 4100 5800 4100
Wire Wire Line
	4600 4300 4600 3500
Wire Wire Line
	4600 3500 5800 3500
Wire Wire Line
	5800 3400 4500 3400
Wire Wire Line
	4500 3400 4500 4300
Wire Wire Line
	7000 3100 7650 3100
Wire Wire Line
	7000 2900 7350 2900
Wire Wire Line
	7350 2900 7350 3200
Wire Wire Line
	7350 3200 7650 3200
Wire Wire Line
	7000 3400 7450 3400
Wire Wire Line
	7450 3400 7450 3300
Wire Wire Line
	7450 3300 7650 3300
Wire Wire Line
	7650 3400 7550 3400
Wire Wire Line
	7550 3400 7550 3500
Wire Wire Line
	7550 3500 7000 3500
$EndSCHEMATC
