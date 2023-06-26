// ==========
// SALINITAS
// ==========

float raw_adc_salinity;
float voltage_salinity;
float value_salinity = 0;


void salinitySensor(){
  raw_adc_salinity = read_by_ads_tds();
  voltage_salinity = ads.computeVolts(raw_adc_salinity);
  value_salinity = voltage_salinity;
}

void salinityPrintToSerialMonitor(){
  Serial.println("============== SALINITY ==============");
  Serial.print("ADC salinity: ");
  Serial.println(raw_adc_salinity);
  Serial.print("Voltage salinity: ");
  Serial.println(voltage_salinity);
  Serial.print("Salinity Value: ");
  Serial.println(value_salinity);
  Serial.println();
        
}