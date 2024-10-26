#include <Arduino.h>
#include "HardwareAbstractions.hpp"
#include "microstep.hpp"
/*to do:
- test microstep() fucntion
- wright dxf tracer
- microsdcard things
- mechanical & cooling
*/
const int LASER_PIN = 6;

Motor xAxis = Motor(1,2,3,4);
Motor yAxis = Motor(8, 9, 10, 11);


void setup() {

}

void loop() {
  xAxis.move(1, 50, 8);
  yAxis.move(1, 50, 8);
  xAxis.move(0, 50, 8);
  yAxis.move(0, 50, 8); 
} 