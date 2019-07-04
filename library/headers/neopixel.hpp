#ifndef NEOPIXEL_HPP
#define NEOPIXEL_HPP

#include "hwlib.hpp"

/// @file

/// \brief
/// Abstract class for adafruit pixel
/// \details
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
class neopixel
{
protected:
    uint8_t leds[100][3];
    bool something_changed = false;

public:
    const int n_leds;
    
    /// \brief
    /// Construct an interface for the adafruit ws2812
    /// \details
    /// this constructor creates a virtual interface for the D8 pin, so the LEDS can be controlled by various functions
    ///
    /// \param  n_leds  number of leds that are chained and needs to be controlled.
    neopixel( const int &n_leds ):
        n_leds( n_leds )
    {}

    /// \brief 
    /// Write to the buffer
    /// \details
    /// This function allows to write the RGB values to the buffer. 
    /// A call to the flush method is needed to flush the buffer to the LEDs.
    ///
    /// \param  p_leds  This is an 2D array. The array has to be n_leds elements long, or longer. It wil loop until var n_leds. The subarray needs to have length 3.
    void write( const uint8_t p_leds[][3] );

    /// \brief
    /// Write to the buffer for one LED
    /// \details
    /// With this function you can change one LED individually.
    /// A call to the flush method is needed to flush the buffer to the LEDs.
    ///
    /// \param  led_index   This is the index of the led you want to change.
    /// \param  red,green,blue  These are the unsigned 8-bit integer values for the red, green and blue colors.
    void write( const uint8_t led_index, const uint8_t red, uint8_t green, const uint8_t blue );

    /// \brief
    /// Write to the buffer for all the n_leds
    /// \details
    /// This function makes it possible to change all LEDs in one function call.
    /// This function calls the write function for all n_leds.
    /// A call to the flush method is needed to flush the buffer to the LEDs.
    ///
    /// \param  red,green,blue  These are the unsigned 8-bit integer values for the red, green and blue colors.
    void write_all( const uint8_t red, const uint8_t green, const uint8_t blue );

    /// \brief
    /// Makes all n_leds black
    /// \details
    /// This function makes the array all 0's.
    /// The function will do the flush itself.
    void clear( );

    /// \brief
    /// virtual function to flash to the LEDs
    /// \details
    /// This function has to be re-implemented in a subclass.
    /// It is an virtual function in class neopixel because the processor frequencies of the Due and the Uno are different.
    virtual void flush( );

    /// \brief
    /// One of the demo functions
    /// \details
    /// This function has an infinite loop, it will never return.
    ///
    /// This function will show a wave from red to green to blue to red.
    ///
    /// It uses a hue to RGB implementation. 
    /// The implementation covers the hue from 0 to 359.
    ///
    /// \param  ms  This is the time in milliseconds to wait for a hue increment.
    void wave( const int ms = 10 );

    /// \brief
    /// one of the demo functions
    /// \details
    /// This function has an infinite loop, it will never return.
    ///
    /// This function flashes red -> green -> blue -> red. 
    ///
    /// \param  ms  This is the time for every flash.
    void flash( const int ms = 500 );
};

/// \example neopixel_example.cpp

#endif // NEOPIXEL_HPP