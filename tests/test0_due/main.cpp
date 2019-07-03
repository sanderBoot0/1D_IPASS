#include "hwlib.hpp"

#include "../../library/headers/neopixel_due.hpp"

// Tests for neopixel_due class

void printFunc(int i, char color, int n_leds) {
    for(int j = 0; j < i; j++ ) {
        hwlib::cout << 'x';
    }
    hwlib::cout << color;
    for(int j = i + 1; j < n_leds; j++) {
        hwlib::cout << 'x';
    }
    hwlib::cout << '\n' << hwlib::flush;
}

int main() {
    int n_leds = 12;
    neopixel_due strip( n_leds );

    hwlib::cout << "<write_all function>\tAll red\n" << hwlib::flush;
    strip.write_all(255, 0, 0); strip.flush();
    hwlib::wait_ms(2000);

    hwlib::cout << "<write_all function>\tAll green\n" << hwlib::flush;
    strip.write_all(0, 255, 0); strip.flush();
    hwlib::wait_ms(2000);

    hwlib::cout << "<write_all function>\tAll blue\n" << hwlib::flush;
    strip.write_all(0, 0, 255); strip.flush();
    hwlib::wait_ms(2000);

    hwlib::cout << "<clear function>\tAll black\n" << hwlib::flush;
    strip.clear();
    hwlib::wait_ms(2000);

    char colors[3] = {'R', 'G', 'B'};

    for (int col = 0; col < 3; col++ ) {
        for(int i = 0; i < n_leds; i++) {
            hwlib::cout << "<write irgb function>\t";
            printFunc(i, colors[col], n_leds);

            strip.write_all(0, 0, 0);

            if(col == 0)
                strip.write(i, 255, 0, 0);
            else if(col == 1)
                strip.write(i, 0, 255, 0);
            else 
                strip.write(i, 0, 0, 255);
            strip.flush();

            hwlib::wait_ms(100);
        }
        hwlib::cout << "<clear function>\t\n" << hwlib::flush;
        strip.clear();
    }

    uint8_t array[n_leds][3];
    for(auto &led : array) {
        for(auto &col : led) {
            col = 0;
        }
    }

    strip.write(array);
    for(int col = 0; col < 3; col++) {
        for(int i = 0; i < n_leds; i++) {
            hwlib::cout << "<write array function>\t";
            printFunc(i, colors[col], n_leds);

            array[i][col] = 255;
            strip.write(array);
            strip.flush();

            hwlib::wait_ms(100);
        }
        for(auto &led : array) {
            for(auto &col : led) {
                col = 0;
            }
        }
    }
    hwlib::cout << "<clear function>\t\n" << hwlib::flush;
    strip.clear();

    hwlib::cout << "\nFinished!\n" << hwlib::flush;
}