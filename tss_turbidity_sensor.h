
// ==========
// TSS/TURBIDITY
// ==========
float raw_adc_tss;
float voltage_tss;
float value_tss = 0;

void tssTurbiditySensor(){
  raw_adc_tss = read_by_ads_tss();
  voltage_tss = ads.computeVolts(raw_adc_tss);   
  value_tss = voltage_tss;   
}


void tssPrintToSerialMonitor(){
  Serial.println("============== TSS ==============");
  Serial.print("ADC TSS: ");
  Serial.println(raw_adc_tss);
  Serial.print("Voltage TSS: ");
  Serial.println(voltage_tss);
  Serial.print("Value TSS: ");
  Serial.println(value_tss);
  Serial.println();
}
