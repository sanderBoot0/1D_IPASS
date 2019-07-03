#include "hwlib.hpp"

#include "../../library/headers/HC_SR04.hpp"

// Tests for HC_SR04 class

int main() {
    hwlib::wait_ms(2000);

    auto trig = hwlib::target::pin_out( hwlib::target::pins::d3 );
    auto echo = hwlib::target::pin_in( hwlib::target::pins::d2 );

    HC_SR04 ultra_module(trig, echo);

    hwlib::cout << "Refreshing distance\n" << hwlib::flush;
    ultra_module.refresh();

    auto timeHigh = ultra_module.readTime();

    hwlib::cout << "high time of echo pin:\t" << timeHigh << "\tus" << '\n' << hwlib::flush;

    if (ultra_module.readCM() == (timeHigh/58) ) {
        hwlib::cout << "Succesfully calculated:\t" << ultra_module.readCM() << "\tcm" << '\n' << hwlib::flush;
    } else {
        hwlib::cout << "Failed calculating cm correctly.\n";
        hwlib::cout << "Correct value:\t" << (timeHigh/58) << '\n';
        hwlib::cout << "Returned value:\t" << ultra_module.readCM() << '\n';
        hwlib::cout << hwlib::flush;
    }

    if (ultra_module.readINCH() == (timeHigh/148) ) {
        hwlib::cout << "Succesfully calculated:\t" << ultra_module.readINCH() << "\tinch" << '\n' << hwlib::flush;
    } else {
        hwlib::cout << "Failed calculating cm correctly.\n";
        hwlib::cout << "Correct value:\t" << (timeHigh/58) << '\n';
        hwlib::cout << "Returned value:\t" << ultra_module.readINCH() << '\n';
        hwlib::cout << hwlib::flush;
    }

    hwlib::cout << "\nFinished\n" << hwlib::flush;

    hwlib::cout << "\nContinuing to infinite loop\n\n" << hwlib::flush;

    for(;;) {
        ultra_module.refresh();

        hwlib::cout << '\r' << ' ';
        hwlib::cout << ultra_module.readTime() << " us    ";
        hwlib::cout << ultra_module.readCM() << " cm    ";
        hwlib::cout << ultra_module.readINCH() << " inch ";

        hwlib::wait_ms(50);
    }
}