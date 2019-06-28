#include "hwlib.hpp"

#include "../library/headers/neopixel_due.hpp"
#include "../library/headers/HC_SR04.hpp"
#include "../library/headers/helpmath.hpp"
#include "../library/headers/HC_12_due.hpp"

int main()
{
    auto trig = hwlib::target::pin_out( hwlib::target::pins::d3 );
    auto echo = hwlib::target::pin_in( hwlib::target::pins::d2 );

    HC_SR04 ultra_module(trig, echo);

    auto tx = hwlib::target::pin_out( hwlib::target::pins::d4 );
    auto rx = hwlib::target::pin_in( hwlib::target::pins::d5 );

    HC_12_due rf_module(tx, rx);

    int n_leds = 30;
    neopixel_due strip( n_leds );

    int loopCount = 0;
    int led_index = 0;

    int reading_ultra_module;
    int mapped_reading;

    for(;;) {
        if (loopCount%64 == 0) {
            ultra_module.refresh();
            reading_ultra_module = ultra_module.readCM();
        }

        if (loopCount%64 == 0) {
            rf_module.send((uint8_t)map(reading_ultra_module, 1, 250, 1, 255));
            rf_module.flush();
        }

        if (loopCount%128 == 0) {
            hwlib::cout << reading_ultra_module << "\n" << hwlib::flush;
        }

        if (loopCount%(map(reading_ultra_module, 10, 250, 16, 64)) == 0) {
            strip.write((led_index+n_leds-1)%n_leds, 0, 0, 0);
            strip.write((led_index+n_leds-1+10)%n_leds, 0, 0, 0);
            strip.write((led_index+n_leds-1+20)%n_leds, 0, 0, 0);

            mapped_reading = map(reading_ultra_module, 1, 50, 150, 0);
            for(int i = 0; i < n_leds; i++) {
                strip.write(i, mapped_reading, 0, 0);
            }
            
            strip.write(led_index, 255, 64, 0);
            strip.write((led_index+10)%n_leds, 255, 64, 0);
            strip.write((led_index+20)%n_leds, 255, 64, 0);
            
            strip.flush();
            led_index = (led_index + 1) % n_leds;
        }

        loopCount = (loopCount + 1) % 1024;
        hwlib::wait_ms(1);
    }
}