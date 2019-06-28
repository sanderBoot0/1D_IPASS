#include "../headers/neopixel.hpp" 

void neopixel::write(uint8_t p_leds[100][3])
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

void neopixel::write(uint8_t led_index, uint8_t red, uint8_t green, uint8_t blue) {
    leds[led_index][0] = red;
    leds[led_index][1] = green;
    leds[led_index][2] = blue;
    something_changed = true;
}