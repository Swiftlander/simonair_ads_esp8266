
#include <DallasTemperature.h> // Library Sensor Suhu
#include <OneWire.h> // Library Sensor Suhu

<<<<<<< HEAD
byte pin_temperature = 25;   // GPIO pin where the DS18B20 is connected to  //25
=======
int pin_temperature = 4;   // GPIO pin where the DS18B20 is connected to  //25
>>>>>>> 39b9bb9ab55ebde30e73af6b838a8042048a64d9

// ==========
// SUHU
// ==========
OneWire oneWire(pin_temperature); // Setup a oneWire instance to communicate with any OneWire devices
DallasTemperature temperatureSensor(&oneWire);
int value_temperature = 0;


void temperatureSensorFunction(){
   temperatureSensor.setResolution(10);
   temperatureSensor.requestTemperatures();
   value_temperature = temperatureSensor.getTempCByIndex(0);

}

void temperaturePrintToSerialMonitor(){
  Serial.println("============== SUHU ==============");
  Serial.print("Suhu: ");
  Serial.println(value_temperature);
  Serial.println();
}

