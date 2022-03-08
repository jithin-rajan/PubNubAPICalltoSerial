
 // Wiring/Arduino code:
 // Read data from the serial and turn ON or OFF a light depending on the value
 #include <Servo.h> // servo library is always included when using servos 

 Servo myservo ; //myservo is the variable name assigned to the servo 

                    //moves the servo from 0 to 180 degrees 
 int pos = 0 ;
 String string;
// char val[20]; // Data received from the serial port
 int ledPin = 7; // Set the pin to digital I/O 4
 
 void setup() {
 pinMode(ledPin, OUTPUT); // Set pin as OUTPUT
 myservo.attach(4); //written in setup method, servo is attached to pin 8 
 Serial.begin(9600); // Start serial communication at 9600 bps
 }
 
 void loop()
    {
      while (Serial.available()) 
      { // If data is available to read,
         string = String(Serial.readString());
         string.trim();
        //val[0] = Serial.read(); // read it and store it in val
         Serial.println(string); 
            
      
 if (string == "lightOn") 
 { // If H was received
 digitalWrite(ledPin, HIGH); // turn the LED on
 }
 else if (string == "lightOff")
 {
 digitalWrite(ledPin, LOW); // Otherwise turn it OFF
 }
 else if (string == "servoOpen")
 {
     for (pos = 0; pos <= 180; pos += 1)
     { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);       
      }
 }
 else
  {
    for (pos = 180; pos >= 0; pos -= 1) 
    { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
    }
  Serial.println(string);
   
 }
  }
 delay(100); // Wait 100 milliseconds for next reading
 }
 

 
 

 
