#include "hwlib.hpp"
#include "../library/headers/HC_12_uno.hpp"
#include "../library/headers/neopixel_uno.hpp"
#include "../library/headers/GRB_decorator.hpp"
#include "../library/headers/helpmath.hpp"

int main()
{
    auto tx = hwlib::target::pin_out( hwlib::target::pins::d2 );
    auto rx = hwlib::target::pin_in( hwlib::target::pins::d3);

    HC_12_uno module(tx, rx);

    int n_leds = 12;
    neopixel_uno grb_strip( n_leds );
    neopixel_grb strip( grb_strip );

    int strip_index = 0;
    uint8_t rf_data = 0;
    int loopCount = 0;
    uint8_t reading;
    uint8_t mapped_reading = 0;

    for (;;)
    {
        if(loopCount%512 == 0) {
            char return_reading = module.read();

            if(return_reading != '\0') {
                reading = (uint8_t) return_reading;
                hwlib::cout << reading << '\n' << hwlib::flush;
                rf_data = return_reading;

                mapped_reading = map(rf_data, 20, 100, 255, 0);
            }
            for(int i = 0; i < n_leds; i++) {
                strip.write(i, mapped_reading, 0, 0);
            }
        }


        if(loopCount%8192 == 0) {
            for (int i = 0; i < n_leds; i++) {
                strip.write(i, 255, 64, 0);
            }
        }

        if(loopCount%8192 == 400) {
            for (int i = 0; i < n_leds; i++) {
                strip.write(i, mapped_reading, 0, 0);
            }
        }

        if(loopCount%512 == 0) {
            strip.write((strip_index+n_leds-1)%n_leds, 0, 0, 0);
            strip.write(strip_index, 255, 64, 0);

            strip_index = (strip_index + 1) % n_leds;
        }

        if(loopCount%256 == 0) {
            strip.flush();
        }


        loopCount = (loopCount + 1) % 32768;
    }
}