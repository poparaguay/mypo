# MyPO

rodi-web
========
Aca escribir una descripción de MyPO

API
----

* Blink

    

* Sense

    ```

* Move

    ```

* Sense Light

    ```
    GET /7/
    ```

    ```
    GET /8/<state[0|1]>
    ```

    Turns the onboard led on or off.

    ie.,
    ```
    curl --get http://192.168.4.1:1234/8/0/    // turns the onboard led off
    curl --get http://192.168.4.1:1234/8/1/    // turns the onbboard led on
    ```


Authors
----------
* Martin Abente Lahaye - tch@sugarlabs.org
* Gary Servin - garyservin@gmail.com

Cool Stuff
-------------------
I recommend Turtle Blocks Javascript as a client for RoDi-web. Grab the latest
bits from https://github.com/walterbender/turtleblocksjs. Don't forget to load
