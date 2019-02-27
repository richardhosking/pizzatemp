EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
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
LIBS:ArduinoThermometer-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "21 feb 2019"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L C C3
U 1 1 5C5FD7A4
P 2150 1500
F 0 "C3" H 2300 1450 40  0000 L CNN
F 1 "0.68uF" H 2250 1350 40  0000 L CNN
F 2 "~" H 2188 1350 30  0000 C CNN
F 3 "~" H 2150 1500 60  0000 C CNN
	1    2150 1500
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 5C5FD7B3
P 3850 2500
F 0 "R2" H 4050 2550 40  0000 C CNN
F 1 "10K" H 4050 2450 40  0000 C CNN
F 2 "~" V 3780 2500 30  0000 C CNN
F 3 "~" H 3850 2500 30  0000 C CNN
	1    3850 2500
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5C5FD7C2
P 3600 3200
F 0 "R1" H 3450 3300 40  0000 C CNN
F 1 "10K" H 3450 3200 40  0000 C CNN
F 2 "~" V 3530 3200 30  0000 C CNN
F 3 "~" H 3600 3200 30  0000 C CNN
	1    3600 3200
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 5C5FD7D1
P 5700 1450
F 0 "R4" H 5550 1350 40  0000 C CNN
F 1 "1K" H 5450 1450 40  0000 C CNN
F 2 "~" V 5630 1450 30  0000 C CNN
F 3 "~" H 5700 1450 30  0000 C CNN
	1    5700 1450
	-1   0    0    1   
$EndComp
$Comp
L R R3
U 1 1 5C5FD7E0
P 3850 3200
F 0 "R3" H 4000 3300 40  0000 C CNN
F 1 "10K" H 4000 3200 40  0000 C CNN
F 2 "~" V 3780 3200 30  0000 C CNN
F 3 "~" H 3850 3200 30  0000 C CNN
	1    3850 3200
	1    0    0    -1  
$EndComp
$Comp
L MAX941 U1
U 1 1 5C5FD9B6
P 3200 2150
F 0 "U1" H 2850 2650 60  0000 C CNN
F 1 "MAX941" H 2900 2550 60  0000 C CNN
F 2 "" H 3200 2150 60  0000 C CNN
F 3 "" H 3200 2150 60  0000 C CNN
	1    3200 2150
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 2150 3850 2150
Wire Wire Line
	3850 2150 6400 2150
Wire Wire Line
	3850 1200 3850 2150
Wire Wire Line
	3850 2150 3850 2250
Connection ~ 3850 2150
Wire Wire Line
	3850 2750 3850 2850
Wire Wire Line
	3850 2850 3850 2950
Connection ~ 3850 2850
Wire Wire Line
	3600 2950 3600 2850
Connection ~ 3600 2850
Wire Wire Line
	2700 2250 2600 2250
Wire Wire Line
	2600 2250 2600 2850
Wire Wire Line
	2600 2850 3600 2850
Wire Wire Line
	3600 2850 3850 2850
Wire Wire Line
	3200 2550 3200 3500
Wire Wire Line
	3200 3500 3300 3500
Wire Wire Line
	3300 3500 3600 3500
Wire Wire Line
	3600 3500 4450 3500
Wire Wire Line
	3600 3500 3600 3450
Wire Wire Line
	3300 2550 3300 3500
Connection ~ 3300 3500
Wire Wire Line
	2600 2050 2700 2050
Wire Wire Line
	2600 1100 2600 1200
Wire Wire Line
	2600 1200 2600 2050
Wire Wire Line
	2150 1200 2150 1300
Wire Wire Line
	1500 1200 1800 1200
Wire Wire Line
	1800 1200 2150 1200
Wire Wire Line
	2150 1200 2600 1200
Connection ~ 2600 1200
Wire Wire Line
	3850 1200 4050 1200
$Comp
L GND #PWR1
U 1 1 5C5FDAC9
P 2150 1900
F 0 "#PWR1" H 2150 1900 30  0001 C CNN
F 1 "GND" H 2150 1830 30  0001 C CNN
F 2 "" H 2150 1900 60  0000 C CNN
F 3 "" H 2150 1900 60  0000 C CNN
	1    2150 1900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR2
U 1 1 5C5FDAD8
P 3100 2650
F 0 "#PWR2" H 3100 2650 30  0001 C CNN
F 1 "GND" H 3100 2580 30  0001 C CNN
F 2 "" H 3100 2650 60  0000 C CNN
F 3 "" H 3100 2650 60  0000 C CNN
	1    3100 2650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR4
U 1 1 5C5FDAE7
P 3850 3750
F 0 "#PWR4" H 3850 3750 30  0001 C CNN
F 1 "GND" H 3850 3680 30  0001 C CNN
F 2 "" H 3850 3750 60  0000 C CNN
F 3 "" H 3850 3750 60  0000 C CNN
	1    3850 3750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR3
U 1 1 5C5FDAF6
P 3450 2000
F 0 "#PWR3" H 3450 2000 30  0001 C CNN
F 1 "GND" H 3450 1930 30  0001 C CNN
F 2 "" H 3450 2000 60  0000 C CNN
F 3 "" H 3450 2000 60  0000 C CNN
	1    3450 2000
	1    0    0    -1  
$EndComp
$Comp
L C C4
U 1 1 5C5FDB05
P 3450 1700
F 0 "C4" H 3200 1600 40  0000 L CNN
F 1 "100nF" H 3200 1500 40  0000 L CNN
F 2 "~" H 3488 1550 30  0000 C CNN
F 3 "~" H 3450 1700 60  0000 C CNN
	1    3450 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3100 1750 3100 1450
Wire Wire Line
	3100 1450 3450 1450
Wire Wire Line
	3450 1450 3650 1450
Wire Wire Line
	3450 1450 3450 1500
Wire Wire Line
	3850 3450 3850 3750
Wire Wire Line
	3450 1900 3450 2000
Wire Wire Line
	3100 2550 3100 2650
Wire Wire Line
	2150 1700 2150 1800
Wire Wire Line
	2150 1800 2150 1900
$Comp
L C C2
U 1 1 5C5FDD09
P 1800 1500
F 0 "C2" H 1750 1100 40  0000 L CNN
F 1 "10nF" H 1750 1000 40  0000 L CNN
F 2 "~" H 1838 1350 30  0000 C CNN
F 3 "~" H 1800 1500 60  0000 C CNN
	1    1800 1500
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 5C5FDD25
P 1500 1500
F 0 "C1" H 1450 1100 40  0000 L CNN
F 1 "10nF" H 1450 1000 40  0000 L CNN
F 2 "~" H 1538 1350 30  0000 C CNN
F 3 "~" H 1500 1500 60  0000 C CNN
	1    1500 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 1300 1500 1200
Connection ~ 2150 1200
Wire Wire Line
	1800 1300 1800 1200
Connection ~ 1800 1200
Wire Wire Line
	1800 1700 1800 1800
Wire Wire Line
	1500 1800 1800 1800
Wire Wire Line
	1800 1800 2150 1800
Connection ~ 2150 1800
Wire Wire Line
	1500 1700 1500 1800
Connection ~ 1800 1800
$Comp
L CONN_3 K1
U 1 1 5C5FDDB7
P 4400 1200
F 0 "K1" V 4350 1200 50  0000 C CNN
F 1 "CONN_3" V 4450 1200 40  0000 C CNN
F 2 "" H 4400 1200 60  0000 C CNN
F 3 "" H 4400 1200 60  0000 C CNN
	1    4400 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2600 1100 4050 1100
$Comp
L GND #PWR5
U 1 1 5C5FDE29
P 4000 1550
F 0 "#PWR5" H 4000 1550 30  0001 C CNN
F 1 "GND" H 4000 1480 30  0001 C CNN
F 2 "" H 4000 1550 60  0000 C CNN
F 3 "" H 4000 1550 60  0000 C CNN
	1    4000 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 1300 4000 1300
Wire Wire Line
	4000 1300 4000 1550
$Comp
L CONN_3 K2
U 1 1 5C5FDE9D
P 4750 1200
F 0 "K2" V 4700 1200 50  0000 C CNN
F 1 "CONN_3" V 4800 1200 40  0000 C CNN
F 2 "" H 4750 1200 60  0000 C CNN
F 3 "" H 4750 1200 60  0000 C CNN
	1    4750 1200
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5100 1100 5700 1100
Wire Wire Line
	5700 1100 5700 1200
Wire Wire Line
	5100 1200 5500 1200
Wire Wire Line
	5500 1200 5500 1800
Wire Wire Line
	5500 1800 5700 1800
Wire Wire Line
	5700 1800 5700 1700
Wire Wire Line
	5100 1300 5250 1300
Wire Wire Line
	5250 1300 5250 1550
$Comp
L GND #PWR6
U 1 1 5C5FE113
P 5250 1550
F 0 "#PWR6" H 5250 1550 30  0001 C CNN
F 1 "GND" H 5250 1480 30  0001 C CNN
F 2 "" H 5250 1550 60  0000 C CNN
F 3 "" H 5250 1550 60  0000 C CNN
	1    5250 1550
	1    0    0    -1  
$EndComp
$Comp
L CONN_14 P1
U 1 1 5C6DE023
P 5800 3250
F 0 "P1" V 5770 3250 60  0000 C CNN
F 1 "CONN_14" V 5880 3250 60  0000 C CNN
F 2 "" H 5800 3250 60  0000 C CNN
F 3 "" H 5800 3250 60  0000 C CNN
	1    5800 3250
	-1   0    0    -1  
$EndComp
$Comp
L CONN_14 P2
U 1 1 5C6DE032
P 7300 3250
F 0 "P2" V 7270 3250 60  0000 C CNN
F 1 "CONN_14" V 7380 3250 60  0000 C CNN
F 2 "" H 7300 3250 60  0000 C CNN
F 3 "" H 7300 3250 60  0000 C CNN
	1    7300 3250
	1    0    0    1   
$EndComp
Text Notes 5500 800  0    60   ~ 0
Thermistor \nHoneywell HEL-707-U-12-00\n1000 Ohms at 0 deg C 
$Comp
L GND #PWR7
U 1 1 5C6DE2B3
P 6800 5500
F 0 "#PWR7" H 6800 5500 30  0001 C CNN
F 1 "GND" H 6800 5430 30  0001 C CNN
F 2 "" H 6800 5500 60  0000 C CNN
F 3 "" H 6800 5500 60  0000 C CNN
	1    6800 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6600 5350 6600 2900
Wire Wire Line
	6600 2900 6950 2900
Wire Wire Line
	3650 1450 3650 1900
Wire Wire Line
	3650 1900 4450 1900
Wire Wire Line
	4450 1900 6700 1900
Wire Wire Line
	6700 1900 6700 2800
Wire Wire Line
	6700 2800 6950 2800
Connection ~ 3450 1450
Wire Wire Line
	4450 3500 4450 1900
Connection ~ 4450 1900
Connection ~ 3600 3500
Text Notes 1200 2200 0    60   ~ 0
Trim Capacitance 
Wire Wire Line
	6150 2700 6400 2700
Wire Wire Line
	6400 2700 6400 2150
Wire Notes Line
	5600 4150 7500 4150
Wire Notes Line
	7500 4150 7500 2250
Wire Notes Line
	5600 2250 5600 4150
Wire Notes Line
	7500 2250 5600 2250
Text Notes 5600 4300 0    60   ~ 0
MKR1000 Shield
Text Label 6750 2800 0    60   ~ 0
3V3
Text Label 6750 2900 0    60   ~ 0
GND
Text Label 6150 2700 0    60   ~ 0
AIN0
Wire Wire Line
	6800 3000 6950 3000
Wire Wire Line
	6800 3000 6800 4650
$Comp
L SW_PUSH SW1
U 1 1 5C6DED15
P 6800 4950
F 0 "SW1" V 6700 5250 50  0000 C CNN
F 1 "RESET" V 6850 5300 50  0000 C CNN
F 2 "~" H 6800 4950 60  0000 C CNN
F 3 "~" H 6800 4950 60  0000 C CNN
	1    6800 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	6800 5250 6800 5350
Wire Wire Line
	6800 5350 6800 5500
Wire Wire Line
	6600 5350 6800 5350
Connection ~ 6800 5350
Text Label 6650 3000 0    60   ~ 0
RESET
$EndSCHEMATC