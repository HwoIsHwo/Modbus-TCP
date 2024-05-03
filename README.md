# Modbus-TCP
Modbus TCP client and server

To work you need to install:
**libmodbus** from https://libmodbus.org/
ARM compiler with 

`sudo apt-get install gcc-arm-linux-gnueabi`

To compile run `make` or `make GCC=1` if you don`t want to compile for ARM.
Remember that to build for ARM you need to reinstall libmodbus:

```
./configure --host=arm-linux-gnueabi
make
make install
```

If you want to return to GCC, install libmodbus using default way.
