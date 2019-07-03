#include "hwlib.hpp"

#include "../../library/headers/HC_12_uno.hpp"

// The uno just resends the messages it received.

// Tests for HC_12 and HC_12_uno class

int main() {
    auto tx = hwlib::target::pin_out( hwlib::target::pins::d2 );
    auto rx = hwlib::target::pin_in( hwlib::target::pins::d3);

    HC_12_uno module(tx, rx);

    for(;;) {
        char reading = module.read();
        if(reading != '\0') {
            hwlib::cout << "Sending\n" << hwlib::flush; 
            module.send(reading);
            module.flush();
        }
    }
}