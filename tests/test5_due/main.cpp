#include "hwlib.hpp"

#include "../../library/headers/HC_12_due.hpp"

int main() {
    hwlib::wait_ms(2000);

    auto tx = hwlib::target::pin_out( hwlib::target::pins::d2 );
    auto rx = hwlib::target::pin_in( hwlib::target::pins::d3);

    HC_12_due module(tx, rx);

    char reading;

    hwlib::cout << "[" << hwlib::flush;

    for(uint8_t i = 1; i < 255; i++) {
        module.send(i);
        module.flush();
        reading = module.read();
        if( (uint8_t)reading == i) 
            hwlib::cout << '=' << hwlib::flush;
        else if( reading == '\0' )
            hwlib::cout << 'X' << hwlib::flush;
        else
            hwlib::cout << '?' << hwlib::flush;
        
    }
    hwlib::cout << ']' << '\n' << hwlib::flush;

    hwlib::cout << "\nFinished\n" << hwlib::flush;
}