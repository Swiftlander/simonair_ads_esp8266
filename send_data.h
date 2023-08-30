#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

String nama_alat;
String id_alat;

String serverName = "http://simonair.my.id/";

byte server[] = {103, 117, 57, 130};
WiFiClient client;
const int httpPort = 80;
String url;
unsigned long timeout;

void sendData(){
  
  if(nomor_akuarium == 7){
  nama_alat = "Akuarium 7";
  id_alat = "99fd53ee-f251-4a11-bb8c-3afbfa3f25d1";
  }

  if(nomor_akuarium == 8){
    nama_alat = "Akuarium 8";
    id_alat = "99fd53f8-7d30-48e6-8871-374bbde0c5d5";
  }

  if(nomor_akuarium == 9){
    nama_alat = "Akuarium 9";
    id_alat = "99fd5403-7a55-46b3-8633-de4c54f71206";
  }

  if(nomor_akuarium == 10){
    nama_alat = "Akuarium 10";
    id_alat = "99fd5410-182e-489a-b8b5-0f13f84a7e20";
  }

  if(nomor_akuarium == 11){
    nama_alat = "Akuarium 11";
    id_alat = "99fd5449-7b89-4128-9b10-cf3e337da217";
  }

  if(nomor_akuarium == 12){
    nama_alat = "Akuarium 12";
    id_alat = "99fd5454-0463-4030-95d0-ac870be5ff1b";
  }

  WiFiClient client;
  HTTPClient http;

  String suhu = String(value_temperature);
  String ph = String(value_ph);
  String amonia = String(value_mq_ppm);
  String tss = String(value_tss);
  String tds = String(value_tds);
  String salinitas = String(value_salinity);

  String serverPath = serverName + "api/monitoring/" +
                id_alat + "/" +
                ph + "/" +
                suhu + "/" +
                amonia + "/" +
                tss + "/" +
                tds + "/" +
                salinitas;

  http.begin(client, serverPath.c_str());

  // Send HTTP GET request
  int httpResponseCode = http.GET();

  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String payload = http.getString();
    Serial.println(payload);
    } else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
      }

  http.end();

}


void sendDataVoltage(){
    
  if(nomor_akuarium == 7){
  nama_alat = "Akuarium 7";
  id_alat = "HF22Bd9A71hh";
  }

  if(nomor_akuarium == 8){
    nama_alat = "Akuarium 8";
    id_alat = "dO7NeYGaBo52";
  }

  if(nomor_akuarium == 9){
    nama_alat = "Akuarium 9";
    id_alat = "99fc8849-9406-48cb-95fb-be45a76a45cb";
  }

  if(nomor_akuarium == 10){
    nama_alat = "Akuarium 10";
    id_alat = "99fc3e74-66a1-4cb7-8d65-5b30d3bfe764";
  }

  if(nomor_akuarium == 11){
    nama_alat = "Akuarium 11";
    id_alat = "eD5GEfu6iAYP";
  }

  if(nomor_akuarium == 12){
    nama_alat = "Akuarium 12";
    id_alat = "OZMCyBAnnGve";
  }

  WiFiClient client_voltage;
  HTTPClient http_voltage;

  float volt_ph = voltage_ph;
  float volt_tds = voltage_tds;
  float volt_tss = voltage_tss;
  float volt_amonia = voltage_mq;

  String ph = String(value_ph);
  String tds = String(value_tds);
  String tss = String(value_tss);
  String amonia = String(value_mq_ppm);

  String serverPath = serverName + "api/monitoring/voltage" +
                id_alat + "/" +
                nama_alat + "/" +
                ph + "/" +
                "0" + "/" +
                amonia + "/" +
                tss + "/" +
                tds + "/" +
                "0";

  http_voltage.begin(client_voltage, serverPath.c_str());

  // Send HTTP GET request
  int httpResponseCode = http_voltage.GET();

  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String payload = http_voltage.getString();
    Serial.println(payload);
    } else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
      }

  http_voltage.end();

}


