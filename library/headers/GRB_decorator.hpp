#ifndef GRB_DECORATOR_HPP
#define GRB_DECORATOR_HPP

#include "hwlib.hpp"
#include "neopixel.hpp"

/// @file


/// \brief
/// Decorator for neopixel class
/// \details
/// This decorator swaps the red and green color.\n
/// Some led rings are RGB, but others are GRB.\n
/// This class swaps these colors.\n
/// All functions are the same as the neopixel functions.\n
class neopixel_grb {
private:
    neopixel & slave;

public:
    /// \brief
    /// Constructor for GRB decorator
    /// \details
    /// This is the constructor for the RGB-GRB swap decorator.
    /// \param p_slave  you first need to construct a neopixel object, and pass it as a parameter.
    neopixel_grb( neopixel & p_slave ): 
        slave( p_slave )
    {}

    void write (uint8_t p_leds[][3]) {
        for ( int i = 0; i < slave.n_leds; i++ ) {
            uint8_t temp = p_leds[i][0];
            p_leds[i][0] = p_leds[i][1];
            p_leds[i][1] = temp;
        }
        slave.write(p_leds);
    }

    void write (uint8_t led_index, uint8_t red, uint8_t green, uint8_t blue) {
        slave.write(led_index, green, red, blue);
    }

    void write_all( const uint8_t red, const uint8_t green, const uint8_t blue ) {
        slave.write_all( green,  red,  blue );
    }

    void clear () {
        slave.clear();
    }

    void wave () {
        for(;;) {
            for(int i = 0; i < 256; i++) {
                write_all(255, i, 0); flush();
                hwlib::wait_ms(ms);
            }
            for(int i = 255; i >= 0; i--) {
                write_all(i, 255, 0); flush();
                hwlib::wait_ms(ms);
            }
            for(int i = 0; i < 256; i++) {
                write_all(0, 255, i); flush();
                hwlib::wait_ms(ms);
            }
            for(int i = 255; i >= 0; i--) {
                write_all(0, i, 255); flush();
                hwlib::wait_ms(ms);
            }
            for(int i = 0; i < 256; i++) {
                write_all(i, 0, 255); flush();
                hwlib::wait_ms(ms);
            }
            for(int i = 255; i >= 0; i--) {
                write_all(255, 0, i); flush();
                hwlib::wait_ms(ms);
            }
        }
    }

    void flash () {
        for(;;) {
            write_all(255, 0, 0); flush();
            hwlib::wait_ms(ms);

            write_all(0, 255, 0); flush();
            hwlib::wait_ms(ms);

            write_all(0, 0, 255); flush();
            hwlib::wait_ms(ms);
        }
    }

    void flush () {
        slave.flush();
    }
};

#endif // GRB_DECORATOR_HPP