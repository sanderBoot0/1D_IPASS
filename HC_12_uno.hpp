#ifndef HC_12_UNO_HPP
#define HC_12_UNO_HPP

#include "hwlib.hpp"
#include "HC_12.hpp"

class HC_12_uno : public HC_12 {
public:
    HC_12_uno(hwlib::pin_out &p_tx, hwlib::pin_in &p_rx):
        HC_12(p_tx, p_rx, 80)
    {
        hwlib::wait_ms(50);
    }
};

#endif // HC_12_UNO_HPP