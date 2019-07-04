#ifndef HC_12_HPP
#define HC_12_hpp

#include "hwlib.hpp"

/// @file


/// \brief
/// Class for communication throug the HC-12 chip.
/// \details
/// With this class you can send a byte from one to another chip.\n
/// It is good practice to make use of the subclasses HC_12_uno and HC_12_due.\n
/// The subclasses automaticly assign the right wait_times for the serial data.\n
/// You can use this class instead of the HC_12_due class; The default variable is for the Arduino Due.
class HC_12
{
private:
    hwlib::pin_out &tx;
    hwlib::pin_in &rx;
    uint8_t wait_time;

    char end_byte = '\n';
    char dataChar = 0;
    bool something_changed = false;
    char reading = 0;

public:
    /// \brief
    /// Constructor for a HC-12 interface
    /// \details
    /// This constructor creates an interface so you can communicate with the HC-12 chip.\n
    /// Note that the name of the class is HC_12, and not HC-12 (The chip name).\n
    /// \param  trigger a type of pin_out, needs to be constructed in main code
    /// \param  echo    a type of pin_in, needs to be constructed in main code
    /// \param  wait_time   this parameter is different depending on the Arduino type. It is 80 for the Uno, and 100 for the Due.
    HC_12(hwlib::pin_out &p_tx, hwlib::pin_in &p_rx, uint8_t wait_time = 100):
        tx( p_tx ), rx( p_rx ), wait_time( wait_time )
    {
        hwlib::wait_ms(50);
    }

    /// \brief
    /// send char to buffer
    /// \details
    /// Pass the data you want to send to this function.
    /// You cant send a char \'\\0\'.
    /// \param  data    char that you want to send
    void send(char data);

    /// \brief
    /// send uint8_t to buffer
    /// \details
    /// Pass the data you want to send to this function.\n
    /// This function writes the uint8_t to the char_buffer.
    /// You cant send the number 0
    /// \param  data    uint8_t integer that you want to send
    void send(uint8_t data);
    
    /// \brief
    /// flush buffer to chip
    /// \details
    /// If the send method is called since the flush, it will flush its buffer.
    /// It wil alwasy send an endbyte, which is '\\n'.
    void flush();

    /// \brief
    /// Read a char
    /// \details
    /// This is an non-blocking method which looks for data at the rx pin.\n
    /// It returns '\\0' if the endbyte is not readed.
    char read();
};

/// \example HC_12_example.cpp

#endif // HC_12_HPP