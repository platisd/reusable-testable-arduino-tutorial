#include "Calculator.h"

void setup() {
    Serial.begin(9600);
    Serial.println(calculator::add(2, -5));
    Serial.println(calculator::subtract(10, 4));
    Serial.println(calculator::divide(634, 34));
}

void loop() {
}