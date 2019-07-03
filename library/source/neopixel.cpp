#include "../headers/neopixel.hpp" 

void neopixel::write( const uint8_t p_leds[][3] )
{
    for (int i = 0; i < n_leds; i++)
    {
        for (uint8_t j = 0; j < 3; j++)
        {
            leds[i][j] = p_leds[i][j];
        }
    }
    something_changed = true;
}

void neopixel::write( const uint8_t led_index, const uint8_t red, const uint8_t green, const uint8_t blue ) {
    leds[led_index][0] = red;
    leds[led_index][1] = green;
    leds[led_index][2] = blue;
    something_changed = true;
}

void neopixel::write_all( const uint8_t red, const uint8_t green, const uint8_t blue ) {
    for (int i = 0; i < n_leds; i++)
    {
        leds[i][0] = red;
        leds[i][1] = green;
        leds[i][2] = blue;
    }
}

void neopixel::clear( ) {
    write_all(0, 0, 0);
    flush();
}

void neopixel::wave( const int ms ) {
    for(;;) {
        for(int i = 0; i < 256; i++) {
            write_all(255, i, 0); flush();
            hwlib::wait_ms(ms);
        }
        for(int i = 255; i >= 0; i--) {
            write_all(i, 255, 0); flush();
            hwlib::wait_ms(ms);
        }
        for(int i = 0; i < 256; i++) {
            write_all(0, 255, i); flush();
            hwlib::wait_ms(ms);
        }
        for(int i = 255; i >= 0; i--) {
            write_all(0, i, 255); flush();
            hwlib::wait_ms(ms);
        }
        for(int i = 0; i < 256; i++) {
            write_all(i, 0, 255); flush();
            hwlib::wait_ms(ms);
        }
        for(int i = 255; i >= 0; i--) {
            write_all(255, 0, i); flush();
            hwlib::wait_ms(ms);
        }
    }
}

void neopixel::flash( const int ms ) {
    for(;;) {
        write_all(255, 0, 0); flush();
        hwlib::wait_ms(ms);

        write_all(0, 255, 0); flush();
        hwlib::wait_ms(ms);

        write_all(0, 0, 255); flush();
        hwlib::wait_ms(ms);
    }
}