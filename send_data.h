#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

// Akuarium 8 = dO7NeYGaBo52
// Akuarium 9 = xpnyHMCHUfzb
// Akuarium 10 = U9HfLIhLQJGQ

String nama_alat = "Akuarium 10";
String id_alat = "U9HfLIhLQJGQ";

String serverName = "http://103.117.57.130/";

byte server[] = {103, 117, 57, 130};
WiFiClient client;
const int httpPort = 80;
String url;
unsigned long timeout;

void sendData(){
  
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

    float suhu = value_temperature;
    float ph = value_ph;
    float amonia = value_mq_ppm;
    float tss = value_tss;
    float tds = value_tds;
    float salinitas = value_salinity;
    // Serial.println(suhu);
    // Serial.println(ph);
    // Serial.println(amonia);
    // Serial.println(tss);
    // Serial.println(tds);
    // Serial.println(salinitas);
 String url = "http://103.117.57.130/api/monitoring/" +
               String(id_alat) + "/" +
               nama_alat + "/" +
               String(ph) + "/" +
               String(suhu) + "/" +
               String(amonia) + "/" +
               String(tss) + "/" +
               String(tds) + "/" +
               String(salinitas);

  // Mengirim HTTP GET request ke server
  HTTPClient http;
  http.begin(url);

  int httpResponseCode = http.GET();
  if (httpResponseCode == HTTP_CODE_OK) {
    String response = http.getString();
    Serial.println("Data berhasil dikirim");
    Serial.println("Response: " + response);
  } else {
    Serial.print("HTTP Error code: ");
    Serial.println(httpResponseCode);
  }

  http.end();

}
