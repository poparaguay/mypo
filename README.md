# MyPO

Myo Armband + PO Paraguay
========
Placa que interconecta todas las etapas del sistema, denominada MyPO, es la interfaz entre el sensor Myo y una prótesis avanzada. Está compuesta por un circuito Arduino y un módulo Bluetooth 4.0 con el firmware modificado. Seguidamente se detallan todas las partes que componen la placa MyPO.

Componentes
----

* Placa MyPO 
* Bluetooth BLE HM-11 CC2541 SoC 
* Arduino Pro Mini 328 5V/16Mhz.
* MicroServo 

    ```
    
    *  3 x TowerPro MG92B.  (Torque (4.8v): 3.1kg/cm - (6.0v): 3.5kg/cm)
    
    ```
    
* Bateria Li-Ion 1S 2500mAh 18650 
* Modulo de carga/descarga con protección de bateria 


    ```
    *  http://goo.gl/Kd2iIu 
    
    ```
    

Caracteristicas
----

* No necesita Computadora externa para funcionar
* El procesamiento de la señal se realiza en el brazalete Myo 
* Utiliza la libreria MyoBridge 
    ```
    https://github.com/vroland/MyoBridge 
    ```
* Control independiente hasta 3 servomotores: 
    ```
    SERVO1 : Port 5
    
    SERVO2 : Port 6
    
    GPIO1  : Port 9
    
    ```
* Comunicación Virtual (Bluetooth - Arduino)
    ```
    
    RX Arduino to TX Bluetooth : Port 2
    
    TX Arduino to RX Bluetooth : Port 3
   
    ```

    

Autor
----------
* Mateo Acosta - macosta@po.com.py



