#include "hwlib.hpp"

#include "../../library/headers/HC_12_due.hpp"

int main() {
    hwlib::wait_ms(2000);

    auto tx = hwlib::target::pin_out( hwlib::target::pins::d2 );
    auto rx = hwlib::target::pin_in( hwlib::target::pins::d3);

    HC_12_due module(tx, rx);

    char reading;

    hwlib::cout << "Test of the uint8_t send function\n";
    hwlib::cout << "It will test all numbers from 1 - 255\n";
    hwlib::cout << "The message will be send to the slave, and the slave will send it back\n";
    hwlib::cout << "an \'=\' means a correct send-receive send-receive sequince\n";
    hwlib::cout << "an \'X\' means the message is not received correctly\n";
    hwlib::cout << "an \'?\' means that the message is received correct, but that the message itself is the wrong number\n";
    hwlib::cout << '\n' << hwlib::flush;

    hwlib::cout << '[' << hwlib::flush;

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