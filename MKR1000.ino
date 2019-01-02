/*
  
  Temperature monitoring application
  Richard Hosking Dec 2018
  Temp measured using platinum resistor sensor
  Temp => ohms => oscillator frequency
  converted to deg C and displayed via simple local webserver 
  
  using 
  
  WiFi Web Server

 A simple web server that shows the value of the analog input pins.
 using a WiFi shield.

 This example is written for a network using WPA encryption. For
 WEP or WPA, change the WiFi.begin() call accordingly.

  created 13 July 2010
 by dlf (Metodo2 srl)
 modified 31 May 2012
 by Tom Igoe

 */

#include <SPI.h>
#include <WiFi101.h>

#include "arduino_secrets.h" 	// sensitive data in the Secret tab/arduino_secrets.h
#include "pizzatemp.h" 		// Helper files 

char ssid[] = SECRET_SSID;      // your network SSID (name)
char pass[] = SECRET_PASS;    	// your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;               // your network key Index number (needed only for WEP)

Pizzatemp helper; //Need to declare an instance of class to use helpers 


// Wifi stuff
int status = WL_IDLE_STATUS;
WiFiServer server(80);

//#include "pizzatemp.cpp" // Project specific routines

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
     // wait for serial port to connect. Needed for native USB port only
  }
  
     helper.initialize_interrupt();
     
  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  }

  // attempt to connect to WiFi network:
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);// wait 1 second
  }
  server.begin();
  // you're connected now, so print out the status:
  helper.printWiFiStatus();
}
// wait 1 second

void loop() {
  // listen for incoming clients
  WiFiClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
          client.println("Refresh: 5");  // refresh the page automatically every 10 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");

	  client.print("Current Oven temperature is : ");
	  int sensorReading = helper.measure_temp();
	  client.print(sensorReading);
	  client.println("<br />");
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        }
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);

    // close the connection:
    client.stop();

    Serial.println("client disconnected");
  }
}


