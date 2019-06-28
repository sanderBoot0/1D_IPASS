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
    const char *dataString = 0;
    bool something_changed = false;

public:
    char reading = 0;

    HC_12(hwlib::pin_out &p_tx, hwlib::pin_in &p_rx, uint8_t wait_time = 100):
        tx( p_tx ), rx( p_rx ), wait_time( wait_time )
    {
        hwlib::wait_ms(50);
    }

    void send(char data)
    {
        dataChar = data;
        something_changed = true;
    }

    void send(uint8_t data)
    {
        dataChar = (char) data;
        something_changed = true;
    }

    void flush()
    {
        if (dataChar != 0)
        {
            tx.write(1);    tx.flush();
            hwlib::wait_us(wait_time);
            tx.write(0);    tx.flush();
            hwlib::wait_us(wait_time);

            for (uint8_t i = 0; i < 8; i++)
            {
                tx.write(((dataChar >> i) & 0x1));
                tx.flush();
                hwlib::wait_us(wait_time);
            }
            dataChar = 0;
        }

        tx.write(1);    tx.flush();
        hwlib::wait_us(wait_time);
        tx.write(0);    tx.flush();
        hwlib::wait_us(wait_time);

        for (uint8_t i = 0; i < 8; i++)
        {
            tx.write(((end_byte >> i) & 0x1));
            tx.flush();
            hwlib::wait_us(wait_time);
        }

        tx.write(0);    tx.flush();
        hwlib::wait_us(wait_time);
        tx.write(1); tx.flush();

        something_changed = false;
    }

    char read()
    {
        char reading_2 = 0;
        int loopCount = 0;
        rx.refresh();

        while(rx.read() && loopCount < 5000) {
            hwlib::wait_us(10);
            loopCount++;
            rx.refresh();
        }

        hwlib::wait_us(wait_time);
        reading = 0;

        for(int i = 0; i < 8; i++) {
            rx.refresh();
            reading |= (rx.read() << i);
            hwlib::wait_us(wait_time);
        }

        hwlib::wait_us(2*wait_time);

        for(int i = 0; i < 8; i++) {
            rx.refresh();
            reading_2 |= (rx.read() << i);
            hwlib::wait_us(wait_time);
        }

        if(reading_2 == '\n')
            return reading;

        return '\0';
    }
};

#endif // HC_12_HPP