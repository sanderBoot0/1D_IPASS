#ifndef NEOPIXEL_UNO_HPP
#define NEOPIXEL_UNO_HPP

#include "hwlib.hpp"
#include "neopixel.hpp"

/// @file


/// \brief
/// implementations for Adafruit ws2812 for Arduino Uno
/// \details
/// This class is an implemtation of the abstract neopixel class
///
/// This implementation can be used for the Arduino Uno
///
/// The adafruit ws2812 led ring is a LED ring that is controlled by one data pin.
///
/// The chip runs on 5V, and I suggest you use an external power supply, because each LED consumes around 60mA when its on full brightness.
/// 
/// An Arduino's Max current on Vcc and GND is 200 mA, so you can link a total off 5 LEDs if you plan to use them on full white brightness.
/// 
/// This class takes a maximum of 100 chained leds. This can be upgraided by making the array bigger.
///
/// <b>The Data pin has to be connected to pin D8!</b>
///
/// It needs to be pin D8 because the class writes directly to the right register.
///
/// references:
///    - <A HREF="https://cdn-shop.adafruit.com/datasheets/WS2812.pdf">
///       WS2812 data sheet</A> (pdf)
class neopixel_uno : public neopixel {
public:
    /// \brief
    /// Constructor for the Uno implementation of ws2812
    /// \details
    /// This constructor creates an interface for the D8 pin, so the LEDS can be controlled by various functions.
    /// The LEDs can be flushed through this subclass.
    ///
    /// \param  n_leds  number of leds that are chained and needs to be controlled.
    neopixel_uno( const int &n_leds ): 
        neopixel( n_leds ) 
    {
        DDRB = DDRB | 0b00000001;
        PORTB = 0b00000000;
        hwlib::wait_ms(1);
    }

    /// \brief
    /// Flush buffer to LEDs
    /// \details
    /// This function writes only if something is changed in the array.
    ///
    /// If so, the array is written to the LEDs, and the bool something_changed is set to false.
    void flush( ) override;
};

/// \example neopixel_example.cpp

#endif // NEOPIXEL_UNO_HPP