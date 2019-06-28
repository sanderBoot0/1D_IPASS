#ifndef HC_12_DUE_HPP
#define HC_12_DUE_HPP

#include "hwlib.hpp"
#include "HC_12.hpp"

class HC_12_due : public HC_12 {
public:
    HC_12_due(hwlib::pin_out &p_tx, hwlib::pin_in &p_rx):
        HC_12(p_tx, p_rx, 100)
    {
        hwlib::wait_ms(50);
    }
};

#endif // HC_12_DUE_HPP