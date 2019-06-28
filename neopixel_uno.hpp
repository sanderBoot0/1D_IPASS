#ifndef NEOPIXEL_UNO_HPP
#define NEOPIXEL_UNO_HPP

#include "hwlib.hpp"
#include "neopixel.hpp"

class neopixel_uno : public neopixel {
public:
    neopixel_uno(const int &n_leds): 
        neopixel( n_leds ) 
    {
        DDRB = DDRB | 0b00000001;
        PORTB = 0b00000000;
        hwlib::wait_ms(1);
    }

    void flush() override;
};

#endif // NEOPIXEL_UNO_HPP