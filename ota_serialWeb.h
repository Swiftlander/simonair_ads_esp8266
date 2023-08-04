#include <Arduino.h>

#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <AsyncElegantOTA.h>

#include <WebSerial.h>


// ====================================================
// KONFIGURASI OTA UPDATE | START
// ====================================================
 AsyncWebServer serverOTA(80);
// ====================================================
// KONFIGURASI OTA UPDATE | END
// ====================================================

void setup_ota_serial_web(){
    AsyncElegantOTA.begin(&serverOTA);
    WebSerial.begin(&serverOTA);
    serverOTA.begin();
}

void ph_value_print_to_web_serial(){
  WebSerial.println("============== PH ==============");
  // WebSerial.print("ADC PH: ");
  // WebSerial.println(raw_adc_ph);
  WebSerial.print("Voltage PH: ");
  WebSerial.println(voltage_ph);
  WebSerial.print("Nilai PH: ");
  WebSerial.println(value_ph);
  WebSerial.println();
}

void tds_value_print_to_web_serial(){
  WebSerial.println("============== TDS ==============");
  // WebSerial.print("ADC TDS: ");
  // WebSerial.println(raw_adc_tds);
  WebSerial.print("Voltage TDS: ");
  WebSerial.println(voltage_tds);
  WebSerial.print("TDS Value: ");
  WebSerial.print(value_tds);
  WebSerial.println("ppm");
  WebSerial.println();
}

void tss_value_print_to_web_serial(){
  WebSerial.println("============== TSS/TURBIDITY ==============");
  // WebSerial.print("ADC TSS/TURBIDITY: ");
  // WebSerial.println(raw_adc_tss);
  WebSerial.print("Voltage TSS/TURBIDITY: ");
  WebSerial.println(voltage_tss);
  WebSerial.print("Nilai TURBIDITY: ");
  WebSerial.println(value_tss);
  WebSerial.println();
}

void temperature_value_print_to_web_serial(){
  WebSerial.println("============== TEMPERATURE ==============");
  WebSerial.print("Nilai Suhu: ");
  WebSerial.println(value_temperature);
  WebSerial.println();
}

void mq_value_print_to_web_serial(){
  WebSerial.println("============== MQ ==============");
  // WebSerial.print("ADC MQ: ");
  // WebSerial.println(raw_adc_mq);
  WebSerial.print("Voltage MQ: ");
  WebSerial.println(voltage_mq);
  WebSerial.print("Nilai MQ: ");
  WebSerial.println(value_mq_ppm);
  WebSerial.println();
}

void salinity_value_print_to_web_serial(){
  WebSerial.println("============== Salinity ==============");
  // WebSerial.print("ADC Salinity: ");
  // WebSerial.println(raw_adc_salinity);
  WebSerial.print("Voltage salinity: ");
  WebSerial.println(voltage_salinity);
  WebSerial.print("Nilai salinity: ");
  WebSerial.println(value_salinity);
  WebSerial.println();
}





