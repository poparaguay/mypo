# MyPO Board

Myo Armband + PO Paraguay
========
A board that connects the different parts of the system, demonimated MyPo. It is the interface between the Myo Armband sensor and the advanced prosthetic. It is composed of an Arduino board and a Bluetooth 4.0 module, with a custom firmware. Next are the different parts that compose this board.

Components
----

* MyPo Board
    ```
    
    Designed by Po Paraguay and manufactured by https://oshpark.com/ by uploading the mypo.brd file to the webpage
    
    Allows to flash the bluetooth module from the board itself
    
    ```
* Bluetooth BLE HM-11 CC2541 SoC 
    ```
    
    Flash the board by following these steps: https://github.com/RedBearLab/CCLoader
    
    Flash this file  "MyoBridge_CC2541.hex" to the CC2541 chip
     
    ```
* Arduino Pro Mini 328 5V/16Mhz.
* MicroServo 

    ```
    
    3 x TowerPro MG92B.  (Torque (4.8v): 3.1kg/cm - (6.0v): 3.5kg/cm)
    
    ```
    
* Battery: Li-Ion 1S 2500mAh 18650 
* Charge/Discharge module with voltage protection:


    ```
    http://goo.gl/Kd2iIu 
    
    ```
* 3.3V Regulator
    ```
AMS11171A LOW DROPOUT VOLTAGE REGULATOR 
http://www.advanced-monolithic.com/pdf/ds1117.pdf
    ```


*Passive components SMD  (0805: 0.08" × 0.05" (2,0 mm × 1,25 mm)  1/8 W)
    ```
- Resistors 1R/2R, where 1R is the value of any resistor and 2R is the double of that
-  100nF Capacitor
    ```
    

Characteristics
----

* Does not need an external computer to run
* The actual processing of the data is done by the Myo armband
* Uses the MyoBridge library:
    ```
    https://github.com/vroland/MyoBridge 
    ```
* Independent control of up to 3 servos: 
    ```
    SERVO1 : Port 5
    
    SERVO2 : Port 6
    
    GPIO1  : Port 9
    
    ```
* Virtual communication (Bluetooth - Arduino)
    ```
    
    RX Arduino to TX Bluetooth : Port 2
    
    TX Arduino to RX Bluetooth : Port 3
   
    ```

    

Author
----------
* Mateo Acosta - macosta@po.com.py



