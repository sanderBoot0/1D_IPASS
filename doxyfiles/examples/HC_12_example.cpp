int main() {
    auto tx = hwlib::target::pin_out( hwlib::target::pins::d2 );
    auto rx = hwlib::target::pin_in( hwlib::target::pins::d3);

    HC_12_due module(tx, rx);
    //or
    HC_12_uno module(tx, rx);

    // send a char
    module.send('A');
    module.flush();

    // send a number
    module.send(3);
    module.flush();

    // read a char
    char reading = module.read();
    // read an unsigned integer
    uint8_t reading = (uint8_t)module.read();
}