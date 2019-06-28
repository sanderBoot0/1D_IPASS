#ifndef HC_SR04_HPP
#define HC_SR04_HPP

#include "hwlib.hpp"

class HC_SR04 {
private:
    hwlib::pin_out &trigger;
    hwlib::pin_in &echo;

    int time_us;
    int o_time_us;

public:
    HC_SR04(hwlib::pin_out &trigger, hwlib::pin_in &echo);

    void refresh();

    int readTime() { return time_us; }

    int readCM() { return (time_us/58); }

    int readINCH() { return (time_us/148); }
};

#endif // HC_SR04_HPP