
// ==========
// SENSOR PH
// ==========

float raw_adc_ph, voltage_ph, value_ph;

// Akuarium 7 = (voltage_ph - 3.7436) / -0.1693;
// Akuarium 8 =  (voltage_ph - 4.1593) / -0.0993;
// Akuarium 9 = (voltage_ph - 3.8829) / -0.1848;
// Akuarium 10 = (voltage_ph - 3.8356) / -0.1746;

void phSensor(){
    raw_adc_ph = read_by_ads_ph();
    voltage_ph = ads.computeVolts(raw_adc_ph);
    value_ph = (voltage_ph - 4.1593) / -0.0993;
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
