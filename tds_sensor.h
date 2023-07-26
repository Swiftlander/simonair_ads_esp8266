// ==========
// SENSOR TDS
// ==========
byte pin_tds = 32; // Pin analog TDS

// Default = 0.60
// Akuarium 8 = 0.67
// Akuarium 9 = 0.86
// Akuarium 10 = 0.27
// Akuarium 12 = 0.72

float raw_adc_tds, voltage_tds = 0, value_tds = 0;

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
