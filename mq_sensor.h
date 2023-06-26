
// ==========
// MQ-137
// ==========

// #define RL 4.7    //The value of resistor RL is 47K
// #define m -0.263  //Enter calculated Slope 
// #define b 0.42    //Enter calculated intercept
// #define Ro_final 20 //Enter found Ro value
float RL = 4.7;    //The value of resistor RL is 47K
float m  = -0.263;  //Enter calculated Slope 
float b = 0.42;    //Enter calculated intercept

float analog_value_searchRO;
float VRL_searchRO;
float Rs_searchRO;
float Ro_searchRO;
float Ro_final;

float VRL; //Voltage drop across the MQ sensor
float Rs; //Sensor resistance at gas concentration 
float ratio; //Define variable for ratio
float value_mq_ppm = 0;

float raw_adc_mq, voltage_mq;

void readMQ(){
  raw_adc_mq = read_by_ads_mq();
  voltage_mq = ads.computeVolts(raw_adc_mq); 

  VRL_searchRO = voltage_mq; //Convert analog value to voltage
  Rs_searchRO = ((5.0/VRL)-1) * RL;
  Ro_searchRO = Rs_searchRO/3.6;
  Ro_final = Ro_searchRO;
  delay(1000); //delay of 1sec
  
  VRL = voltage_mq; //Measure the voltage drop and convert to 0-5V
  Rs = ((5.0*RL)/VRL)-RL; //Use formula to get Rs value
  ratio = Rs/Ro_final;  // find ratio Rs/Ro
  value_mq_ppm = pow(10, ((log10(ratio)-b)/m)); //use formula to calculate ppm

}

// void searchROMQ(){

//   for(int test_cycle = 1 ; test_cycle <= 500 ; test_cycle++) //Read the analog output of the sensor for 200 times
//   {
//     analog_value_searchRO = analog_value_searchRO + read_by_ads_mq(); //add the values for 200
//   }
//   analog_value_searchRO = analog_value_searchRO/500.0; //Take average
//   VRL_searchRO = ads.computeVolts(analog_value_searchRO); //Convert analog value to voltage
//   //RS = ((Vc/VRL)-1)*RL is the formulae we obtained from datasheet
//   Rs_searchRO = ((5.0/VRL)-1) * RL;
//   //RS/RO is 3.6 as we obtained from graph of datasheet
//   Ro_searchRO = Rs/3.6;
//   delay(1000); //delay of 1sec

// }

// void mqSensor() {
//   raw_adc_mq = read_by_ads_mq();
//   voltage_mq = ads.computeVolts(raw_adc_mq); 
//   VRL = voltage_mq; //Measure the voltage drop and convert to 0-5V
//   Rs = ((5.0*RL)/VRL)-RL; //Use formula to get Rs value
//   ratio = Rs/Ro_final;  // find ratio Rs/Ro

//   // value_mq_ppm = pow(10, ((log10(ratio)-b)/m)); //use formula to calculate ppm
//   value_mq_ppm = VRL; //use formula to calculate ppm
// }

void mqPrintToSerialMonitor(){
  Serial.println("============== MQ ==============");
  Serial.print("ADC MQ: ");
  Serial.println(raw_adc_mq);
  Serial.print("ADC Voltage MQ: ");
  Serial.println(voltage_mq);
  Serial.print("RO MQ: ");
  Serial.println(Ro_searchRO);
  Serial.print("Nilai MQ Ammonia: ");
  Serial.println(value_mq_ppm);
  Serial.println();

}
