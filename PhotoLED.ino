//Define Pin Mappings

const int leftLedPin = 9;
const int leftSensorPin = A0;
int lightThreshold=290;
const int RightLedPin = 10;
const int RightSensorPin = A1;

void setup() {
  //Set Baud Rate, Required to use Serial Monitor Serial.begin(9600);
  pinMode(leftLedPin, OUTPUT);
  pinMode(leftSensorPin, INPUT);
  pinMode(RightLedPin, OUTPUT);
  pinMode(RightSensorPin, INPUT);     //Setting Imputs and Outputs for photosensor and motors
  
}
void loop() {

  //Read Sensor Values

  int leftLightLevel = analogRead(leftSensorPin);

  // If left light sensor is greater than threshold
  // then turn left Motor on, else turn left Motor off

  if (leftLightLevel > lightThreshold)
    digitalWrite(leftLedPin, HIGH);

  else
    digitalWrite(leftLedPin, LOW);


  int RightLightLevel = analogRead(RightSensorPin);

  // If Right light sensor is greater than threshold
  // then turn Right Motor on, else turn Right Motor off

  if (RightLightLevel > lightThreshold)
    digitalWrite(RightLedPin, HIGH);

  else
    digitalWrite(RightLedPin, LOW);
}
