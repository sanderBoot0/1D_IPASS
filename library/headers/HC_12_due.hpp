#ifndef HC_12_DUE_HPP
#define HC_12_DUE_HPP

#include "hwlib.hpp"
#include "HC_12.hpp"

/// @file


/// \brief
/// Implementation HC-12 for Arduino Due
/// \details
/// This subclass automaticly chooses the right wait_time for the superclass.
class HC_12_due : public HC_12 {
public:
    /// \brief  
    /// Constructor for a HC-12 interface
    /// \details
    /// This constructor creates an interface so you can communicate with the HC-12 chip.\n
    /// Note that the name of the class is HC_12, and not HC-12 (The chip name).\n
    /// \param  trigger a type of pin_out, needs to be constructed in main code
    /// \param  echo    a type of pin_in, needs to be constructed in main code
    HC_12_due(hwlib::pin_out &p_tx, hwlib::pin_in &p_rx):
        HC_12(p_tx, p_rx, 100)
    {}
};

/// \example HC_12_example.cpp

#endif // HC_12_DUE_HPP