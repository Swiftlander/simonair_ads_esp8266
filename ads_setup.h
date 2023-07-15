
#include <Wire.h>
#include <Adafruit_ADS1X15.h>
#include <RunningMedian.h>

Adafruit_ADS1115 ads;

int16_t adc0_ph, adc1_tds, adc2_tss, adc3_mq;
float volts_ph, volts_tds, volts_tss, volts_mq;

RunningMedian median_ph = RunningMedian(1);
RunningMedian median_tds = RunningMedian(1);
RunningMedian median_tss = RunningMedian(1);
RunningMedian median_mq = RunningMedian(1);

void setup_ads(){
  Wire.begin();

  if (!ads.begin()){
    Serial.println("Failed to initialize ADS.");
  }
}


int16_t read_by_ads_ph(){
  adc0_ph = ads.readADC_SingleEnded(0);  // Untuk Sensor PH
  median_ph.add(adc0_ph);
  adc0_ph = median_ph.getMedian();
  return adc0_ph;
}

int16_t read_by_ads_tds(){
  adc1_tds = ads.readADC_SingleEnded(1);  // Untuk Sensor TDS
  median_tds.add(adc1_tds);
  adc1_tds = median_tds.getMedian();
  return adc1_tds;
}

int16_t read_by_ads_tss(){
  adc2_tss = ads.readADC_SingleEnded(2);  // Untuk Sensor TSS/Turbidity
  median_tss.add(adc2_tss);
  adc2_tss = median_tss.getMedian();
  return adc2_tss;
}

int16_t read_by_ads_mq(){
  adc3_mq = ads.readADC_SingleEnded(3);  // Untuk Sensor MQ
  median_mq.add(adc3_mq);
  adc3_mq = median_mq.getMedian();
  return adc3_mq;
}