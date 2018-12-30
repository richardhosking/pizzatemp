/*
  WiFi Web Server

 A simple web server that shows the value of the analog input pins.
 using a WiFi shield.

 This example is written for a network using WPA encryption. For
 WEP or WPA, change the WiFi.begin() call accordingly.

 Circuit:
 * WiFi shield attached
 * Analog inputs attached to pins A0 through A5 (optional)

 created 13 July 2010
 by dlf (Metodo2 srl)
 modified 31 May 2012
 by Tom Igoe

 */

#include <SPI.h>
#include <WiFi101.h>

#include "arduino_secrets.h" 	// sensitive data in the Secret tab/arduino_secrets.h
char ssid[] = SECRET_SSID;      // your network SSID (name)
char pass[] = SECRET_PASS;    	// your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;               // your network key Index number (needed only for WEP)

int temp_offset = 1061;  // freq in Hz at 0 deg C
float temp_ratio = 0.3977;  // Decrease in freq Hz per deg C increase in temp 

int counter=0; // pulse counter to determine frequency
unsigned long start_milliseconds, current_milliseconds; // for interval timer
const unsigned long period = 1000; // interval for counting frequency - 1 second 

// Wifi stuff
int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  // Code to setup counter interrupt
  // Pin 0 interrupt priority 0 ie highest
  pinMode(0,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(0), increment_counter, RISING);
  
  // Test Oscillator
  pinMode(1, OUTPUT);
  
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
  printWiFiStatus();
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
          // output the value of each analog input pin
          /*for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
            int sensorReading = analogRead(analogChannel);
            client.print("analog input ");
            client.print(analogChannel);
            client.print(" is ");
            client.print(sensorReading);
            client.println("<br />");
          }
          */
	  client.print("Current Oven temperature is : ");
	  int sensorReading = measure_temp();
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


void printWiFiStatus() {
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

int measure_temp(){
/* this routine measures the current temp of the probe 
 * Temp change is approx 0.375 Ohms per degree C increase 1000 ohms at 0 deg C 
 * which translates to a freq decrease of approx 0.3977 Hz per Deg C increase
 * Pseudocode
 * Count output freq of relaxation oscillator over a timed period
 * Calculate temp T where
 * T = (temp_offset - count) /temp_ratio
 * convert to int and return
 */
float temp;
int count, result;

//clear counter
counter=0;
start_milliseconds = millis(); //get current time 
current_milliseconds = millis();

// delay of 1 sec - pulses counted by interrupt service routine increment_counter
while(current_milliseconds - start_milliseconds <= period){
  current_milliseconds = millis(); 
    unsigned long start_micros = micros();
    unsigned long current_micros = micros();
    unsigned long delay = 55000;
    
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

// Interrupt service routine for counter

void increment_counter(){
  counter++;
}
