/***********************
 RC Controller
***********************/

// Initialize variables

// Set pins
int enableLeft = 9; // left side enable pin
int pinLeft1 = 2; // left side control pin 1
int pinLeft2 = 3; // left side control pin 2
int enableRight = 6; // right side enable pin
int pinRight1 = 4; // right side control pin 1
int pinRight2 = 5; // right side control pin 2

// Set directional commands
int forwardCmd = 'f'; // forward
int backwardCmd = 'b'; // backward
int leftCmd = 'l'; // left
int rightCmd = 'r'; // right
int stopCmd = 's'; // stop

// Set other variables
int incomingByte; // serial data input
int motorSpeed = 200; // motor speed


// Setup routine

void setup() {

  // Configure the drive motor pin modes
  pinMode(enableLeft, OUTPUT);
  pinMode(pinLeft1, OUTPUT);
  pinMode(pinLeft2, OUTPUT);
  pinMode(enableRight, OUTPUT);
  pinMode(pinRight1, OUTPUT);
  pinMode(pinRight2, OUTPUT);

  // Open the serial port
  Serial.begin(9600);

}


// Main program

void loop() {
  
  if (Serial.available() > 0) {

    // read the serial buffer:
    incomingByte = Serial.read();

    // forward
    if (incomingByte == forwardCmd) {
      Serial.println("Forward");
      analogWrite(enableLeft, motorSpeed);
      analogWrite(enableRight, motorSpeed);
      digitalWrite(pinLeft1, HIGH);
      digitalWrite(pinLeft2, LOW);
      digitalWrite(pinRight1, LOW);
      digitalWrite(pinRight2, HIGH);
    }

    // backward
    if (incomingByte == backwardCmd) {
      Serial.println("Backward");
      analogWrite(enableLeft, motorSpeed);
      analogWrite(enableRight, motorSpeed);
      digitalWrite(pinLeft1, LOW);
      digitalWrite(pinLeft2, HIGH);
      digitalWrite(pinRight1, HIGH);
      digitalWrite(pinRight2, LOW);
    }

    // left
    if (incomingByte == leftCmd) {
      Serial.println("Left");
      analogWrite(enableLeft, motorSpeed+55);
      analogWrite(enableRight, motorSpeed+55);
      digitalWrite(pinLeft1, LOW);
      digitalWrite(pinLeft2, HIGH);
      digitalWrite(pinRight1, LOW);
      digitalWrite(pinRight2, HIGH);
    }

    // right
    if (incomingByte == rightCmd) {
      Serial.println("Right");
      analogWrite(enableLeft, motorSpeed+55);
      analogWrite(enableRight, motorSpeed+55);
      digitalWrite(pinLeft1, HIGH);
      digitalWrite(pinLeft2, LOW);
      digitalWrite(pinRight1, HIGH);
      digitalWrite(pinRight2, LOW);
    }

    // stop
    if (incomingByte == stopCmd) {
      Serial.println("Stop");
      digitalWrite(pinLeft1, HIGH);
      digitalWrite(pinLeft2, HIGH);
      digitalWrite(pinRight1, HIGH);
      digitalWrite(pinRight2, HIGH);
    }

  }

}
