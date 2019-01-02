/*
 * Helper files for pizzatemp project
 * 
 */
 
#ifndef HEADER_PIZZATEMPFUNC
  #define HEADER_PIZZATEMPFUNC

   
  class Pizzatemp{
  public:
  //Prototypes for helper_functions found in pizzatemp.cpp
    void printWiFiStatus(void);
    int measure_temp(void);
    void initialize_interrupt(void);

    
  // Variables
  private:
    int temp_offset = 1061;  	// freq in Hz at 0 deg C
    float temp_ratio = 0.3977;  	// Decrease in freq Hz per deg C increase in temp 
    float temp;
    int count, result;
    unsigned long start_milliseconds, current_milliseconds; // for interval timer
    const unsigned long period = 1000; // interval for counting frequency - 1 second 
   };
   
#endif
