#include "hwlib.hpp"
#include "../headers/HC_12.hpp"

void HC_12::send(char data)
{
    dataChar = data;
    something_changed = true;
}

void HC_12::send(uint8_t data)
{
    dataChar = (char) data;
    something_changed = true;
}

void HC_12::flush()
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

char HC_12::read()
{
    reading = 0;
    char reading_2 = 0;
    int loopCount = 0;
    rx.refresh();

    int max_loops;
    if (wait_time == 80) 
        max_loops = 10000;
    else 
        max_loops = 50000;

    while(rx.read() && loopCount < max_loops) {
        hwlib::wait_us(10);
        loopCount++;
        rx.refresh();
    }

    hwlib::wait_us(wait_time);

    rx.refresh();
    reading = reading | (rx.read() << 0);
    hwlib::wait_us(wait_time);

    rx.refresh();
    reading = reading | (rx.read() << 1);
    hwlib::wait_us(wait_time);

    rx.refresh();
    reading = reading | (rx.read() << 2);
    hwlib::wait_us(wait_time);

    rx.refresh();
    reading = reading | (rx.read() << 3);
    hwlib::wait_us(wait_time);

    rx.refresh();
    reading = reading | (rx.read() << 4);
    hwlib::wait_us(wait_time);

    rx.refresh();
    reading = reading | (rx.read() << 5);
    hwlib::wait_us(wait_time);

    rx.refresh();
    reading = reading | (rx.read() << 6);
    hwlib::wait_us(wait_time);

    rx.refresh();
    reading = reading | (rx.read() << 7);
    hwlib::wait_us(wait_time);

    hwlib::wait_us(2*wait_time+wait_time/7+5);

    rx.refresh();
    reading_2 = reading_2 | (rx.read() << 0);
    hwlib::wait_us(wait_time);

    rx.refresh();
    reading_2 = reading_2 | (rx.read() << 1);
    hwlib::wait_us(wait_time);

    rx.refresh();
    reading_2 = reading_2 | (rx.read() << 2);
    hwlib::wait_us(wait_time);

    rx.refresh();
    reading_2 = reading_2 | (rx.read() << 3);
    hwlib::wait_us(wait_time);

    rx.refresh();
    reading_2 = reading_2 | (rx.read() << 4);
    hwlib::wait_us(wait_time);

    rx.refresh();
    reading_2 = reading_2 | (rx.read() << 5);
    hwlib::wait_us(wait_time);

    rx.refresh();
    reading_2 = reading_2 | (rx.read() << 6);
    hwlib::wait_us(wait_time);

    rx.refresh();
    reading_2 = reading_2 | (rx.read() << 7);

    if(reading_2 == '\n' || (uint8_t)reading_2 == 20)
        return reading;

    return '\0';
}