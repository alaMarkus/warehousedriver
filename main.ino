#include <arduino.h>
#include <AccelStepper.h>
#include "./Grid.h"
// Define some steppers and the pins the will use
AccelStepper stepper1(AccelStepper::FULL2WIRE, 2, 5);
AccelStepper stepper2(AccelStepper::FULL2WIRE, 3, 6);
AccelStepper stepper3(AccelStepper::FULL2WIRE, 4, 7);
AccelStepper stepper4(AccelStepper::FULL2WIRE, 12, 13);

Grid grid;
int test;
int isSet = 0;
void setup()
{
    Serial.begin(9600);
    grid.setGridX(4);
    grid.setGridY(3);
    grid.setColumnWidth(200);
    grid.setRowHeight(300);
}

void loop()
{
    if (Serial.available() > 0) {
        int input = Serial.read();
        int inputPos = input - 48;
        delay(200);
        Serial.print("input: ");
        Serial.print(inputPos);
        grid.setMoveCoordinates(inputPos);
        isSet = 1;
    }
    if (isSet == 1){
        int x = grid.getXcoordinate();
        int y = grid.getYcoordinate();
        int xmm = grid.getDistanceToMoveX();
        int ymm = grid.getDistanceToMoveY();
        Serial.print(": X:");
        Serial.print(x);
        Serial.print(", Y:");
        Serial.print(y);
        Serial.print(", X in mm: ");
        Serial.print(xmm);
        Serial.print(", Y in mm: ");
        Serial.println(ymm);
        isSet = 0;
    }
}