#ifndef HC_SR04_HPP
#define HC_SR04_HPP

#include "hwlib.hpp"

/// @file

/// \brief
/// Calculate distance for the HC-SR04
/// \details
/// This class can get the distance from a HC-SR04 chip.
/// 
/// This is an ultrasone chip.
/// After the trigger is on for 10 us, the chip will output the distance on the echo pin through PWM.
///
/// note that the class name is HC_SR04 and not HC-SR04.
///
/// More details about this class.
class HC_SR04 {
private:
    hwlib::pin_out &trigger;
    hwlib::pin_in &echo;

    int time_us;
    int o_time_us;

public:
    /// \brief
    /// Constructor for a HC-SR04 interface
    /// \details
    /// This constructor creates an interface so you can communicate with the HC-SR04 chip.
    ///
    /// \param  trigger a type of pin_out, needs to be constructed in main code
    /// \param  echo    a type of pin_in, needs to be constructed in main code
    HC_SR04(hwlib::pin_out &trigger, hwlib::pin_in &echo);

    /// \brief
    /// Refresh the distance reading
    /// \details
    /// This function makes the trigger pin high and low, and measures how long the echo pin is high.
    /// 
    /// Then you can call the read* functions so you can get the time in us, or you can get it in CM or INCHes.
    void refresh( );

    /// \brief
    /// Return the time that the echo pin was high
    /// \details
    /// This function returns the time that the echo high was after the trigeer, in us.
    int readTime( ) { return time_us; }

    /// \brief 
    /// Return the discante in CM
    /// \details
    /// This function returns the distance in CM as an integer.
    int readCM( ) { return (time_us/58); }

    /// \brief 
    /// Return the discante in INCH
    /// \details
    /// This function returns the distance in INCHes as an integer.
    int readINCH( ) { return (time_us/148); }
};

/// \example HC_SR04_example.cpp

#endif // HC_SR04_HPP