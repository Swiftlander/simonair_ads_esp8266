#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

// Akuarium 7 = HF22Bd9A71hh
// Akuarium 8 = dO7NeYGaBo52
// Akuarium 9 = xpnyHMCHUfzb
// Akuarium 10 = U9HfLIhLQJGQ
// Akuarium 11 = eD5GEfu6iAYP
// Akuarium 12 = OZMCyBAnnGve

String nama_alat;
String id_alat;

String serverName = "http://simonair.portalsvipb.com/";

byte server[] = {103, 117, 57, 130};
WiFiClient client;
const int httpPort = 80;
String url;
unsigned long timeout;

void sendData(){
  
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
    id_alat = "xpnyHMCHUfzb";
  }

  if(nomor_akuarium == 10){
    nama_alat = "Akuarium 10";
    id_alat = "U9HfLIhLQJGQ";
  }

  if(nomor_akuarium == 11){
    nama_alat = "Akuarium 11";
    id_alat = "eD5GEfu6iAYP";
  }

  if(nomor_akuarium == 12){
    nama_alat = "Akuarium 12";
    id_alat = "OZMCyBAnnGve";
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
                nama_alat + "/" +
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
