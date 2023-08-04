
// ==========
// TSS/TURBIDITY
// ==========
float raw_adc_tss;
float voltage_tss;
float value_tss = 0;

// Akuarium 7 = (-0.952 * voltage_tss) + 3.64;
// Akuarium 9 = (-9.5 * voltage_tss) + 31.4;
// Akuarium 10 = (-9.5 * voltage_tss) + 31.4;
// Akuarium 12 = (17 * voltage_tss) + -32.4;

void tssTurbiditySensor(){
  raw_adc_tss = read_by_ads_tss();
  voltage_tss = ads.computeVolts(raw_adc_tss);   
  value_tss = voltage_tss;

  // if(nomor_akuarium == 7){
  //   value_tss = (-0.952 * voltage_tss) + 3.64;
  // }

  // if(nomor_akuarium == 8){
  //   value_tss = (-28.5 * voltage_tss) + 128;
  // }

  // if(nomor_akuarium == 9){
  //   value_tss = (-9.5 * voltage_tss) + 31.4;
  // }

  // if(nomor_akuarium == 10){
  //   value_tss = (-9.5 * voltage_tss) + 31.4;
  // }

  // if(nomor_akuarium == 11){
  //   value_tss = (-1.67 * voltage_tss) + 6.4;
  // }

  // if(nomor_akuarium == 12){
  //   value_tss = (0.952 * voltage_tss) + 0.437;
  // }
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
