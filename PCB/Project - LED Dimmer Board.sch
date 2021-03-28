EESchema Schematic File Version 4
EELAYER 30 0
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
L power:GND #PWR0104
U 1 1 5F8B3D3E
P 6950 -350
F 0 "#PWR0104" H 6950 -600 50  0001 C CNN
F 1 "GND" H 6955 -523 50  0000 C CNN
F 2 "" H 6950 -350 50  0001 C CNN
F 3 "" H 6950 -350 50  0001 C CNN
	1    6950 -350
	1    0    0    -1  
$EndComp
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5F8B42FF
P 6500 -350
F 0 "#FLG0101" H 6500 -275 50  0001 C CNN
F 1 "PWR_FLAG" H 6500 -177 50  0000 C CNN
F 2 "" H 6500 -350 50  0001 C CNN
F 3 "~" H 6500 -350 50  0001 C CNN
	1    6500 -350
	1    0    0    -1  
$EndComp
$Comp
L power:GNDPWR #PWR0105
U 1 1 5F837002
P 6950 -350
F 0 "#PWR0105" H 6950 -550 50  0001 C CNN
F 1 "GNDPWR" H 6955 -505 50  0000 C CNN
F 2 "" H 6950 -400 50  0001 C CNN
F 3 "" H 6950 -400 50  0001 C CNN
	1    6950 -350
	-1   0    0    1   
$EndComp
$Comp
L Connector:Barrel_Jack J4
U 1 1 6013D8F3
P 4500 1275
F 0 "J4" H 4557 1600 50  0000 C CNN
F 1 "Barrel_Jack" H 4557 1509 50  0000 C CNN
F 2 "Connector_BarrelJack:BarrelJack_CUI_PJ-102AH_Horizontal" H 4550 1235 50  0001 C CNN
F 3 "~" H 4550 1235 50  0001 C CNN
	1    4500 1275
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 1175 4900 1175
Wire Wire Line
	4800 1375 5025 1375
Wire Wire Line
	9525 1300 9875 1300
Wire Wire Line
	9875 1600 9525 1600
NoConn ~ 5825 3325
NoConn ~ 6425 3125
NoConn ~ 6525 3125
NoConn ~ 6825 3525
NoConn ~ 6825 3625
NoConn ~ 6825 3925
NoConn ~ 6825 4125
NoConn ~ 6825 4225
NoConn ~ 6825 4325
NoConn ~ 6825 4425
NoConn ~ 6825 4525
NoConn ~ 6825 4625
NoConn ~ 6825 4725
NoConn ~ 6825 4825
NoConn ~ 5825 4825
NoConn ~ 5825 4725
NoConn ~ 5825 4625
NoConn ~ 5825 4225
NoConn ~ 5825 4125
NoConn ~ 5825 3925
NoConn ~ 5825 3825
NoConn ~ 5825 3425
Wire Wire Line
	9525 2200 9875 2200
Wire Wire Line
	9525 2500 9875 2500
Wire Wire Line
	9525 3450 9825 3450
Wire Wire Line
	9525 3150 9825 3150
$Comp
L power:GND #PWR0102
U 1 1 60128EA7
P 5700 1375
F 0 "#PWR0102" H 5700 1125 50  0001 C CNN
F 1 "GND" H 5705 1202 50  0000 C CNN
F 2 "" H 5700 1375 50  0001 C CNN
F 3 "" H 5700 1375 50  0001 C CNN
	1    5700 1375
	1    0    0    -1  
$EndComp
Connection ~ 5700 1375
Wire Wire Line
	5700 1375 6050 1375
$Comp
L power:+9V #PWR0101
U 1 1 6012A575
P 6500 -350
F 0 "#PWR0101" H 6500 -500 50  0001 C CNN
F 1 "+9V" H 6515 -177 50  0000 C CNN
F 2 "" H 6500 -350 50  0001 C CNN
F 3 "" H 6500 -350 50  0001 C CNN
	1    6500 -350
	-1   0    0    1   
$EndComp
$Comp
L power:+9V #PWR0103
U 1 1 6012D82A
P 5700 1175
F 0 "#PWR0103" H 5700 1025 50  0001 C CNN
F 1 "+9V" H 5715 1348 50  0000 C CNN
F 2 "" H 5700 1175 50  0001 C CNN
F 3 "" H 5700 1175 50  0001 C CNN
	1    5700 1175
	1    0    0    -1  
$EndComp
Connection ~ 5700 1175
Wire Wire Line
	5700 1175 6050 1175
$Comp
L power:GND #PWR0106
U 1 1 6013179A
P 6900 1375
F 0 "#PWR0106" H 6900 1125 50  0001 C CNN
F 1 "GND" H 6905 1202 50  0000 C CNN
F 2 "" H 6900 1375 50  0001 C CNN
F 3 "" H 6900 1375 50  0001 C CNN
	1    6900 1375
	0    -1   -1   0   
$EndComp
$Comp
L VPB_Library:AdafruitCoolPushbutton U4
U 1 1 60139770
P 6500 1325
F 0 "U4" H 6475 1740 50  0000 C CNN
F 1 "AdafruitCoolPushbutton" H 6475 1649 50  0000 C CNN
F 2 "VPB_footprint:AdafruitCoolPushbutton" H 6500 1475 50  0001 C CNN
F 3 "" H 6500 1475 50  0001 C CNN
	1    6500 1325
	1    0    0    -1  
$EndComp
$Comp
L VPB_Library:MeanWellLDD-300L U1
U 1 1 6013A4BC
P 9125 1450
F 0 "U1" H 9150 1865 50  0000 C CNN
F 1 "MeanWellLDD-###L" H 9150 1774 50  0000 C CNN
F 2 "VPB_footprint:Meanwell-LDD" H 9225 1450 50  0001 C CNN
F 3 "" H 9225 1450 50  0001 C CNN
	1    9125 1450
	1    0    0    -1  
$EndComp
$Comp
L VPB_Library:MeanWellLDD-300L U2
U 1 1 6013B170
P 9125 2350
F 0 "U2" H 9150 2765 50  0000 C CNN
F 1 "MeanWellLDD-###L" H 9150 2674 50  0000 C CNN
F 2 "VPB_footprint:Meanwell-LDD" H 9225 2350 50  0001 C CNN
F 3 "" H 9225 2350 50  0001 C CNN
	1    9125 2350
	1    0    0    -1  
$EndComp
$Comp
L VPB_Library:MeanWellLDD-300L U3
U 1 1 6013BA28
P 9125 3300
F 0 "U3" H 9150 3715 50  0000 C CNN
F 1 "MeanWellLDD-###L" H 9150 3624 50  0000 C CNN
F 2 "VPB_footprint:Meanwell-LDD" H 9225 3300 50  0001 C CNN
F 3 "" H 9225 3300 50  0001 C CNN
	1    9125 3300
	1    0    0    -1  
$EndComp
$Comp
L VPB_Library:SpacedSolderHoles J1
U 1 1 6013C1F5
P 10075 1400
F 0 "J1" H 10155 1392 50  0000 L CNN
F 1 "SpacedSolderHoles" H 10155 1301 50  0000 L CNN
F 2 "VPB_footprint:TwoSpacedPins" H 10075 1400 50  0001 C CNN
F 3 "~" H 10075 1400 50  0001 C CNN
	1    10075 1400
	1    0    0    -1  
$EndComp
$Comp
L VPB_Library:SpacedSolderHoles J2
U 1 1 6013D399
P 10075 2300
F 0 "J2" H 10155 2292 50  0000 L CNN
F 1 "SpacedSolderHoles" H 10155 2201 50  0000 L CNN
F 2 "VPB_footprint:TwoSpacedPins" H 10075 2300 50  0001 C CNN
F 3 "~" H 10075 2300 50  0001 C CNN
	1    10075 2300
	1    0    0    -1  
$EndComp
$Comp
L VPB_Library:SpacedSolderHoles J3
U 1 1 6013E636
P 10025 3250
F 0 "J3" H 10105 3242 50  0000 L CNN
F 1 "SpacedSolderHoles" H 10105 3151 50  0000 L CNN
F 2 "VPB_footprint:TwoSpacedPins" H 10025 3250 50  0001 C CNN
F 3 "~" H 10025 3250 50  0001 C CNN
	1    10025 3250
	1    0    0    -1  
$EndComp
$Comp
L MCU_Module:Arduino_Nano_Every A1
U 1 1 60148AFF
P 6325 4125
F 0 "A1" H 6325 2944 50  0000 C CNN
F 1 "Arduino_Nano_Every" H 6325 3035 50  0000 C CNN
F 2 "VPB_footprint:Arduino_Nano_Every_Silkscreen" H 6325 4125 50  0001 C CIN
F 3 "https://content.arduino.cc/assets/NANOEveryV3.0_sch.pdf" H 6325 4125 50  0001 C CNN
	1    6325 4125
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 1675 5450 1675
NoConn ~ 5825 4425
Text GLabel 5750 3625 0    50   Input ~ 0
shutdownPin
Wire Wire Line
	5750 3625 5825 3625
Wire Wire Line
	6050 1475 6050 1675
$Comp
L power:+9V #PWR0107
U 1 1 6014FAFA
P 6900 1175
F 0 "#PWR0107" H 6900 1025 50  0001 C CNN
F 1 "+9V" H 6915 1348 50  0000 C CNN
F 2 "" H 6900 1175 50  0001 C CNN
F 3 "" H 6900 1175 50  0001 C CNN
	1    6900 1175
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR0108
U 1 1 6015F119
P 8775 1600
F 0 "#PWR0108" H 8775 1350 50  0001 C CNN
F 1 "GND" H 8780 1427 50  0000 C CNN
F 2 "" H 8775 1600 50  0001 C CNN
F 3 "" H 8775 1600 50  0001 C CNN
	1    8775 1600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0109
U 1 1 6015F74A
P 6325 5125
F 0 "#PWR0109" H 6325 4875 50  0001 C CNN
F 1 "GND" V 6330 4997 50  0000 R CNN
F 2 "" H 6325 5125 50  0001 C CNN
F 3 "" H 6325 5125 50  0001 C CNN
	1    6325 5125
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR0110
U 1 1 60160441
P 8775 3450
F 0 "#PWR0110" H 8775 3200 50  0001 C CNN
F 1 "GND" H 8780 3277 50  0000 C CNN
F 2 "" H 8775 3450 50  0001 C CNN
F 3 "" H 8775 3450 50  0001 C CNN
	1    8775 3450
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0111
U 1 1 60160F1B
P 8775 2500
F 0 "#PWR0111" H 8775 2250 50  0001 C CNN
F 1 "GND" H 8780 2327 50  0000 C CNN
F 2 "" H 8775 2500 50  0001 C CNN
F 3 "" H 8775 2500 50  0001 C CNN
	1    8775 2500
	1    0    0    -1  
$EndComp
Text GLabel 5450 1675 0    50   Input ~ 0
shutdownPin
Text GLabel 6900 1275 2    50   Input ~ 0
Controlled9V
Text GLabel 6050 1275 0    50   Input ~ 0
Controlled9V
Text GLabel 6225 3125 1    50   Input ~ 0
Controlled9V
Text GLabel 8775 1300 0    50   Input ~ 0
Controlled9V
Text GLabel 8775 2200 0    50   Input ~ 0
Controlled9V
Text GLabel 8775 3150 0    50   Input ~ 0
Controlled9V
Text GLabel 5825 3725 0    50   Input ~ 0
ledPin1
Text GLabel 5825 4025 0    50   Input ~ 0
ledPin2
Text GLabel 5825 4325 0    50   Input ~ 0
ledPin3
Text GLabel 8775 1450 0    50   Input ~ 0
ledPin1
Text GLabel 8775 2350 0    50   Input ~ 0
ledPin2
Text GLabel 8775 3300 0    50   Input ~ 0
ledPin3
NoConn ~ 6900 1475
$Comp
L Connector:Screw_Terminal_01x02 J5
U 1 1 6016D4D8
P 5225 750
F 0 "J5" H 5305 742 50  0000 L CNN
F 1 "9V Pwr" H 5305 651 50  0000 L CNN
F 2 "VPB_footprint:ScrewTerminal9VLabel" H 5225 750 50  0001 C CNN
F 3 "~" H 5225 750 50  0001 C CNN
	1    5225 750 
	1    0    0    -1  
$EndComp
Wire Wire Line
	5025 850  5025 1375
Connection ~ 5025 1375
Wire Wire Line
	5025 1375 5700 1375
Wire Wire Line
	5025 750  4900 750 
Wire Wire Line
	4900 750  4900 1175
Connection ~ 4900 1175
Wire Wire Line
	4900 1175 5700 1175
$EndSCHEMATC
