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
  // Pin 0 interrupt priority 0 ie highest
  pinMode(0,INPUT_PULLUP);

 attachInterrupt(0,increment_counter, RISING); 
 // Call Interrupt service routine to incerement_counter when rising waveform on pin 0
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

// Displays a table of past temperatures 
// over the ;last several hours 
// via webserver
// Uses HTML only
// quotes limitations make for rather difficult to read code

void Pizzatemp::table(WiFiClient client){
  
  int last_temp =660;//<%= last_temp %>
  client.print("<table width=100% border=1 cellpadding=0 cellspacing=0>");
  client.print("<tr>");
  client.print("<td height='30' valign='bottom'><div align='left'>100</div></td><td width='0'rowspan='11' valign='bottom'><div align='center'>");
  client.print("</tr>");
  client.print("<td height='30' valign='bottom'><div align='right'>100</div></td><td width='0' rowspan='11' valign='bottom'><div align='center'>");
  client.print("<table width='100%' border='0' cellpadding='0' cellspacing='0'><tr>");
  client.print("<td width='50%' valign='bottom' ><table width='20' height=");
  client.print(last_temp);
  client.print("border='0' align='center' bordercolor='#FF0000' bgcolor='#CCCCFF'>");
  client.print("<tr><td></td></tr></table></td></tr></table></div></td>");
  /*client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");  
  client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");  
  client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");
  client.print("Previous temperature data : ");*/
  client.print("</tr>");
  client.print("</table>");  




  
}