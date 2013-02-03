#ifdef NMA7361L_H
#define NMA7361L_H

// Assumes you're using port F, pins 1-7
/** @brief Sets up the teensy to work with the accelerometer.
 *  @details Turns off self-test and sleep mode.
 *  @param sens the 
 */
void acc_setup(uint8_t sens);


void acc_set_sens(uint8_t sens);


void acc_set_sleep(uint8_t sleep);


void acc_set_selftest(uint8_t selftest);

#endif
