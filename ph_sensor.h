
// ==========
// SENSOR PH
// ==========

float raw_adc_ph, voltage_ph, value_ph;

// kalibrasi Ph
// float PH4 = 2.96f;
// float PH7 = 2.6f;

void phSensor(){
    raw_adc_ph = read_by_ads_ph();
    voltage_ph = ads.computeVolts(raw_adc_ph);
    value_ph = (voltage_ph - 3.636) / -0.1511;
}

void phPrintToSerialMonitor(){
  Serial.println("============== PH ==============");
  Serial.print("ADC PH: ");
  Serial.println(raw_adc_ph);
  Serial.print("Voltage PH: ");
  Serial.println(voltage_ph);
  Serial.print("Nilai PH: ");
  Serial.println(value_ph);
  Serial.println();

}