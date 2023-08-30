
// ==========
// TSS/TURBIDITY
// ==========
float raw_adc_tss;
float voltage_tss;
float value_tss = 0;

void tssTurbiditySensor(){
  raw_adc_tss = read_by_ads_tss();
  voltage_tss = ads.computeVolts(raw_adc_tss);   
  // value_tss = voltage_tss; // comment baris ini jika rumus sudah ada;

  if(nomor_akuarium == 7){
    value_tss = (-0.501 * voltage_tss) + 2.42;
  }

  if(nomor_akuarium == 8){
    value_tss = (0.2 * voltage_tss) + -0.45;
  }

  if(nomor_akuarium == 9){
    // value_tss = (-13.7 * voltage_tss) + 44.1;
    value_tss = voltage_tss; // comment baris ini jika rumus sudah ada;
  }

  if(nomor_akuarium == 10){
    value_tss = (-9.5 * voltage_tss) + 31.4;
  }

  if(nomor_akuarium == 11){
    value_tss = (-3.75 * voltage_tss) + 15.7;
  }

  if(nomor_akuarium == 12){
    value_tss = (-0.605 * voltage_tss) + 2.84;
  }

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
