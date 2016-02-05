toggleBluetooth
===============

Toggle the Bluetooth state on OS X.  
Attention: uses OS X private API.

How to build
------------

    xcodebuild

How to use
----------

 * `toggleBluetooth` toggles Bluetooth on or off.  
    Returns `0` on success, `1` if the Bluetooth state could not
    be changed.
 * `toggleBluetooth status` prints whether Bluetooth is on or off.

License
-------

CC0 1.0 Universal
