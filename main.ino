#include <arduino.h>

#include <AccelStepper.h>
#include <MultiStepper.h>

#include "./Grid.h"
// Define some steppers and the pins the will use
AccelStepper stepper1(AccelStepper::FULL2WIRE, 2, 5);
AccelStepper stepper2(AccelStepper::FULL2WIRE, 3, 6);
AccelStepper stepper3(AccelStepper::FULL2WIRE, 4, 7);
AccelStepper stepper4(AccelStepper::FULL2WIRE, 12, 13);

MultiStepper steppers1;
MultiStepper steppers2;

Grid grid;
int test;
int isSet = 0;

void setup()
{
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(8, OUTPUT);

    int speed = 2000;
    int acc = 2000;

    stepper1.setMaxSpeed(speed);
    //stepper1.setAcceleration(acc);
    stepper2.setMaxSpeed(speed);
    //stepper2.setAcceleration(acc);
    stepper3.setMaxSpeed(speed);
    //stepper3.setAcceleration(acc);
    stepper4.setMaxSpeed(speed);
    //stepper4.setAcceleration(acc);

    steppers1.addStepper(stepper1);
    steppers1.addStepper(stepper2);
    steppers2.addStepper(stepper3);
    steppers2.addStepper(stepper4);


    Serial.begin(9600);
    grid.setGridX(4);
    grid.setGridY(3);
    grid.setColumnWidth(200);
    grid.setRowHeight(300);
    grid.setStepsPerMillimeter(4);
}

void loop()
{
    /*stepper1.run();
    stepper2.run();
    stepper3.run();
    stepper4.run();*/
    if (Serial.available() > 0) {
        digitalWrite(8, LOW);
        int input = Serial.read();
        int inputPos = input - 48;
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
        long positionsX[2];
        long positionsY[2];
        positionsX[0] = xmm;
        positionsX[1] = xmm;
        positionsY[0] = ymm;
        positionsY[1] = ymm;

        steppers1.moveTo(positionsX);
        steppers2.moveTo(positionsY);

        Serial.print(": X:");
        Serial.print(x);
        Serial.print(", Y:");
        Serial.print(y);
        Serial.print(", X in steps: ");
        Serial.print(xmm);
        Serial.print(", Y in steps: ");
        Serial.println(ymm);
        isSet = 0;
    }
    steppers1.run();
    steppers2.run();
    if (stepper1.distanceToGo()==0&&stepper3.distanceToGo()==0){
        digitalWrite(8,HIGH);
    }
}