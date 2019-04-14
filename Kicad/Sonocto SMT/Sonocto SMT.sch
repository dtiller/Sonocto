EESchema Schematic File Version 4
LIBS:Sonocto SMT-cache
EELAYER 29 0
EELAYER END
$Descr USLetter 11000 8500
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
L 74xx:74LS251 U3
U 1 1 5C977B06
P 7150 2550
F 0 "U3" H 7450 3350 50  0000 C CNN
F 1 "74LS251" H 6950 3350 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 7150 2550 50  0001 C CNN
F 3 "http://www.ti.com/lit/gpn/sn74LS251" H 7150 2550 50  0001 C CNN
	1    7150 2550
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5C9798EE
P 1550 2400
F 0 "#PWR0101" H 1550 2150 50  0001 C CNN
F 1 "GND" H 1555 2227 50  0000 C CNN
F 2 "" H 1550 2400 50  0001 C CNN
F 3 "" H 1550 2400 50  0001 C CNN
	1    1550 2400
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0102
U 1 1 5C97ABC0
P 1950 1600
F 0 "#PWR0102" H 1950 1450 50  0001 C CNN
F 1 "+12V" H 1965 1773 50  0000 C CNN
F 2 "" H 1950 1600 50  0001 C CNN
F 3 "" H 1950 1600 50  0001 C CNN
	1    1950 1600
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Linear:L7805 U1
U 1 1 5C97B5F5
P 2550 1850
F 0 "U1" H 2550 2092 50  0000 C CNN
F 1 "L7805" H 2550 2001 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 2575 1700 50  0001 L CIN
F 3 "http://www.st.com/content/ccc/resource/technical/document/datasheet/41/4f/b3/b0/12/d4/47/88/CD00000444.pdf/files/CD00000444.pdf/jcr:content/translations/en.CD00000444.pdf" H 2550 1800 50  0001 C CNN
	1    2550 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 2400 1550 2450
$Comp
L Connector_Generic:Conn_01x04 J1
U 1 1 5C97B0F8
P 1100 1950
F 0 "J1" H 1018 2267 50  0000 C CNN
F 1 "Conn_01x04" H 1018 2176 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 1100 1950 50  0001 C CNN
F 3 "~" H 1100 1950 50  0001 C CNN
	1    1100 1950
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1950 1850 1950 1600
Wire Wire Line
	1300 1950 1550 1950
Wire Wire Line
	1550 1950 1550 2150
Wire Wire Line
	2550 2150 1950 2150
Connection ~ 1550 2150
$Comp
L power:+5V #PWR0103
U 1 1 5C985354
P 3000 1550
F 0 "#PWR0103" H 3000 1400 50  0001 C CNN
F 1 "+5V" H 3015 1723 50  0000 C CNN
F 2 "" H 3000 1550 50  0001 C CNN
F 3 "" H 3000 1550 50  0001 C CNN
	1    3000 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 1850 3000 1850
Wire Wire Line
	3000 1850 3000 1550
$Comp
L Device:CP1 C2
U 1 1 5C986409
P 3000 2000
F 0 "C2" H 3115 2046 50  0000 L CNN
F 1 "0.47 uF" H 3115 1955 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.00mm" H 3000 2000 50  0001 C CNN
F 3 "~" H 3000 2000 50  0001 C CNN
	1    3000 2000
	1    0    0    -1  
$EndComp
Connection ~ 3000 1850
Wire Wire Line
	3000 2150 2550 2150
Connection ~ 2550 2150
$Comp
L Device:CP1 C1
U 1 1 5C9870AA
P 1950 2000
F 0 "C1" H 2065 2046 50  0000 L CNN
F 1 "0.47 uF" H 2065 1955 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.00mm" H 1950 2000 50  0001 C CNN
F 3 "~" H 1950 2000 50  0001 C CNN
	1    1950 2000
	1    0    0    -1  
$EndComp
Connection ~ 1950 1850
Wire Wire Line
	1950 1850 2250 1850
Connection ~ 1950 2150
Wire Wire Line
	1950 2150 1550 2150
Wire Wire Line
	1550 2150 1550 2400
Connection ~ 1550 2400
Wire Wire Line
	1300 1850 1650 1850
$Comp
L 74xx_IEEE:74HC238 U4
U 1 1 5C9A824C
P 7200 4750
F 0 "U4" H 7200 5266 50  0000 C CNN
F 1 "74HC238" H 7200 5175 50  0000 C CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 7200 4750 50  0001 C CNN
F 3 "" H 7200 4750 50  0001 C CNN
	1    7200 4750
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J2
U 1 1 5C9B3DAD
P 9800 1750
F 0 "J2" H 9908 2031 50  0000 C CNN
F 1 "Sonar 0" H 9908 1940 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 9800 1750 50  0001 C CNN
F 3 "~" H 9800 1750 50  0001 C CNN
	1    9800 1750
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J3
U 1 1 5C9B544A
P 9800 2300
F 0 "J3" H 9908 2581 50  0000 C CNN
F 1 "Sonar 1" H 9908 2490 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 9800 2300 50  0001 C CNN
F 3 "~" H 9800 2300 50  0001 C CNN
	1    9800 2300
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J4
U 1 1 5C9B62F7
P 9800 2850
F 0 "J4" H 9908 3131 50  0000 C CNN
F 1 "Sonar 2" H 9908 3040 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 9800 2850 50  0001 C CNN
F 3 "~" H 9800 2850 50  0001 C CNN
	1    9800 2850
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J5
U 1 1 5C9B6DF2
P 9800 3400
F 0 "J5" H 9908 3681 50  0000 C CNN
F 1 "Sonar 3" H 9908 3590 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 9800 3400 50  0001 C CNN
F 3 "~" H 9800 3400 50  0001 C CNN
	1    9800 3400
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J6
U 1 1 5C9B7965
P 9800 3950
F 0 "J6" H 9908 4231 50  0000 C CNN
F 1 "Sonar 4" H 9908 4140 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 9800 3950 50  0001 C CNN
F 3 "~" H 9800 3950 50  0001 C CNN
	1    9800 3950
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J7
U 1 1 5C9B8268
P 9800 4500
F 0 "J7" H 9908 4781 50  0000 C CNN
F 1 "Sonar 5" H 9908 4690 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 9800 4500 50  0001 C CNN
F 3 "~" H 9800 4500 50  0001 C CNN
	1    9800 4500
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J8
U 1 1 5C9B8D3F
P 9800 5050
F 0 "J8" H 9908 5331 50  0000 C CNN
F 1 "Sonar 6" H 9908 5240 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 9800 5050 50  0001 C CNN
F 3 "~" H 9800 5050 50  0001 C CNN
	1    9800 5050
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J9
U 1 1 5C9B98D9
P 9800 5600
F 0 "J9" H 9908 5881 50  0000 C CNN
F 1 "Sonar 7" H 9908 5790 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 9800 5600 50  0001 C CNN
F 3 "~" H 9800 5600 50  0001 C CNN
	1    9800 5600
	-1   0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0104
U 1 1 5C9CC550
P 9450 1350
F 0 "#PWR0104" H 9450 1200 50  0001 C CNN
F 1 "+5V" H 9465 1523 50  0000 C CNN
F 2 "" H 9450 1350 50  0001 C CNN
F 3 "" H 9450 1350 50  0001 C CNN
	1    9450 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9450 1350 9450 1650
Wire Wire Line
	9450 1650 9600 1650
Wire Wire Line
	9600 2200 9450 2200
Wire Wire Line
	9450 2200 9450 1650
Connection ~ 9450 1650
Wire Wire Line
	9600 2750 9450 2750
Wire Wire Line
	9450 2750 9450 2200
Connection ~ 9450 2200
Wire Wire Line
	9600 3300 9450 3300
Wire Wire Line
	9450 3300 9450 2750
Connection ~ 9450 2750
Wire Wire Line
	9600 3850 9450 3850
Wire Wire Line
	9450 3850 9450 3300
Connection ~ 9450 3300
Wire Wire Line
	9600 4400 9450 4400
Wire Wire Line
	9450 4400 9450 3850
Connection ~ 9450 3850
Wire Wire Line
	9600 4950 9450 4950
Wire Wire Line
	9450 4950 9450 4400
Connection ~ 9450 4400
Wire Wire Line
	9600 5500 9450 5500
Wire Wire Line
	9450 5500 9450 4950
Connection ~ 9450 4950
$Comp
L power:GND #PWR0105
U 1 1 5C9D0273
P 9350 6050
F 0 "#PWR0105" H 9350 5800 50  0001 C CNN
F 1 "GND" H 9355 5877 50  0000 C CNN
F 2 "" H 9350 6050 50  0001 C CNN
F 3 "" H 9350 6050 50  0001 C CNN
	1    9350 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	9600 5800 9350 5800
Wire Wire Line
	9350 5800 9350 5950
Wire Wire Line
	9600 5250 9350 5250
Wire Wire Line
	9350 5250 9350 5450
Connection ~ 9350 5800
Wire Wire Line
	9600 4700 9350 4700
Wire Wire Line
	9350 4700 9350 4850
Connection ~ 9350 5250
Wire Wire Line
	9600 4150 9350 4150
Wire Wire Line
	9350 4150 9350 4300
Connection ~ 9350 4700
Wire Wire Line
	9600 3600 9350 3600
Wire Wire Line
	9350 3600 9350 3750
Connection ~ 9350 4150
Wire Wire Line
	9600 3050 9350 3050
Wire Wire Line
	9350 3050 9350 3200
Connection ~ 9350 3600
Wire Wire Line
	9600 2500 9350 2500
Wire Wire Line
	9350 2500 9350 2650
Connection ~ 9350 3050
Wire Wire Line
	9600 1950 9350 1950
Wire Wire Line
	9350 1950 9350 2100
Connection ~ 9350 2500
$Comp
L MCU_Microchip_PIC16:PIC16F15323-IP U2
U 1 1 5C9F2E83
P 4450 3900
F 0 "U2" H 4650 4400 50  0000 C CNN
F 1 "PIC16F15323-IP" H 4800 3500 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 3800 4450 50  0001 C CNN
F 3 "" H 4550 4450 50  0001 C CNN
	1    4450 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	3600 5300 6300 5300
Wire Wire Line
	6650 5200 6200 5200
Wire Wire Line
	3400 5100 6100 5100
Wire Wire Line
	7650 3050 7900 3050
Wire Wire Line
	7900 3050 7900 4150
Wire Wire Line
	7900 4150 6300 4150
Wire Wire Line
	6300 4150 6300 5300
Connection ~ 6300 5300
Wire Wire Line
	6300 5300 6650 5300
Wire Wire Line
	7650 2950 8000 2950
Wire Wire Line
	8000 2950 8000 4050
Wire Wire Line
	8000 4050 6200 4050
Wire Wire Line
	6200 4050 6200 5200
Connection ~ 6200 5200
Wire Wire Line
	6200 5200 3500 5200
Wire Wire Line
	7650 2850 8100 2850
Wire Wire Line
	8100 2850 8100 3950
Wire Wire Line
	8100 3950 6100 3950
Wire Wire Line
	6100 3950 6100 5100
Connection ~ 6100 5100
Wire Wire Line
	6100 5100 6650 5100
Wire Wire Line
	7650 3250 7650 3550
Wire Wire Line
	7650 3550 7150 3550
$Comp
L power:GND #PWR0106
U 1 1 5CA0695C
P 7150 3650
F 0 "#PWR0106" H 7150 3400 50  0001 C CNN
F 1 "GND" H 7155 3477 50  0000 C CNN
F 2 "" H 7150 3650 50  0001 C CNN
F 3 "" H 7150 3650 50  0001 C CNN
	1    7150 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 3550 7150 3650
Connection ~ 7150 3550
$Comp
L power:+5V #PWR0107
U 1 1 5CA0901A
P 7150 1350
F 0 "#PWR0107" H 7150 1200 50  0001 C CNN
F 1 "+5V" H 7165 1523 50  0000 C CNN
F 2 "" H 7150 1350 50  0001 C CNN
F 3 "" H 7150 1350 50  0001 C CNN
	1    7150 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 1650 7150 1350
$Comp
L power:+5V #PWR0108
U 1 1 5CA0BCE1
P 4450 3150
F 0 "#PWR0108" H 4450 3000 50  0001 C CNN
F 1 "+5V" H 4465 3323 50  0000 C CNN
F 2 "" H 4450 3150 50  0001 C CNN
F 3 "" H 4450 3150 50  0001 C CNN
	1    4450 3150
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0109
U 1 1 5CA0BD32
P 8050 4300
F 0 "#PWR0109" H 8050 4150 50  0001 C CNN
F 1 "+5V" H 8065 4473 50  0000 C CNN
F 2 "" H 8050 4300 50  0001 C CNN
F 3 "" H 8050 4300 50  0001 C CNN
	1    8050 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 3150 4450 3350
$Comp
L power:GND #PWR0110
U 1 1 5CA0EC67
P 4450 4600
F 0 "#PWR0110" H 4450 4350 50  0001 C CNN
F 1 "GND" H 4455 4427 50  0000 C CNN
F 2 "" H 4450 4600 50  0001 C CNN
F 3 "" H 4450 4600 50  0001 C CNN
	1    4450 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 4050 5750 4050
Wire Wire Line
	5750 4050 5750 1950
Wire Wire Line
	5750 1950 6650 1950
Wire Wire Line
	6650 4850 5650 4850
Wire Wire Line
	5650 4850 5650 3850
Wire Wire Line
	5650 3850 5250 3850
Wire Wire Line
	9600 5600 7750 5600
Wire Wire Line
	7750 5600 7750 5250
Wire Wire Line
	9600 5050 9250 5050
Wire Wire Line
	9250 5050 9250 5150
Wire Wire Line
	9250 5150 7750 5150
Wire Wire Line
	7750 5050 9100 5050
Wire Wire Line
	9100 5050 9100 4500
Wire Wire Line
	9100 4500 9600 4500
Wire Wire Line
	9050 3950 9050 4950
Wire Wire Line
	9050 4950 7750 4950
Wire Wire Line
	7750 4850 8950 4850
Wire Wire Line
	8950 4850 8950 3400
Wire Wire Line
	8950 3400 9600 3400
Wire Wire Line
	9600 2850 8850 2850
Wire Wire Line
	8850 2850 8850 4750
Wire Wire Line
	8850 4750 7750 4750
Wire Wire Line
	7750 4650 8750 4650
Wire Wire Line
	8750 4650 8750 2300
Wire Wire Line
	8750 2300 9600 2300
Wire Wire Line
	9600 1750 8650 1750
Wire Wire Line
	8650 1750 8650 4550
Wire Wire Line
	8650 4550 7750 4550
Wire Wire Line
	9600 1850 9250 1850
Wire Wire Line
	7650 1850 7650 1950
Wire Wire Line
	7650 2050 8550 2050
Wire Wire Line
	8550 2050 8550 2400
Wire Wire Line
	8550 2400 9250 2400
Wire Wire Line
	9600 2950 9250 2950
Wire Wire Line
	9200 2950 9200 2150
Wire Wire Line
	9200 2150 7650 2150
Wire Wire Line
	9600 3500 9250 3500
Wire Wire Line
	9100 3500 9100 2500
Wire Wire Line
	9100 2500 8450 2500
Wire Wire Line
	8450 2500 8450 2250
Wire Wire Line
	8450 2250 7650 2250
Wire Wire Line
	9050 3950 9600 3950
Wire Wire Line
	8550 3600 8550 2600
Wire Wire Line
	8550 2600 8350 2600
Wire Wire Line
	8350 2600 8350 2350
Wire Wire Line
	8350 2350 7650 2350
Wire Wire Line
	9600 4600 9250 4600
Wire Wire Line
	9150 4600 9150 4150
Wire Wire Line
	9150 4150 8450 4150
Wire Wire Line
	8450 4150 8450 2700
Wire Wire Line
	8450 2700 8250 2700
Wire Wire Line
	8250 2700 8250 2450
Wire Wire Line
	8250 2450 7650 2450
Wire Wire Line
	9600 5150 9500 5150
Wire Wire Line
	9500 5150 9500 5200
Wire Wire Line
	9500 5200 9250 5200
Wire Wire Line
	8350 5200 8350 2750
Wire Wire Line
	8350 2750 8150 2750
Wire Wire Line
	8150 2750 8150 2550
Wire Wire Line
	8150 2550 7650 2550
Wire Wire Line
	9600 5700 9250 5700
Wire Wire Line
	8250 5700 8250 2800
Wire Wire Line
	8250 2800 8050 2800
Wire Wire Line
	8050 2800 8050 2650
Wire Wire Line
	8050 2650 7650 2650
$Comp
L power:GND #PWR0111
U 1 1 5CA86DD1
P 6500 5950
F 0 "#PWR0111" H 6500 5700 50  0001 C CNN
F 1 "GND" H 6505 5777 50  0000 C CNN
F 2 "" H 6500 5950 50  0001 C CNN
F 3 "" H 6500 5950 50  0001 C CNN
	1    6500 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 4550 6500 4550
Wire Wire Line
	6500 4550 6500 4700
Wire Wire Line
	6650 4700 6500 4700
Connection ~ 6500 4700
Wire Wire Line
	6500 4700 6500 5450
Wire Wire Line
	7200 5350 7200 5450
Wire Wire Line
	7200 5450 6500 5450
Connection ~ 6500 5450
Wire Wire Line
	6500 5450 6500 5950
Wire Wire Line
	8050 4300 7200 4300
Wire Wire Line
	7200 4300 7200 4450
NoConn ~ 6650 2050
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5CB04814
P 1650 1600
F 0 "#FLG0101" H 1650 1675 50  0001 C CNN
F 1 "PWR_FLAG" H 1650 1773 50  0000 C CNN
F 2 "" H 1650 1600 50  0001 C CNN
F 3 "~" H 1650 1600 50  0001 C CNN
	1    1650 1600
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 1600 1650 1850
Connection ~ 1650 1850
Wire Wire Line
	1650 1850 1950 1850
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5CB24F60
P 1950 2400
F 0 "#FLG0102" H 1950 2475 50  0001 C CNN
F 1 "PWR_FLAG" H 1950 2573 50  0000 C CNN
F 2 "" H 1950 2400 50  0001 C CNN
F 3 "~" H 1950 2400 50  0001 C CNN
	1    1950 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	1550 2400 1950 2400
$Comp
L Connector:Conn_01x06_Male J10
U 1 1 5C98B681
P 5450 1500
F 0 "J10" V 5512 1112 50  0000 R CNN
F 1 "ICSP" V 5603 1112 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 5450 1500 50  0001 C CNN
F 3 "~" H 5450 1500 50  0001 C CNN
	1    5450 1500
	0    -1   1    0   
$EndComp
Wire Wire Line
	5250 3750 5650 3750
Wire Wire Line
	5650 3750 5650 1700
Wire Wire Line
	5250 3650 5550 3650
Wire Wire Line
	5550 3650 5550 1700
Wire Wire Line
	5250 3950 5350 3950
Wire Wire Line
	5350 3950 5350 2450
Wire Wire Line
	5350 2450 5250 2450
Wire Wire Line
	5250 2450 5250 1700
$Comp
L power:+5V #PWR0112
U 1 1 5C9BAE85
P 4900 1700
F 0 "#PWR0112" H 4900 1550 50  0001 C CNN
F 1 "+5V" H 4915 1873 50  0000 C CNN
F 2 "" H 4900 1700 50  0001 C CNN
F 3 "" H 4900 1700 50  0001 C CNN
	1    4900 1700
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0113
U 1 1 5C9BC472
P 5450 1850
F 0 "#PWR0113" H 5450 1600 50  0001 C CNN
F 1 "GND" H 5455 1677 50  0000 C CNN
F 2 "" H 5450 1850 50  0001 C CNN
F 3 "" H 5450 1850 50  0001 C CNN
	1    5450 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5450 1700 5450 1850
Wire Wire Line
	5350 1700 5350 1800
Wire Wire Line
	5350 1800 4900 1800
Wire Wire Line
	4900 1800 4900 1700
NoConn ~ 5750 1700
Wire Wire Line
	3600 5300 3600 4150
Wire Wire Line
	3600 4150 3650 4150
Wire Wire Line
	3650 4050 3500 4050
Wire Wire Line
	3500 4050 3500 5200
Wire Wire Line
	3400 3950 3400 5100
Wire Wire Line
	3400 3950 3650 3950
$Comp
L Device:LED D2
U 1 1 5CAA566F
P 5350 4400
F 0 "D2" V 5297 4478 50  0000 L CNN
F 1 "RD_LED" V 5388 4478 50  0000 L CNN
F 2 "LED_THT:LED_D3.0mm" H 5350 4400 50  0001 C CNN
F 3 "~" H 5350 4400 50  0001 C CNN
	1    5350 4400
	0    1    1    0   
$EndComp
Wire Wire Line
	3100 3850 3650 3850
Wire Wire Line
	5250 4150 5350 4150
Wire Wire Line
	5350 4150 5350 4250
Wire Wire Line
	3100 3850 3100 4250
$Comp
L Device:LED D1
U 1 1 5CAA9A33
P 3100 4400
F 0 "D1" V 3047 4478 50  0000 L CNN
F 1 "YL_LED" V 3138 4478 50  0000 L CNN
F 2 "LED_THT:LED_D3.0mm" H 3100 4400 50  0001 C CNN
F 3 "~" H 3100 4400 50  0001 C CNN
	1    3100 4400
	0    1    1    0   
$EndComp
Wire Wire Line
	4450 4450 4450 4600
$Comp
L power:GND #PWR02
U 1 1 5CAE6080
P 5350 4550
F 0 "#PWR02" H 5350 4300 50  0001 C CNN
F 1 "GND" H 5355 4377 50  0000 C CNN
F 2 "" H 5350 4550 50  0001 C CNN
F 3 "" H 5350 4550 50  0001 C CNN
	1    5350 4550
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5CAEFD6F
P 3100 4550
F 0 "#PWR01" H 3100 4300 50  0001 C CNN
F 1 "GND" H 3105 4377 50  0000 C CNN
F 2 "" H 3100 4550 50  0001 C CNN
F 3 "" H 3100 4550 50  0001 C CNN
	1    3100 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1300 2150 1300 3650
Wire Wire Line
	1300 3650 2450 3650
Wire Wire Line
	1300 2050 1400 2050
Wire Wire Line
	1400 2050 1400 3750
Wire Wire Line
	1400 3750 2550 3750
$Comp
L Device:R_Small_US R3
U 1 1 5CA8511D
P 4900 2100
F 0 "R3" H 4968 2146 50  0000 L CNN
F 1 "10k" H 4968 2055 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P1.90mm_Vertical" H 4900 2100 50  0001 C CNN
F 3 "~" H 4900 2100 50  0001 C CNN
	1    4900 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 2200 4900 2450
Wire Wire Line
	4900 2450 5250 2450
Connection ~ 5250 2450
Wire Wire Line
	4900 2000 4900 1800
Connection ~ 4900 1800
$Comp
L Device:R_Small_US R1
U 1 1 5CA9A3D3
P 2450 2750
F 0 "R1" H 2518 2796 50  0000 L CNN
F 1 "4.7k" H 2518 2705 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P1.90mm_Vertical" H 2450 2750 50  0001 C CNN
F 3 "~" H 2450 2750 50  0001 C CNN
	1    2450 2750
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R2
U 1 1 5CA9B12A
P 2550 2750
F 0 "R2" H 2618 2796 50  0000 L CNN
F 1 "4.7k" H 2618 2705 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P1.90mm_Vertical" H 2550 2750 50  0001 C CNN
F 3 "~" H 2550 2750 50  0001 C CNN
	1    2550 2750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2550 3500 2550 3750
Connection ~ 2550 3750
Wire Wire Line
	2550 3750 3650 3750
Wire Wire Line
	2450 3500 2450 3650
Connection ~ 2450 3650
Wire Wire Line
	2450 3650 3650 3650
Wire Wire Line
	2550 3000 2550 2850
Wire Wire Line
	2450 2850 2450 3000
Wire Wire Line
	2450 2650 2550 2650
$Comp
L power:+5V #PWR03
U 1 1 5CB15674
P 2450 2500
F 0 "#PWR03" H 2450 2350 50  0001 C CNN
F 1 "+5V" H 2465 2673 50  0000 C CNN
F 2 "" H 2450 2500 50  0001 C CNN
F 3 "" H 2450 2500 50  0001 C CNN
	1    2450 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2450 2500 2450 2650
Connection ~ 2450 2650
$Comp
L Device:R_Small_US R4
U 1 1 5CB36306
P 9250 2000
F 0 "R4" H 9318 2046 50  0000 L CNN
F 1 "10k" H 9318 1955 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P1.90mm_Vertical" H 9250 2000 50  0001 C CNN
F 3 "~" H 9250 2000 50  0001 C CNN
	1    9250 2000
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R5
U 1 1 5CB370DB
P 9250 2550
F 0 "R5" H 9318 2596 50  0000 L CNN
F 1 "10k" H 9318 2505 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P1.90mm_Vertical" H 9250 2550 50  0001 C CNN
F 3 "~" H 9250 2550 50  0001 C CNN
	1    9250 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R6
U 1 1 5CB37BF9
P 9250 3100
F 0 "R6" H 9318 3146 50  0000 L CNN
F 1 "10k" H 9318 3055 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P1.90mm_Vertical" H 9250 3100 50  0001 C CNN
F 3 "~" H 9250 3100 50  0001 C CNN
	1    9250 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R7
U 1 1 5CB38471
P 9250 3650
F 0 "R7" H 9318 3696 50  0000 L CNN
F 1 "10k" H 9318 3605 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P1.90mm_Vertical" H 9250 3650 50  0001 C CNN
F 3 "~" H 9250 3650 50  0001 C CNN
	1    9250 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	9100 3600 8550 3600
Wire Wire Line
	9100 4050 9100 3600
Wire Wire Line
	9100 4050 9250 4050
$Comp
L Device:R_Small_US R8
U 1 1 5CB9194E
P 9250 4200
F 0 "R8" H 9318 4246 50  0000 L CNN
F 1 "10k" H 9318 4155 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P1.90mm_Vertical" H 9250 4200 50  0001 C CNN
F 3 "~" H 9250 4200 50  0001 C CNN
	1    9250 4200
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R9
U 1 1 5CB91EE6
P 9250 4750
F 0 "R9" H 9318 4796 50  0000 L CNN
F 1 "10k" H 9318 4705 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P1.90mm_Vertical" H 9250 4750 50  0001 C CNN
F 3 "~" H 9250 4750 50  0001 C CNN
	1    9250 4750
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R10
U 1 1 5CB9299F
P 9250 5350
F 0 "R10" H 9318 5396 50  0000 L CNN
F 1 "10k" H 9318 5305 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P1.90mm_Vertical" H 9250 5350 50  0001 C CNN
F 3 "~" H 9250 5350 50  0001 C CNN
	1    9250 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R11
U 1 1 5CB9E4E4
P 9250 5850
F 0 "R11" H 9318 5896 50  0000 L CNN
F 1 "10k" H 9318 5805 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P1.90mm_Vertical" H 9250 5850 50  0001 C CNN
F 3 "~" H 9250 5850 50  0001 C CNN
	1    9250 5850
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 2650 9350 2650
Connection ~ 9350 2650
Wire Wire Line
	9350 2650 9350 3050
Wire Wire Line
	9250 3200 9350 3200
Connection ~ 9350 3200
Wire Wire Line
	9350 3200 9350 3600
Wire Wire Line
	9250 3750 9350 3750
Connection ~ 9350 3750
Wire Wire Line
	9350 3750 9350 4150
Wire Wire Line
	9250 4300 9350 4300
Connection ~ 9350 4300
Wire Wire Line
	9350 4300 9350 4700
Wire Wire Line
	9250 4850 9350 4850
Connection ~ 9350 4850
Wire Wire Line
	9350 4850 9350 5250
Wire Wire Line
	9250 5450 9350 5450
Connection ~ 9350 5450
Wire Wire Line
	9350 5450 9350 5800
Wire Wire Line
	9250 5950 9350 5950
Connection ~ 9350 5950
Wire Wire Line
	9350 5950 9350 6050
Wire Wire Line
	9250 5750 9250 5700
Connection ~ 9250 5700
Wire Wire Line
	9250 5700 8250 5700
Wire Wire Line
	9250 5250 9250 5200
Connection ~ 9250 5200
Wire Wire Line
	9250 5200 8350 5200
Wire Wire Line
	9250 4650 9250 4600
Connection ~ 9250 4600
Wire Wire Line
	9250 4600 9150 4600
Wire Wire Line
	9250 4100 9250 4050
Connection ~ 9250 4050
Wire Wire Line
	9250 4050 9600 4050
Wire Wire Line
	9250 3550 9250 3500
Connection ~ 9250 3500
Wire Wire Line
	9250 3500 9100 3500
Wire Wire Line
	9250 3000 9250 2950
Connection ~ 9250 2950
Wire Wire Line
	9250 2950 9200 2950
Wire Wire Line
	9250 2450 9250 2400
Connection ~ 9250 2400
Wire Wire Line
	9250 2400 9600 2400
Wire Wire Line
	9250 2100 9350 2100
Connection ~ 9350 2100
Wire Wire Line
	9350 2100 9350 2500
Wire Wire Line
	9250 1900 9250 1850
Connection ~ 9250 1850
Wire Wire Line
	9250 1850 7650 1850
NoConn ~ 2750 3250
$Comp
L Connector_Generic:Conn_02x02_Odd_Even J11
U 1 1 5CAA9E90
P 2550 3200
F 0 "J11" V 2554 3280 50  0000 L CNN
F 1 "Conn_02x02_Odd_Even" V 2645 3280 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x02_P2.54mm_Vertical" H 2550 3200 50  0001 C CNN
F 3 "~" H 2550 3200 50  0001 C CNN
	1    2550 3200
	0    1    1    0   
$EndComp
$EndSCHEMATC
