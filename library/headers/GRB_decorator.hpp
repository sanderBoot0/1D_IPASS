#ifndef GRB_DECORATOR_HPP
#define GRB_DECORATOR_HPP

#include "hwlib.hpp"
#include "neopixel.hpp"

class neopixel_grb {
private:
    neopixel & slave;

public:
    neopixel_grb( neopixel & p_slave ): 
        slave( p_slave ) 
    {}

    void write (uint8_t p_leds[100][3]) {
        slave.write(p_leds);
    }

    void write (uint8_t led_index, uint8_t red, uint8_t green, uint8_t blue) {
        slave.write(led_index, green, red, blue);
    }

    void flush () {
        slave.flush();
    }
};

#endif // GRB_DECORATOR_HPP