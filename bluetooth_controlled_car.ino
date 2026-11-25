#include <SoftwareSerial.h>

// Motor 1 pins
#define m1 2
#define m2 3

// Motor 2 pins
#define m3 4
#define m4 5

// HC-05 Bluetooth
#define BT_RX 10
#define BT_TX 11

SoftwareSerial bluetooth(BT_RX, BT_TX);

char command;

void setup()
{
    pinMode(m1, OUTPUT);
    pinMode(m2, OUTPUT);
    pinMode(m3, OUTPUT);
    pinMode(m4, OUTPUT);

    bluetooth.begin(9600);
    Serial.begin(9600);

    stopCar();
}

void loop()
{
    if (bluetooth.available())
    {
        command = bluetooth.read();

        Serial.print("Command: ");
        Serial.println(command);

        if (command == 'F')
        {
            forward();
        }
        else if (command == 'B')
        {
            backward();
        }
        else if (command == 'L')
        {
            left();
        }
        else if (command == 'R')
        {
            right();
        }
        else if (command == 'S')
        {
            stopCar();
        }
    }
}

void forward()
{
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);

    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
}

void backward()
{
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);

    digitalWrite(m3, LOW);
    digitalWrite(m4, HIGH);
}

void left()
{
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);

    digitalWrite(m3, HIGH);
    digitalWrite(m4, LOW);
}

void right()
{
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);

    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
}

void stopCar()
{
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);

    digitalWrite(m3, LOW);
    digitalWrite(m4, LOW);
}
