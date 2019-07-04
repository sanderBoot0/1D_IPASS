int main() {
    int n_leds = 30;
    // for the due:
    neopixel_due strip( n_leds );
    // for the uno:
    neopixel_uno strip( n_leds );

    // write all leds
    strip.write_all(255, 0, 0); 
    strip.flush();

    // write specific led
    strip.write(5, 100, 200, 0);
    strip.flush();

    // all black, automatic flush
    strip.clear();

    // using an array
    uint8_t array[n_leds][3];
    for(auto &led : array) {
        for(auto &col : led) {
            col = 0;
        }
    }

    array[1][2] = 255;
    strip.write(array);
    strip.flush();

    // demo functions, both infinite loops
    strip.flash();
    strip.wave();
}