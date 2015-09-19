#include "Robot_APIs/PAL3G4200D.h"
#include "Robot_APIs/GC6050.h"
#include <boards.h>
#include <usb_serial.h>
#include <HardwareSPI.h>
#include <wirish_time.h>

int main(int __attribute__((unused)) argc, const char __attribute__((unused)) * argv[])
{
    init();
    SerialUSB.begin();
    SerialUSB.read();
    PAL3G4200D gyro(I2CDevice::Pin::I2C1);
    GC6050 gyroAccel(I2CDevice::Pin::I2C1);
    while (1) {
        SerialUSB.println(gyro.readZ());
    }
    
    return 0;
}
