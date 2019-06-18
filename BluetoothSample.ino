// Faraday Challenge Bluetooth Sample Code
// This sample code shows you how to accept
// simple commands from Android Apps through
// Bluetooth. 

// Author: Ivan Ling
// Version 1.2
// Last updated: 10/6/2019

// Connection:
// HC-05 Bluetooth Module
// HC05  |  Arduino
//  VCC  |  5V
//  GND  |  GND
//   TX  |  RX  (Pin 0)
//   RX  |  TX  (Pin 1)
// Leave other HC05 Pins disconnected.
/****************************************
 IMPORTANT
 When programming the Arduino, make sure 
 that the TX and RX of the Bluetooth module
 is not connected. Reconnect after programming.
******************************************/
String serialInput = " ";

void setup() {
  // Put your setup code here
  // For this example, we are turning the 
  // Built-in LED (Pin 13) on and off
  // Depending on your Input. 
  // Make sure you make an Android app to send "ON" and "OFF"
  // via Bluetooth Client before proceeding.
  
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
// Here, we will read the Serial input only if there is an input. if bluetooth
// is not connected, we don't read.  
while(Serial.available()) {
  serialInput = Serial.readString();// read the incoming data as string
}
  // Here is an example of how we can do something when we receive a command.
  // If your Android App sends an "ON" command, we turn on the LED
  if(serialInput == "ON")
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  
  // If your Android App sends an "OFF" command, we turn off the LED
  else if(serialInput == "OFF")
  {
    digitalWrite(LED_BUILTIN, LOW);
  }
}
