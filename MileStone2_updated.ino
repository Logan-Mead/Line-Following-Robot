//Define Pin Mappings

const int leftLedPin = 9;
const int leftSensorPin = A0;
int lightThreshold=290;
const int RightLedPin = 10;
const int RightSensorPin = A1;
int Button = 11;
int Button_Pressed= 0;
int leftWhite;
int rightWhite;
int White;
int leftBlack;
int rightBlack;
int Black;
int prevButton=0;
int avg_thresh;
int ButtonPressed;
void setup() {
  //Set Baud Rate, Required to use Serial Monitor 
  Serial.begin(9600);
  pinMode(leftLedPin, OUTPUT);
  pinMode(leftSensorPin, INPUT);
  pinMode(RightLedPin, OUTPUT);
  pinMode(RightSensorPin, INPUT);     //Setting Imputs and Outputs for photosensor and motors
  pinMode(Button, INPUT);
  pinMode(Button_Pressed, INPUT);
}
void loop() {
    ButtonPressed = digitalRead(Button);
    int ButtonCount=0;    //inital button count at 0
     if (ButtonPressed != prevButton) {   //if button is pressed keep last button value
        if (ButtonPressed == LOW)
       {  
            Serial.println("Pressed");
             ButtonCount ++;      //if button is pressed add to the button counter
           if (ButtonCount == 1)    //if button count=1 read sensor values and create a white average value
            Serial.println("Test1");      //if button count =1 serial print that test 1 is running
            leftWhite = analogRead(leftSensorPin);
            rightWhite = analogRead(RightSensorPin);
            White == (leftWhite + rightWhite)/2;
          }
               else if (ButtonCount == 2)     //if button count=2 read sensor values and create a black average value
                  {
                    Serial.println ("Test2");       //if buttin count = 2 serial print that test 2 is running
                    leftBlack = analogRead(leftSensorPin);
                    rightBlack = analogRead(RightSensorPin);
                    Black== (leftBlack + rightBlack)/2;
                    lightThreshold = (Black + White)/2;   //create new lightThreshold value by adding black and white value and divide by 2
                   
                  } 
              
    
                    
                     if (ButtonCount == 3)
                    {
                      Serial.println("Running");        //if button count = 3 serial print that the rest of code is running
                    }
        
    
   

  
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
}
