#include <SoftwareSerial.h>
#include <TinyGPS++.h>
// Definir los pines de TX y RX
static const int tx_d5 = 14, rx_d6 = 12;
// Crear una instancia de TinyGPSPlus
TinyGPSPlus gps;
SoftwareSerial ss(tx_d5, rx_d6); // Conexión serial por software

void setup(){
  // Iniciar el puerto serial para comunicación con la PC
  Serial.begin(9600);
  ss.begin(9600);
}

void loop(){

  while (ss.available() > 0) { // Comprobar si hay datos disponibles desde el GPS
    // Obtener los datos byte a byte del GPS
    byte gpsData = ss.read();
    gps.encode(gpsData);

    if (gps.location.isUpdated()) {
      // Latitud
      double lat = gps.location.lat();
      // Longitud
      double lng = gps.location.lng();
      // Mostrar la información en el monitor serie
      Serial.print("Latitud: ");
      Serial.print(lat, 6);  // Mostrar 6 decimales
      Serial.print(" , Longitud: ");
      Serial.print(lng, 6);
    }
  }
}