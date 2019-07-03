int main() 
{
    // Construct the pins for the trigger and the echo
    auto trig = hwlib::target::pin_out( hwlib::target::pins::d3 );
    auto echo = hwlib::target::pin_in( hwlib::target::pins::d2 );

    // Construct the class
    HC_SR04 class_var_name(trig, echo);

    // Read the distance
    class_var_name.refresh();

    // Get the distance in different units
    auto readingUS = class_var_name.readTime();
    auto readingCM = class_var_name.readCM();
    auto readingINCH = class_var_name.readINCH();
}