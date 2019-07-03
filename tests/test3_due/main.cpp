#include "hwlib.hpp"

#include "../../library/headers/neopixel_due.hpp"

// Tests for neopixel_due class

int main() {
    int n_leds = 12;
    neopixel_due strip( n_leds );

    hwlib::cout << "<wave demo function>\n" << hwlib::flush; 
    strip.wave();
}