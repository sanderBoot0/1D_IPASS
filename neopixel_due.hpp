#ifndef NEOPIXEL_DUE_HPP
#define NEOPIXEL_DUE_HPP

#include "hwlib.hpp"
#include "neopixel.hpp"

#define register 
#include "sam.h"
#undef register

class neopixel_due : public neopixel {
public:
    neopixel_due(const int &n_leds): 
        neopixel( n_leds ) 
    {
        WDT->WDT_MR = WDT_MR_WDDIS;

        PIOC->PIO_OER = 0x400000;
        PIOC->PIO_CODR = 0x400000;
        hwlib::wait_us(1);
    }

    void flush() override;
};

#endif // NEOPIXEL_DUE_HPP