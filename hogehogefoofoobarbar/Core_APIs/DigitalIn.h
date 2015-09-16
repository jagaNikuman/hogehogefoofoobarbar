#ifndef __DigitalIn__
#define __DigitalIn__

#include <stdint.h>
#include <boards.h>
#include <io.h>

class DigitalIn {
    volatile uint32_t *IDR;
    uint32_t bit;
    
public:
    DigitalIn(uint8_t pin, WiringPinMode mode = INPUT);
    bool read() {
        return *IDR & bit;
    }
    operator bool () {
        return read();
    }
};

#endif