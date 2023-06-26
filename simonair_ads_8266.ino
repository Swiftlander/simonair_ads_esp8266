// ====================================================
// KONFIGURASI LED INTERNAL | START
// ====================================================
int indikator = 2;
// ====================================================
// KONFIGURASI LED INTERNAL | END
// ====================================================

#include "ads_setup.h"

#include "temperature_sensor.h"
#include "tds_sensor.h"
#include "ph_sensor.h"
#include "tss_turbidity_sensor.h"
#include "mq_sensor.h"
#include "salinity_sensor.h"

#include "wifi_conf.h"
#include "send_data.h"

#include "ota_serialWeb.h"
// #include "lcd_display.h"

// INTERVAL PEMBACAAN
unsigned long intervalSendTime = 30000;
unsigned long prevCurrentTimeSend = 0;
unsigned long intervalPrintTime = 2000;
unsigned long prevCurrentTimePrint = 0;
unsigned long intervalSendDataTime = 15000;
unsigned long prevCurrentTimeSendData = 0;
unsigned long intervalPrintSerialWebTime = 20000;
unsigned long prevCurrentTimePrintSerialWeb = 0;

void setup(){
    Serial.begin(115200);
    pinMode(indikator, OUTPUT); 
    setup_ads();
    // setupLcd();
}

void loop(){
    
  unsigned long currentTime = millis();

  if (WiFi.status() != WL_CONNECTED){
    initWiFi();
    setup_ota_serial_web();
  }

  temperatureSensorFunction();
  phSensor();
  tdsSensor();
  tssTurbiditySensor();
  salinitySensor();
  readMQ();

    if(currentTime - prevCurrentTimePrint >= intervalPrintTime){

      temperaturePrintToSerialMonitor();
      phPrintToSerialMonitor();
      tdsPrintToSerialMonitor();
      tssPrintToSerialMonitor();
      salinityPrintToSerialMonitor();
      mqPrintToSerialMonitor();

      prevCurrentTimePrint = currentTime;
    }
 

    if (currentTime - prevCurrentTimePrintSerialWeb >= intervalPrintSerialWebTime){
      if (WiFi.status() == WL_CONNECTED){
          temperature_value_print_to_web_serial();
          ph_value_print_to_web_serial();
          tds_value_print_to_web_serial();
          tss_value_print_to_web_serial();
          salinity_value_print_to_web_serial();
          mq_value_print_to_web_serial();
      }
      prevCurrentTimePrintSerialWeb = currentTime;
    }


    if(currentTime - prevCurrentTimeSendData >= intervalSendDataTime){
      if (WiFi.status() == WL_CONNECTED){
        sendData();
      }
      prevCurrentTimeSendData = currentTime;
    }    


  // statusParamsText(0, value_temperature, value_ph, value_tds, value_tss, value_salinity, value_mq_ppm, 500, 16);
}
