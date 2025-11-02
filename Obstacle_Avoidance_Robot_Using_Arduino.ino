// Motor A connections
int enA = 3;
int in1 = 14; //or AO
int in2 = 15; //OR A1
// Motor B connections
int enB = 5;
int in3 = 16; //OR A2
int in4 = 17; //OR A3

int trigPin = 7;
int echoPin = 6;

void setup() {
  // Set all the motor control pins to outputs
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {

 // Make the trigPin LOW (0 volts) 
  // for 2 microseconds
  digitalWrite(trigPin, LOW);
  delayMicroseconds(20);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(20);
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(20);

  int durationA = pulseIn(echoPin, HIGH);
  int distanceA= durationA*0.034/2;//distance in cm. Speed of sound is 343m/s, in cm/s = 34300cm/s. pulseIn returns time in microseconds.
  // //Hence in cm/microsecs will be 34300/1000000 = 0.0343 cm/microsecs.
  Serial.println(distanceA);

  if(distanceA <= 10){
    turnRight();
  }
  moveForward();
}

// This function lets you control spinning direction of motors
void turnRight() {
  analogWrite(enA, 60); // right motor (slow)
  analogWrite(enB, 120); // left motor (fast)
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW); 

  delay(500);

}

// motor A moves faster than motor B in default conditions, so it was important to reduce the speed of motor A slightly to 
// avoid the Robot spinning or moving in circles.
void moveForward(){
  analogWrite(enA, 95); 
  analogWrite(enB, 100);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

}
