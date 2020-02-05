/*
 * pizzatemp.cpp 
 * helper functions for the temp monitoring aspplication
 */

#include <WiFi101.h>
#include "Arduino.h"
#include "pizzatemp.h" 
   
void increment_counter(void); // Interrupt Service Routine prototype - 
			      // need to declare outside a class to work 
int counter;
 
void increment_counter(){	// and the actual function is part of ISR 	
  counter++;
}  
   
void Pizzatemp::printWiFiStatus() {
  IPAddress ip = WiFi.localIP();
  long rssi = WiFi.RSSI();

  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:

  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:

  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");

}

// Set up counter interrupt 
void Pizzatemp::initialize_interrupt(){
  // Pin 4 interrupt priority 0 ie highest
  pinMode(4,INPUT_PULLUP);

 attachInterrupt(4,increment_counter, RISING); 
 // Call Interrupt service routine to incerement_counter when rising waveform on pin 4 which is oscillator output
}

int Pizzatemp::measure_temp(){
/* this routine measures the current temp of the probe 
 * resistance change with temperature is approx 0.375 Ohms per degree C increase 
 * from (nominally) 1000 ohms at 0 deg C - this quite linear 
 * which translates to a freq decrease of approx ?? Hz per Deg C increase
 * Variables are set in pizzatemp.h
 * These can be trimmed to suit each build 
 * Pseudocode
 * Count output freq of relaxation oscillator over a timed period
 * Calculate temp T where
 * T = multiplier/(freq* C) - offset
 * where C = oscillator capacitance
 * convert to int and return
 */
  
//clear counter
counter=0;
start_milliseconds = millis(); //get current time 
current_milliseconds = millis();

// delay of 1 sec - pulses counted by interrupt service routine increment_counter
while(current_milliseconds - start_milliseconds <= period){
  current_milliseconds = millis(); 
}

count = counter;
// Calculate temp from freq counter
temp = multiplier/(count*cap) - offset ;

#ifdef DEBUGMODE
Serial.print("Count  :");
Serial.println(count);

Serial.print("capacitor  :");
Serial.println(capacitor);

Serial.print("offset  :");
Serial.println(offset);
#endif

result = (int)temp; // convert temp float to integer

return result;

}

