
// ==========
// SENSOR PH
// ==========

float raw_adc_ph, voltage_ph, value_ph;

// ============ V2 ============
// Akuarium 7 = (voltage_ph - 3.7436) / -0.1693;
// Akuarium 8 =  (voltage_ph - 4.1593) / -0.1593;
// Akuarium 9 = (voltage_ph - 3.8829) / -0.1848;
// Akuarium 10 = (voltage_ph - 3.7436) / -0.1743;
// Akuarium 11 = (voltage_ph - 3.8356) / -0.1746;
// Akuarium 12 = (voltage_ph - 4.4495) / -0.1037;

// ============ V2 ============
// Akuarium 7 = (voltage_ph - 3.7436) / -0.1693;
// Akuarium 8 = (voltage_ph - 4.1593) / -0.0993;
// Akuarium 9 = (voltage_ph - 3.8829) / -0.1848;
// Akuarium 10 = (voltage_ph - 3.7436) / -0.1693;
// Akuarium 11 = (voltage_ph - 3.8356) / -0.1746;
// Akuarium 12 = (voltage_ph - 4.4495) / -0.0677;

// Regresi Linear
// Akuarium 8 = (0.0616 * value_ph) + 7.33;
// Akuarium 12 = (0.553 * value_ph) + -0.337;

void phSensor(){
    raw_adc_ph = read_by_ads_ph();
    voltage_ph = ads.computeVolts(raw_adc_ph);

    if(nomor_akuarium == 7){
      value_ph = (voltage_ph - 3.7436) / -0.1693;
      // value_ph = -0.0753 * value_ph + 8.52;
    }

    if(nomor_akuarium == 8){
      value_ph = (voltage_ph - 4.1593) / -0.0993;
      value_ph = (0.0616 * value_ph) + 7.33;
    }

    if(nomor_akuarium == 9){
      value_ph = (voltage_ph - 3.8829) / -0.1848;
      value_ph = -1.74E-03 * value_ph + 7.98;
    }

    if(nomor_akuarium == 10){
      value_ph = (voltage_ph - 3.7436) / -0.1693;
      value_ph = 0.752 * value_ph + 2.69;
    }

    if(nomor_akuarium == 11){
      value_ph = (voltage_ph - 3.8356) / -0.1746;
      value_ph = -0.0231 * value_ph + 8.29;
    }

    if(nomor_akuarium == 12){
      value_ph = (voltage_ph - 4.4495) / -0.0677;
      value_ph = (0.553 * value_ph) + -0.337;
    }
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
