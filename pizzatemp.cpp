/*
 * pizzatemp.cpp 
 * helper functions for the temp monitoring aspplication
 */

#include <WiFi101.h>
#include "Arduino.h"
#include "pizzatemp.h" 
   
void increment_counter(void); // ISR prototype - 
				 // need to declare outside a class  for Interrupt Service Routine 
int counter;
 
void increment_counter(){	// ISR Function	
  counter++;
}  
   
void Pizzatemp::printWiFiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}

void Pizzatemp::initialize_interrupt(){
   // Code to setup counter interrupt
  // Pin 0 interrupt priority 0 ie highest
  pinMode(0,INPUT_PULLUP);

    // Test Oscillator
  pinMode(1, OUTPUT);
  
 attachInterrupt(0,increment_counter, RISING); 
 // Call Interrupt service routine to incerement_counter when rising waveform on pin 0
}

int Pizzatemp::measure_temp(){
/* this routine measures the current temp of the probe 
 * Temp change is approx 0.375 Ohms per degree C increase 1000 ohms at 0 deg C 
 * which translates to a freq decrease of approx 0.3977 Hz per Deg C increase
 * Pseudocode
 * Count output freq of relaxation oscillator over a timed period
 * Calculate temp T where
 * T = (temp_offset - count) /temp_ratio
 * convert to int and return
 */
  
//clear counter
counter=0;
start_milliseconds = millis(); //get current time 
current_milliseconds = millis();

// delay of 1 sec - pulses counted by interrupt service routine increment_counter
while(current_milliseconds - start_milliseconds <= period){
  current_milliseconds = millis(); 
    unsigned long start_micros = micros();
    unsigned long current_micros = micros();
    unsigned long delay = 57000;
    
  // Test oscillator approx 1KHz on pin1 
  for(int i = 0; i<=100; i++){
     while(current_micros - start_micros <=delay){
      current_micros = micros();// Wait 500us
    }
      //Toggle the pin 
    digitalWrite(1, !digitalRead(1));
    unsigned long start_micros = micros();
    unsigned long current_micros = micros();
  }
    
}
count = counter;

// Calculate temp from freq counter
temp = (temp_offset - count)/temp_ratio;
result = (int)temp;

return result;

}


