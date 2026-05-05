//Polymnia Galiatsatos 40342236

#include <Servo.h> // server motor library


Servo servo1; // declare global Servo object

//joystick variables
const int X_pin = A0; // analog pin connected to X output (moves servo motor )
const int SW_pin = 2; // connect to pin 2 NOTE: WHEN CLICKED WILL MAKE SEVRO MOTOR RETURN TO 0 DEGREES (starting position)

//NOTE Y pin not required for this project so i excluded it

int xValue = 0; //prints 0 when servo is at 0

int servoStartingPosition = 90; //initialize starting position

void setup() {

  //initialize serial communication
  Serial.begin(9600);

  //attach servo motor to pin 7
  servo1.attach(7); // connect pin 7 to servo motor #1


 //setting up pin 
 pinMode(SW_pin, INPUT_PULLUP);

  //starting position for servo

  servo1.write(servoStartingPosition); //servo motor goes to starting position 

}

//joystick loop


void loop() {
  
  //if statements checks for RESET press (switch)
  if (digitalRead(SW_pin) == LOW){

    servo1.write(90); //reset servo to 90 degrees

    Serial.print("\nReset Switch Pressed, servo position back to 90");
    delay(1000); //wait 1 seconds

  }
    else {

      //READ JOYSTICK

     xValue = analogRead(X_pin); //elegoo says value is between 0-1023

      //map value. of joystick and servo (range is 0-180 deg.)

     int servoPosition = map(xValue, 0, 1023, 180, 0);

     //servo move
     servo1.write(servoPosition);

     if (abs(servoPosition - servoStartingPosition) > 1){     //print servo position ONLY WHEN MOVED GREATER THAN 1 degree

     Serial.print("\nX position: ");
     Serial.print(xValue);
    
     Serial.print("\nServo Poistion: ");
     Serial.print(servoPosition);}

    }
 delay(10); //10 miliseconds
}
