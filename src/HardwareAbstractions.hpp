#ifndef myStepperStuff_hpp
#define myStepperStuff_hpp
#include <Arduino.h>


class Motor{
    private:
        int A;
        int Aprime;
        int B;
        int Bprime;

    public:
        Motor(int a, int aprime, int b, int bprime);
        ~Motor();
        void move(bool direction, unsigned int steps, int speed);
        void moveMicrosteps(bool direction, unsigned int steps, int speed, int microsteps);
};

Motor::Motor(int a, int aprime, int b, int bprime){
    A = a; Aprime = aprime; B = b; Bprime = bprime;
    pinMode(A, OUTPUT);
    pinMode(Aprime, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(Bprime, OUTPUT);
    
}

Motor::~Motor(){
}

void Motor::move(bool direction, unsigned int steps, int speed){
    unsigned int i = 0;

    if (direction){
    while(true){ 
            if(i >= steps){break;}else {i++;}
            delay(speed);
            digitalWrite(A, HIGH);
            digitalWrite(Bprime, LOW);

            if(i >= steps){break;}else {i++;}
            delay(speed);
            digitalWrite(A, LOW);
            digitalWrite(B, HIGH);
            digitalWrite(Bprime, LOW);

            if(i >= steps){break;}else {i++;}
            delay(speed);    
            digitalWrite(B, LOW);
            digitalWrite(Aprime, HIGH);

            if(i >= steps){break;}else {i++;}
            delay(speed);
            digitalWrite(Bprime, HIGH);
            digitalWrite(Aprime, LOW);
        }
    }else{
        while (true){
            if(i >= steps){break;}else {i++;}
            delay(speed);
            digitalWrite(Aprime, LOW);
            digitalWrite(Bprime, HIGH);

            if(i >= steps){break;}else {i++;}
            delay(speed);
            digitalWrite(Aprime, HIGH);
            digitalWrite(B, LOW);

            if(i >= steps){break;}else {i++;}
            delay(speed); 
            digitalWrite(Bprime, LOW);
            digitalWrite(B, HIGH);
            digitalWrite(A, LOW);

            if(i >= steps){break;}else {i++;}
            delay(speed);
            digitalWrite(Bprime, LOW);
            digitalWrite(A, HIGH);

        }
    }
}

class Lazer{
    private:
        short LazerPin;
    public:
        Lazer(short pin);
        ~Lazer();
        void laserOn();
        void laserOff();
};

void Lazer::laserOn(){
  digitalWrite(LazerPin, HIGH);
}

void Lazer::laserOff(){
  digitalWrite(LazerPin, LOW);
}

Lazer::Lazer(short pin){
    LazerPin = pin;
}

Lazer::~Lazer(){}

#endif
