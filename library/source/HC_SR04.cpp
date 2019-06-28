#include "hwlib.hpp"
#include "../headers/HC-SR04.hpp"

HC_SR04::HC_SR04(hwlib::pin_out &trigger, hwlib::pin_in &echo):
        trigger( trigger ), echo( echo ), time_us( 0 )
{}

void HC_SR04::refresh() 
{
    o_time_us = time_us;
    time_us = 0;
    trigger.write(1); trigger.flush();
    hwlib::wait_us(6);
    trigger.write(0); trigger.flush();

    echo.refresh();
    while(!echo.read()) {
        hwlib::wait_us(1);
        echo.refresh();
    }
    while(echo.read() && time_us < 14000) {
        time_us += 10;
        hwlib::wait_us(10);
        echo.refresh();
    }
    if(time_us >= 14000) 
        time_us = o_time_us;
}