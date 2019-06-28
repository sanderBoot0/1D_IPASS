#ifndef HC_12_HPP
#define HC_12_hpp

#include "hwlib.hpp"

class HC_12
{
private:
    hwlib::pin_out &tx;
    hwlib::pin_in &rx;
    uint8_t wait_time;

    char end_byte = '\n';
    char dataChar = 0;
    bool something_changed = false;

public:
    char reading = 0;

    HC_12(hwlib::pin_out &p_tx, hwlib::pin_in &p_rx, uint8_t wait_time = 100):
        tx( p_tx ), rx( p_rx ), wait_time( wait_time )
    {
        hwlib::wait_ms(50);
    }

    void send(char data);
    void send(uint8_t data);
    
    void flush();
    char read();
};

#endif // HC_12_HPP