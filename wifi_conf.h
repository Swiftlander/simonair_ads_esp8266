// ====================================================
// WIFI
// ====================================================
#include <ESP8266WiFi.h>

// ======== WIFI 1 ========
const char* ssid = "Acer";
const char* password = "1029384756";

String ip_address;
IPAddress local_IP;
// IPAddress local_IP(192,168,137,100);
IPAddress gateway(192,168,137,1);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8);
IPAddress secondaryDNS(8, 8, 4, 4);
// ======== WIFI 1 ========


// ======== WIFI 2 ========
// const char* ssid = "Canon-Pixma-E460";
// const char* password = "Ikanlele1kilo";

// String ip_address;
// IPAddress local_IP;
// IPAddress gateway(172, 22, 38, 254);
// IPAddress subnet(255, 255, 255, 0);
// IPAddress primaryDNS(8, 8, 8, 8);
// IPAddress secondaryDNS(8, 8, 4, 4);
// ======== WIFI 2 ========

void initWiFi() {

  if(nomor_akuarium == 7){
    ip_address = "172.22.38.17";
    local_IP.fromString(ip_address.c_str());
  }

  if(nomor_akuarium == 8){
    ip_address = "172.22.38.18";
    local_IP.fromString(ip_address.c_str());
  }

  if(nomor_akuarium == 9){
    ip_address = "172.22.38.19";
    local_IP.fromString(ip_address.c_str());
  }
  
  if(nomor_akuarium == 10){
    ip_address = "172.22.38.20";
    local_IP.fromString(ip_address.c_str());
  }
  
  if(nomor_akuarium == 11){
    ip_address = "172.22.38.21";
    local_IP.fromString(ip_address.c_str());
  }

  if(nomor_akuarium == 12){
    ip_address = "172.22.38.22";
    local_IP.fromString(ip_address.c_str());
  }

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
    Serial.println("STA Failed to configure");
  }
  
  Serial.println("Connecting to WiFi ..");

  if (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    Serial.println("\nConnecting..");
    digitalWrite(indikator, LOW);
    delay(1000);
    digitalWrite(indikator, HIGH);
    delay(1000);
  }

  if (WiFi.status() == WL_CONNECTED)
   {
    Serial.println("Connected!!!");
    digitalWrite(indikator, HIGH);
    Serial.println(WiFi.localIP());
    delay(1000);
   }
}


// void initWiFi() {
//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, password);
  
//   if (!WiFi.config(local_IP, gateway, subnet, primaryDNS, secondaryDNS)) {
//     Serial.println("STA Failed to configure");
//   }
  
//   Serial.print("Connecting to WiFi ..");
  
//   if (WiFi.status() != WL_CONNECTED) {
//     Serial.print('.');
//     Serial.println("Connecting..");
//     digitalWrite(indikator, LOW);
//     delay(1000);
//     digitalWrite(indikator, HIGH);
//     delay(1000);
//   }

//   if (WiFi.status() == WL_CONNECTED)
//    {
//     Serial.println("Connected!!!");
//     digitalWrite(indikator, HIGH);
//     delay(1000);
//    }
//   Serial.println(WiFi.localIP());
// }