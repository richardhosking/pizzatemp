/* 
 * pizzatemp.h 
 * Header for Helper files for pizzatemp project
 * 
 */
    
  class Pizzatemp{
  public:
  //Prototypes for helper_functions found in pizzatemp.cpp
    void printWiFiStatus(void);
    int measure_temp(void);
    void initialize_interrupt(void);
    
  // Variables
  private:
    float capacitor = 0.607; 	// capacitance in uF of the oscillator capacitor
    float cap = capacitor*1E-6;
    int offset = 281; 		// Offset for temp calculation - can be trimmed 
    float multiplier = 0.205; 	// Coefficient based on resistance change 0.385 ohms/deg C 
    float temp;
    int count, result;
    unsigned long start_milliseconds, current_milliseconds; // for interval timer
    const unsigned long period = 1000; // interval for counting frequency - 1 second 
   };
   
