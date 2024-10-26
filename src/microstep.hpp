#ifndef myStepperStuff_hpp
#define myStepperStuff_hpp
#include <Arduino.h>
#include "HardwareAbstractions.hpp"

#define A 2
#define B 3
#define Aprime 4
#define Bprime 5

const int microstep_4[] = {0, 64, 128, 192, 255}; // Microstepping PWM values for 4th step
const int microstep_8[] = {0, 32, 64, 96, 128, 160, 192, 224, 255}; // Microstepping PWM values for 8th step
const int microstep_16[] = {0, 16, 32, 48, 64, 80, 96, 112, 128, 144, 160, 176, 192, 208, 224, 240, 255}; // Microstepping PWM values for 16th step

void Motor::moveMicrosteps(bool direction, unsigned int steps, int speed, int microsteps) {
    unsigned int i = 0;

    const int* microstepValues;
    int microstepCount;
    
    // Select the microstepping array and count based on the microsteps parameter
    switch (microsteps) {
        case 4:
            microstepValues = microstep_4;
            microstepCount = sizeof(microstep_4) / sizeof(microstep_4[0]);
            break;
        case 8:
            microstepValues = microstep_8;
            microstepCount = sizeof(microstep_8) / sizeof(microstep_8[0]);
            break;
        case 16:
            microstepValues = microstep_16;
            microstepCount = sizeof(microstep_16) / sizeof(microstep_16[0]);
            break;
        default:
            microstepValues = microstep_4;
            microstepCount = sizeof(microstep_4) / sizeof(microstep_4[0]);
            break;
    }

    if (direction) {
        while (i < steps * microstepCount) {
            for (int step = 0; step < microstepCount; step++) {
                analogWrite(A, microstepValues[step]);
                analogWrite(Bprime, microstepValues[microstepCount - 1 - step]);
                delay(speed);

                analogWrite(A, microstepValues[microstepCount - 1 - step]);
                analogWrite(B, microstepValues[step]);
                analogWrite(Bprime, microstepValues[step]);
                delay(speed);

                analogWrite(B, microstepValues[microstepCount - 1 - step]);
                analogWrite(Aprime, microstepValues[step]);
                delay(speed);

                analogWrite(Aprime, microstepValues[microstepCount - 1 - step]);
                analogWrite(Bprime, microstepValues[step]);
                delay(speed);

                i++;
                if (i >= steps * microstepCount) break;
            }
        }
    } else {
        while (i < steps * microstepCount) {
            for (int step = 0; step < microstepCount; step++) {
                analogWrite(Aprime, microstepValues[step]);
                analogWrite(Bprime, microstepValues[microstepCount - 1 - step]);
                delay(speed);

                analogWrite(Aprime, microstepValues[microstepCount - 1 - step]);
                analogWrite(B, microstepValues[step]);
                delay(speed);

                analogWrite(B, microstepValues[microstepCount - 1 - step]);
                analogWrite(A, microstepValues[step]);
                analogWrite(Bprime, microstepValues[step]);
                delay(speed);

                analogWrite(A, microstepValues[microstepCount - 1 - step]);
                analogWrite(Bprime, microstepValues[step]);
                delay(speed);

                i++;
                if (i >= steps * microstepCount) break;
            }
        }
    }
}
#endif