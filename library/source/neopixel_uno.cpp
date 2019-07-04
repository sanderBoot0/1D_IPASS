#include "hwlib.hpp"
#include "../headers/neopixel_uno.hpp"

/// The idea of how to flush is from:\n\t
/// kevindarrah.com/download/arduino_code/WS1812_V4_FOR_VIDEO.ino
void neopixel_uno::flush()
{
    auto old_port = PORTB;
    for (uint8_t i = 0; i < n_leds; i++)
    {
        for (uint8_t j = 0; j < 3; j++)
        {
            PORTB = 0b00000001;
            PORTB = ((leds[i][j] & 0x80) && 0x80) | old_port;
            __asm__("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
            PORTB = 0b00000000;
            __asm__("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");

            PORTB = 0b00000001;
            PORTB = ((leds[i][j] & 0x40) && 0x40) | old_port;
            __asm__("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
            PORTB = 0b00000000;
            __asm__("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");

            PORTB = 0b00000001;
            PORTB = ((leds[i][j] & 0x20) && 0x20) | old_port;
            __asm__("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
            PORTB = 0b00000000;
            __asm__("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");

            PORTB = 0b00000001;
            PORTB = ((leds[i][j] & 0x10) && 0x10) | old_port;
            __asm__("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
            PORTB = 0b00000000;
            __asm__("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");

            PORTB = 0b00000001;
            PORTB = ((leds[i][j] & 0x8) && 0x8) | old_port;
            __asm__("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
            PORTB = 0b00000000;
            __asm__("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");

            PORTB = 0b00000001;
            PORTB = ((leds[i][j] & 0x4) && 0x4) | old_port;
            __asm__("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
            PORTB = 0b00000000;
            __asm__("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");

            PORTB = 0b00000001;
            PORTB = ((leds[i][j] & 0x2) && 0x2) | old_port;
            __asm__("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
            PORTB = 0b00000000;
            __asm__("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");

            PORTB = 0b00000001;
            PORTB = ((leds[i][j] & 0x1) && 0x1) | old_port;
            __asm__("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
            PORTB = 0b00000000;
            __asm__("nop\n\tnop\n\tnop\n\tnop\n\tnop\n\t");
        }
    }
    something_changed = false;
    hwlib::wait_us(1);
}