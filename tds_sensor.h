// ==========
// SENSOR TDS
// ==========
byte pin_tds = 32; // Pin analog TDS

<<<<<<< HEAD
float raw_adc_tds, voltage_tds = 0, value_tds = 0, value_tds_cal = 0;
=======
float raw_adc_tds, voltage_tds = 0, value_tds = 0;
>>>>>>> 39b9bb9ab55ebde30e73af6b838a8042048a64d9
int value_temperature_dummy = 25;

void tdsSensor()
{
  raw_adc_tds = read_by_ads_tds();
  voltage_tds = ads.computeVolts(raw_adc_tds);
  float compensationCoefficient = 1.0 + 0.02 * (value_temperature - 25.0);
  float compensationVoltage = voltage_tds / compensationCoefficient;
  value_tds = (133.42 * compensationVoltage * compensationVoltage * compensationVoltage - 255.86 * compensationVoltage * compensationVoltage + 857.39 * compensationVoltage) * 0.60;
       
}

void tdsPrintToSerialMonitor(){
  Serial.println("============== TDS ==============");
  Serial.print("ADC TDS: ");
  Serial.println(raw_adc_tds);
  Serial.print("Voltage TDS: ");
  Serial.println(voltage_tds);
  Serial.print("TDS Value: ");
  Serial.print(value_tds);
  Serial.println("ppm");
  Serial.println();
}
