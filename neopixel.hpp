#ifndef NEOPIXEL_HPP
#define NEOPIXEL_HPP

#include "hwlib.hpp"

class neopixel
{
protected:
    const int n_leds;
    uint8_t leds[100][3];
    bool something_changed = false;

public:
    neopixel(const int &n_leds):
        n_leds( n_leds )
    {}

    void write(uint8_t p_leds[100][3]);
    void write(uint8_t led_index, uint8_t red, uint8_t green, uint8_t blue);

    virtual void flush();
};

#endif // NEOPIXEL_HPP